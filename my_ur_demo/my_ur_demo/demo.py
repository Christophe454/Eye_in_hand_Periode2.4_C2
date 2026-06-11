#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from threading import Thread
from my_ur_actions.action import RobotMovement
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle

from tf2_ros import Buffer, TransformListener, TransformException

from my_moveit_python import srdfGroupStates, MovegroupHelper
import tf_transformations


class manipulatorController(Node):
    def __init__(self):
        super().__init__("manipulator_controller_server")
        self.manipulator_controller_server_ = ActionServer(
            self,
            RobotMovement,
            "manipulator_controller", 
            execute_callback=self.execute_callback)
        self.get_logger().info("manipulator controller action server has been started.")

        # Robot parameters
        prefix = ""
        # arrange the joint_names alphabetically to match URDF
        self.joint_names = [
            prefix + "elbow_joint",
            prefix + "shoulder_lift_joint",
            prefix + "shoulder_pan_joint",
            prefix + "wrist_1_joint",
            prefix + "wrist_2_joint",
            prefix + "wrist_3_joint",
        ]

        self.base_link_name = "base_link"
        self.end_effector_name = "tool0"
        self.group_name = "arm"
        self.package_name = "my_ur_moveit_config"
        self.srdf_file_name = "config/my_ur.srdf"

        # TF setup
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # MoveIt helpers
        self.group_states = srdfGroupStates(
            self.package_name, self.srdf_file_name, self.group_name
        )
        self.move_group = MovegroupHelper(
            self, self.joint_names, self.base_link_name, self.end_effector_name, self.group_name
        )

        # --- Create subscribers, publishers, clients, timers here ---

        self.get_logger().info("UR demo node has been initialized.")

    # --- Create callback functions here ---
    def execute_callback(self, goal_handle: ServerGoalHandle):

    

            self.get_logger().info("Received a new goal request.")

            goal = goal_handle.request

            mode = goal.mode.strip().lower()
            target_state = goal.target_state.strip().lower()


            x = goal.target_x
            y = goal.target_y
            z = goal.target_z

            ok = False

            # ===== FEEDBACK OBJECT =====

            feedback_msg = RobotMovement.Feedback()

            feedback_msg.current_state = "Starting movement"
            feedback_msg.progress = 0.0

            goal_handle.publish_feedback(feedback_msg)

            # ===== STATE MOVEMENT =====

            if mode == "state":

                self.get_logger().info(
                    f"Moving to state: {target_state}"
                )

                ok =self.move_to_state(target_state)

            # ===== CAMERA MOVEMENT =====

            elif mode == "camera":

                self.get_logger().info(
                    f"Moving to camera pose: {x}, {y}, {z}"
                )

                translation = [x, y, z]

                rotation = [1.0, 0.0, 0.0, 0.0]

                ok =self.move_to_pose(translation, rotation)
            
            else:
                self.get_logger().error(f"Unknown mode: {mode}")
                goal_handle.abort()

                result = RobotMovement.Result()
                result.success = False
                result.message = f"Unknown mode: {mode}"
                result.final_x = 0.0
                result.final_y = 0.0
                result.final_z = 0.0
            
                return result

            # ===== FEEDBACK =====

            if not ok:
                feedback_msg.current_state = "Movement failed"
                feedback_msg.progress = 100.0
                goal_handle.publish_feedback(feedback_msg)

                goal_handle.abort()

                result = RobotMovement.Result()
                result.success = False
                result.message = "Movement failed"
                result.final_x = x
                result.final_y = y
                result.final_z = z
                return result

            feedback_msg.current_state = "Movement finished"
            feedback_msg.progress = 100.0

            goal_handle.publish_feedback(feedback_msg)

            # ===== RESULT =====

            goal_handle.succeed()

            result = RobotMovement.Result()

            result.success = True
            result.message = "Movement complete"

            result.final_x = x
            result.final_y = y
            result.final_z = z

            return result
    # --- Motion primitives ------------------------------------------------
    # def move_to_state(self, state_name: str):
    #     result, joint_values = self.group_states.get_joint_values(state_name)
    #     if not result:
    #         self.get_logger().error(f"Failed to get joint values for state '{state_name}'.")
    #         return
    #     self.get_logger().info(f"Moving to state '{state_name}'.")
    #     self.move_group.move_to_configuration(joint_values)

    def move_to_state(self, state_name: str):
        result, joint_values = self.group_states.get_joint_values(state_name)
        if not result:
            self.get_logger().error(f"Failed to get joint values for state '{state_name}'.")
            return False

        self.get_logger().info(f"Moving to state '{state_name}'.")
        move_result = self.move_group.move_to_configuration(joint_values)

        if isinstance(move_result, bool):
            return move_result

        return True

    # def move_to_pose(self, translation, rotation):
    #     self.get_logger().info(f"Moving to pose: {translation}, {rotation}")
    #     self.move_group.move_to_pose(translation, rotation)

    def move_to_pose(self, translation, rotation):
        self.get_logger().info(f"Moving to pose: {translation}, {rotation}")
        move_result = self.move_group.move_to_pose(translation, rotation)

        if isinstance(move_result, bool):
            return move_result

        return True

    def move_to_tf(self, from_frame: str, to_frame: str):
        try:
            t = self.tf_buffer.lookup_transform(
                to_frame, from_frame, rclpy.time.Time()
            )
            translation = [
                t.transform.translation.x,
                t.transform.translation.y,
                t.transform.translation.z,
            ]
            rotation = [
                t.transform.rotation.w,
                t.transform.rotation.x,
                t.transform.rotation.y,
                t.transform.rotation.z,
            ]
            self.get_logger().info(f"Moving to transform: {from_frame} → {to_frame}")
            return self.move_to_pose(translation, rotation)
        
        except TransformException as ex:
            self.get_logger().warn(f"Could not transform {to_frame} to {from_frame}: {ex}")
            return False

    # --- App sequence ----------------------------------------------------

    def execute_app(self):

        # Move through predefined joint states
        for state in ["left", "right", "home"]:
            self.move_to_state(state)

        translation = [0.7, 0.0, 0.4] # Relative to base_link    
        # RPY angles in radians
        roll = 3.1415927 # De gripper is facing downwards
        pitch = 0.0
        yaw = 0.0
        # Convert RPY to quaternion
        rotation = tf_transformations.quaternion_from_euler(roll, pitch, yaw)

        # Move to a specific pose
        self.move_to_pose(translation, rotation)

        # Move back to home position
        self.move_to_state("home")

        # Move to resting position
        self.move_to_state("resting")


# --------------------------------------------------------------------------
# Do not modify the main function unless necessary.
# --------------------------------------------------------------------------
def main(args=None):
    rclpy.init(args=args)

    # Instantiate the manipulatorController node.
    # NOTE: This must be done before creating the executor to ensure callbacks are registered correctly.
    node = manipulatorController()

    # Create a multithreaded executor with 2 threads.
    # Allows the node to handle multiple callbacks concurrently (e.g., subscriptions, timers).
    executor = MultiThreadedExecutor(num_threads=2)

    # Add the node to the executor so it can process its callbacks.
    executor.add_node(node)

    # Start the executor in a separate background thread.
    # Keeps the ROS event loop running while allowing the main thread to execute custom logic.
    # executor_thread = Thread(target=executor.spin, daemon=True)
    # executor_thread.start()

    # # Create a 1 Hz rate object and sleep once to allow initialization.
    # # Provides time for system setup (e.g., MoveIt, TF) before running main logic.
    # node.create_rate(1.0).sleep()

    # # Execute the main application logic defined in the node.
    # # Typically runs robot motion, computations, or control behaviors.
    # #node.execute_app() aangepast dus opletten om weer terug te zetten

    # # Shutdown ROS gracefully after main logic completes.
    # rclpy.shutdown()

    # # Wait for the executor thread to exit cleanly before terminating the program.
    # executor_thread.join()

    try:
        executor.spin()
    finally:
        rclpy.shutdown()



if __name__ == "__main__":
    main()