import time

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import String, Bool, Int32
from std_srvs.srv import Trigger

from hmi_interfaces.action import Reset


class SystemManager(Node):
    def __init__(self):
        super().__init__('system_manager')

        self.callback_group = ReentrantCallbackGroup()

        # -------------------------
        # Interne systeemstatus
        # -------------------------
        self.system_state = "standby"
        self.reset_active = False
        self.stop_requested = False

        # -------------------------
        # Signalen van testprogramma's
        # -------------------------
        self.belt_count = 0
        self.conveyor_empty_done = False
        self.robot_home_done = False
        self.robot_calibration_done = False

        # -------------------------
        # Publishers naar HMI
        # -------------------------
        self.status_publisher = self.create_publisher(String, 'status', 10)
        self.feedback_publisher = self.create_publisher(String, 'hmi_feedback', 10)

        # -------------------------
        # Services vanaf HMI
        # -------------------------
        self.startknop_server = self.create_service(
            Trigger,
            'startknop',
            self.startknop_callback,
            callback_group=self.callback_group
        )

        self.stopknop_server = self.create_service(
            Trigger,
            'stopknop',
            self.stopknop_callback,
            callback_group=self.callback_group
        )

        # -------------------------
        # Reset action vanaf HMI
        # -------------------------
        self.reset_action_server = ActionServer(
            self,
            Reset,
            'reset_action',
            self.execute_reset_callback,
            callback_group=self.callback_group
        )

        # -------------------------
        # Subscribers vanaf testprogramma's
        # -------------------------
        self.belt_count_subscriber = self.create_subscription(
            Int32,
            'belt_count',
            self.belt_count_callback,
            10,
            callback_group=self.callback_group
        )

        self.conveyor_empty_subscriber = self.create_subscription(
            Bool,
            'conveyor_empty_done',
            self.conveyor_empty_callback,
            10,
            callback_group=self.callback_group
        )

        self.robot_home_subscriber = self.create_subscription(
            Bool,
            'robot_home_done',
            self.robot_home_callback,
            10,
            callback_group=self.callback_group
        )

        self.robot_calibration_subscriber = self.create_subscription(
            Bool,
            'robot_calibration_done',
            self.robot_calibration_callback,
            10,
            callback_group=self.callback_group
        )

        self.publish_status("standby")
        self.publish_feedback("System manager gestart")

        self.get_logger().info("System manager gestart")

    # ============================================================
    # Publishers
    # ============================================================

    def publish_status(self, status):
        self.system_state = status

        msg = String()
        msg.data = status
        self.status_publisher.publish(msg)

        self.get_logger().info(f"Status: {status}")

    def publish_feedback(self, feedback):
        msg = String()
        msg.data = feedback
        self.feedback_publisher.publish(msg)

        self.get_logger().info(f"Feedback: {feedback}")

    def publish_reset_feedback(self, goal_handle, text):
        feedback_msg = Reset.Feedback()
        feedback_msg.current_step = text

        goal_handle.publish_feedback(feedback_msg)
        self.publish_feedback(text)

    # ============================================================
    # HMI services
    # ============================================================

    def startknop_callback(self, request, response):
        if self.system_state in "resetting"
            response.success = False
            response.message = "Kan niet starten: reset is bezig"
            self.publish_feedback(response.message)
            return response

        if self.system_state in "stopping":
            response.success = False
            response.message = "kan niet starten: systeem wordt gestopt"
            self.publish_feedback(respons.message)
            return response


        if self.reset_active:
            response.success = False
            response.message = "Kan niet starten: reset is bezig"
            self.publish_feedback(response.message)
            return response


        if self.system_state == "running":
            response.success = False
            response.message = "Systeem draait al"
            self.publish_feedback(response.message)
            return response

        self.stop_requested = False

        self.publish_status("running")
        self.publish_feedback("Startsignaal ontvangen, systeem gestart")

        response.success = True
        response.message = "Startsignaal succesvol verwerkt"
        return response

    def stopknop_callback(self, request, response):
        if self.system_state not in ["running", "resetting", "calibrating"]:
            response.success = False
            response.message = "Systeem draait niet, stop niet nodig"
            self.publish_feedback(response.message)
            return response

        self.stop_requested = True

        self.publish_status("stopping")
        self.publish_feedback("Stopsignaal ontvangen, systeem stopt na huidige actie")

        response.success = True
        response.message = "Stopverzoek geaccepteerd"
        return response

    # ============================================================
    # Callbacks van testprogramma's
    # ============================================================

    def belt_count_callback(self, msg):
        self.belt_count = msg.data
        self.get_logger().info(f"Belt count ontvangen: {self.belt_count}")

    def conveyor_empty_callback(self, msg):
        self.conveyor_empty_done = msg.data
        self.get_logger().info(f"Conveyor empty done ontvangen: {self.conveyor_empty_done}")

    def robot_home_callback(self, msg):
        self.robot_home_done = msg.data
        self.get_logger().info(f"Robot home done ontvangen: {self.robot_home_done}")

    def robot_calibration_callback(self, msg):
        self.robot_calibration_done = msg.data
        self.get_logger().info(
            f"Robot calibration done ontvangen: {self.robot_calibration_done}"
        )

    # ============================================================
    # Wachtfunctie voor reset
    # ============================================================

    def wait_until(self, goal_handle, condition_function, waiting_text):
        last_feedback_time = 0.0

        while rclpy.ok():
            if goal_handle.is_cancel_requested:
                self.publish_feedback("Reset geannuleerd")
                goal_handle.canceled()
                return False

            if self.stop_requested:
                self.publish_feedback("Reset gestopt door stopverzoek")
                return False

            if condition_function():
                return True

            current_time = time.time()

            if current_time - last_feedback_time >= 1.0:
                self.publish_reset_feedback(goal_handle, waiting_text)
                last_feedback_time = current_time

            time.sleep(0.1)

        return False

    # ============================================================
    # Reset action
    # ============================================================

    def execute_reset_callback(self, goal_handle):
        if self.reset_active:
            result = Reset.Result()
            result.success = False
            result.message = "Reset is al bezig"

            goal_handle.abort()
            return result

        self.reset_active = True
        self.stop_requested = False

        # Reset signalen terug naar beginstand
        self.conveyor_empty_done = False
        self.robot_home_done = False
        self.robot_calibration_done = False

        self.publish_status("resetting")
        self.publish_feedback("Reset actie gestart")

        try:
            # ----------------------------------------------------
            # Stap 1: wachten tot transportband leeg is EN robot home is
            # ----------------------------------------------------
            self.publish_reset_feedback(
                goal_handle,
                "Wachten op transportband leeg en robot home..."
            )

            first_part_done = self.wait_until(
                goal_handle,
                lambda: self.conveyor_empty_done and self.robot_home_done,
                "Nog bezig: transportband leegmaken en robot homen..."
            )

            if not first_part_done:
                result = Reset.Result()
                result.success = False
                result.message = "Reset afgebroken tijdens transportband/robot home"

                self.publish_status("standby")
                goal_handle.abort()
                return result

            self.publish_reset_feedback(
                goal_handle,
                "Transportband leeg en robot home ontvangen"
            )

            # ----------------------------------------------------
            # Stap 2: wachten tot robot/camera kalibratie klaar is
            # ----------------------------------------------------
            self.publish_status("calibrating")

            self.publish_reset_feedback(
                goal_handle,
                "Wachten op kalibratie klaar..."
            )

            calibration_done = self.wait_until(
                goal_handle,
                lambda: self.robot_calibration_done,
                "Nog bezig: kalibratie..."
            )

            if not calibration_done:
                result = Reset.Result()
                result.success = False
                result.message = "Reset afgebroken tijdens kalibratie"

                self.publish_status("standby")
                goal_handle.abort()
                return result

            self.publish_reset_feedback(
                goal_handle,
                "Kalibratie klaar ontvangen"
            )

            # ----------------------------------------------------
            # Stap 3: reset compleet
            # ----------------------------------------------------
            self.publish_reset_feedback(
                goal_handle,
                "Reset compleet, systeem klaar voor gebruik"
            )

            self.publish_status("standby")

            result = Reset.Result()
            result.success = True
            result.message = "Reset complete"

            goal_handle.succeed()
            return result

        except Exception as e:
            self.publish_status("standby")
            self.publish_feedback(f"Reset mislukt: {e}")

            result = Reset.Result()
            result.success = False
            result.message = f"Reset mislukt: {e}"

            goal_handle.abort()
            return result

        finally:
            self.reset_active = False


def main(args=None):
    rclpy.init(args=args)

    system_manager = SystemManager()

    executor = MultiThreadedExecutor()
    executor.add_node(system_manager)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass

    system_manager.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()