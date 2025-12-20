#!/usr/bin/env python3
"""
UR Robot TeachBot Follower Node (Action Client)

This node subscribes to joint states from a teachbot device and commands
the UR robot to follow those positions using action client for trajectory execution.
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from sensor_msgs.msg import JointState
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
import threading


class URTeachBotFollowerAction(Node):
    """Node that follows teachbot joint commands using action client."""
    
    def __init__(self):
        super().__init__('ur_teachbot_follower')
        
        # Declare parameters
        self.declare_parameter('teachbot_topic', '/teachbot/joint_states')
        self.declare_parameter('controller_name', 'scaled_joint_trajectory_controller')
        self.declare_parameter('update_rate', 0.5)  # seconds between updates
        self.declare_parameter('position_tolerance', 0.01)  # radians
        self.declare_parameter('trajectory_duration', 1.0)  # seconds - increased for action server
        
        # Get parameters
        teachbot_topic = self.get_parameter('teachbot_topic').value
        controller_name = self.get_parameter('controller_name').value
        self.update_rate = self.get_parameter('update_rate').value
        self.position_tolerance = self.get_parameter('position_tolerance').value
        self.trajectory_duration = self.get_parameter('trajectory_duration').value
        
        # Storage for latest joint states
        self.latest_joint_states = None
        self.last_commanded_positions = None
        self.lock = threading.Lock()
        self.is_executing = False
        
        # Create action client
        self._action_client = ActionClient(
            self,
            FollowJointTrajectory,
            f'/{controller_name}/follow_joint_trajectory'
        )
        
        # Subscribe to teachbot joint states
        self.subscription = self.create_subscription(
            JointState,
            teachbot_topic,
            self.joint_state_callback,
            10
        )
        
        # Create a timer to periodically send commands
        self.timer = self.create_timer(self.update_rate, self.update_robot_position)
        
        self.get_logger().info(f'Subscribed to {teachbot_topic}')
        self.get_logger().info(f'Action client: /{controller_name}/follow_joint_trajectory')
        self.get_logger().info(f'Update rate: {self.update_rate} seconds')
        self.get_logger().info('Waiting for action server...')
        
        # Wait for action server
        self._action_client.wait_for_server()
        self.get_logger().info('Action server connected. Ready to follow teachbot commands')
    
    def joint_state_callback(self, msg):
        """Store the latest joint state message."""
        with self.lock:
            self.latest_joint_states = msg
    
    def update_robot_position(self):
        """Periodically update the robot position based on teachbot input."""
        # Don't send new commands while executing
        if self.is_executing:
            return
            
        with self.lock:
            if self.latest_joint_states is None:
                return
            
            joint_states = self.latest_joint_states
        
        try:
            # Check if we need to update (positions changed significantly)
            if self.should_update_position(joint_states):
                self.send_goal(joint_states)
        except Exception as e:
            self.get_logger().error(f'Error updating robot position: {str(e)}')
    
    def should_update_position(self, joint_states):
        """Check if the position has changed enough to warrant a new command."""
        if self.last_commanded_positions is None:
            return True
        
        # Check if any joint has moved beyond the tolerance
        for i, pos in enumerate(joint_states.position):
            if i < len(self.last_commanded_positions):
                if abs(pos - self.last_commanded_positions[i]) > self.position_tolerance:
                    return True
        
        return False
    
    def send_goal(self, joint_states):
        """Send a trajectory goal via action client."""
        self.is_executing = True
        
        # Create trajectory message
        trajectory = JointTrajectory()
        trajectory.joint_names = list(joint_states.name)
        
        # Create trajectory point with zero velocities (let controller calculate)
        point = JointTrajectoryPoint()
        point.positions = list(joint_states.position)
        point.velocities = [0.0] * len(joint_states.position)  # Zero velocities at end
        point.time_from_start = Duration(
            sec=int(self.trajectory_duration),
            nanosec=int((self.trajectory_duration % 1) * 1e9)
        )
        
        trajectory.points = [point]
        
        # Create goal with relaxed tolerances
        goal_msg = FollowJointTrajectory.Goal()
        goal_msg.trajectory = trajectory
        
        # Set goal tolerances (optional but helps avoid PATH_TOLERANCE_VIOLATED)
        # Leave empty to use controller defaults
        
        self.get_logger().info(
            f'Sending goal: {[f"{p:.3f}" for p in joint_states.position]}'
        )
        
        # Send goal
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)
        
        # Update last commanded positions
        self.last_commanded_positions = list(joint_states.position)
    
    def goal_response_callback(self, future):
        """Handle goal response."""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('Goal rejected')
            self.is_executing = False
            return
        
        self.get_logger().info('Goal accepted')
        
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self, future):
        """Handle result."""
        from control_msgs.action import FollowJointTrajectory as FJT
        result = future.result().result
        
        # Map error codes to messages
        error_messages = {
            FJT.Result.SUCCESSFUL: 'SUCCESSFUL',
            FJT.Result.INVALID_GOAL: 'INVALID_GOAL',
            FJT.Result.INVALID_JOINTS: 'INVALID_JOINTS',
            FJT.Result.OLD_HEADER_TIMESTAMP: 'OLD_HEADER_TIMESTAMP',
            FJT.Result.PATH_TOLERANCE_VIOLATED: 'PATH_TOLERANCE_VIOLATED',
            FJT.Result.GOAL_TOLERANCE_VIOLATED: 'GOAL_TOLERANCE_VIOLATED'
        }
        
        error_msg = error_messages.get(result.error_code, f'UNKNOWN({result.error_code})')
        
        if result.error_code == FJT.Result.SUCCESSFUL:
            self.get_logger().info(f'Result: {error_msg}')
        else:
            self.get_logger().warn(f'Result: {error_msg} (code: {result.error_code})')
        
        self.is_executing = False
    
    def feedback_callback(self, feedback_msg):
        """Handle feedback (optional)."""
        pass


def main(args=None):
    rclpy.init(args=args)
    
    try:
        node = URTeachBotFollowerAction()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f'Error: {e}')
    finally:
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
