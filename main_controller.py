import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from my_ur_actions.action import RobotMovement

from rclpy.action import ActionClient

class MainNode(rclpy.node.Node):
    def __init__(self):
        super().__init__('main_node')

        self.Main_Node_action_client = ActionClient(self,RobotMovement,"manipulator_controller")

    def send_goal(self, target_state):

        goal_msg = RobotMovement.Goal()

        goal_msg.mode = "state"


        goal_msg.target_state = target_state

        goal_msg.target_x = 0.0
        goal_msg.target_y = 0.0
        goal_msg.target_z = 0.0

        goal_msg.use_camera_target = False

        goal_msg.speed = 0.3

        self.Main_Node_action_client.wait_for_server()

        self.get_logger().info(
            f'Sending goal: {target_state}'
        )


        self._send_goal_future = self.Main_Node_action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )

        self._send_goal_future.add_done_callback(
            self.goal_response_callback
        )

    def send_camera_goal(self, x, y, z):

        goal_msg = RobotMovement.Goal()

        goal_msg.mode = "camera"

        goal_msg.target_state = ""

        goal_msg.target_x = x
        goal_msg.target_y = y
        goal_msg.target_z = z

        goal_msg.use_camera_target = True
        goal_msg.speed = 0.2
        
        self.Main_Node_action_client.wait_for_server()

        self._send_goal_future = self.Main_Node_action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )

        self._send_goal_future.add_done_callback(
            self.goal_response_callback
        )

    def goal_response_callback(self, future):

        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return

        self.get_logger().info('Goal accepted')

        self._get_result_future = goal_handle.get_result_async()

        self._get_result_future.add_done_callback(
            self.get_result_callback
        )

    def feedback_callback(self, feedback_msg):

        feedback = feedback_msg.feedback

        self.get_logger().info(
            f'Feedback: {feedback.current_state}'
        )

    def get_result_callback(self, future):

        result = future.result().result

        self.get_logger().info(
            f'Result: {result.success}, {result.message}'
        )


    def main(args=None):

        rclpy.init(args=args)

        node = MainNode()
        node.send_goal("home")

        rclpy.spin(node)

        rclpy.shutdown()


    if __name__ == '__main__':
        main()
    