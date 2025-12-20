#!/usr/bin/env python3
"""
UR Robot TeachBot Follower Node (Commander Interface)

This node subscribes to joint states from a teachbot device and commands
the UR robot to follow those positions using MoveIt's MoveGroupCommander.
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
import threading


class URTeachBotFollowerCommander(Node):
    """Node that follows teachbot joint commands using trajectory messages."""
    
    def __init__(self):
        super().__init__('ur_teachbot_follower')
        
        # Declare parameters
        self.declare_parameter('teachbot_topic', '/teachbot/joint_states')
        self.declare_parameter('controller_name', 'scaled_joint_trajectory_controller')
        self.declare_parameter('update_rate', 0.5)  # seconds between updates
        self.declare_parameter('position_tolerance', 0.01)  # radians
        self.declare_parameter('trajectory_duration', 0.5)  # seconds
        
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
        
        # Create QoS profile matching the controller (BEST_EFFORT)
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Create QoS profile for subscribing to teachbot (RELIABLE)
        qos_subscriber = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Create publisher for joint trajectory
        self.trajectory_pub = self.create_publisher(
            JointTrajectory,
            f'/{controller_name}/joint_trajectory',
            qos_profile
        )
        
        # Subscribe to teachbot joint states
        self.subscription = self.create_subscription(
            JointState,
            teachbot_topic,
            self.joint_state_callback,
            qos_subscriber
        )
        
        # Create a timer to periodically send commands
        self.timer = self.create_timer(self.update_rate, self.update_robot_position)
        
        self.get_logger().info(f'Subscribed to {teachbot_topic}')
        self.get_logger().info(f'Publishing to /{controller_name}/joint_trajectory')
        self.get_logger().info(f'Update rate: {self.update_rate} seconds')
        self.get_logger().info('Ready to follow teachbot commands')
    
    def joint_state_callback(self, msg):
        """Store the latest joint state message."""
        with self.lock:
            self.latest_joint_states = msg
        self.get_logger().info(f'Received joint states: {[f"{p:.3f}" for p in msg.position]}', throttle_duration_sec=2.0)
    
    def update_robot_position(self):
        """Periodically update the robot position based on teachbot input."""
        with self.lock:
            if self.latest_joint_states is None:
                self.get_logger().info('No joint states received yet', throttle_duration_sec=5.0)
                return
            
            joint_states = self.latest_joint_states
        
        try:
            # Check if we need to update (positions changed significantly)
            if self.should_update_position(joint_states):
                self.send_trajectory_command(joint_states)
            else:
                self.get_logger().debug('Position change below tolerance')
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
    
    def send_trajectory_command(self, joint_states):
        """Send a trajectory command to move the robot."""
        # Create trajectory message
        trajectory = JointTrajectory()
        trajectory.header.stamp = self.get_clock().now().to_msg()
        trajectory.joint_names = list(joint_states.name)
        
        # Create trajectory point
        point = JointTrajectoryPoint()
        point.positions = list(joint_states.position)
        point.time_from_start = Duration(
            sec=int(self.trajectory_duration),
            nanosec=int((self.trajectory_duration % 1) * 1e9)
        )
        
        trajectory.points = [point]
        
        # Publish trajectory
        self.trajectory_pub.publish(trajectory)
        
        self.get_logger().info(
            f'Sent trajectory: {[f"{p:.3f}" for p in joint_states.position]}'
        )
        
        # Update last commanded positions
        self.last_commanded_positions = list(joint_states.position)


def main(args=None):
    rclpy.init(args=args)
    
    try:
        node = URTeachBotFollowerCommander()
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
