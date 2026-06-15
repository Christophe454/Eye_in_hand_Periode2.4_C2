import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from std_msgs.msg import String
from std_srvs.srv import Trigger
from hmi_interfaces.action import Reset
import time

class HMIController(Node):
    def __init__(self):
        super().__init__('hmi_controller') # naam van de publisher

        self.system_state = "standby"
        self.reset_active = False
        self.stop_requested = False

        self.status_publisher = self.create_publisher(String, 'status', 10) #aanmaken van de publisher, topic naam en grootte van de queue
        self.feedback_publisher = self.create_publisher(String, 'hmi_feedback', 10) #aanmaken van de publisher, topic naam en grootte van de queue
        self.startknop_server = self.create_service(Trigger, 'startknop', self.startknop_callback)
        self.stopknop_server = self.create_service(Trigger, 'stopknop', self.stopknop_callback)
        self.reset_action_server = ActionServer(
            self,
            Reset,
            'reset_action',
            self.execute_callback
        )
        print("init draait")

    def publish_status(self, status):
        self.system_state = status

        msg = String()
        msg.data = status
        self.status_publisher.publish(msg)

        self.get_logger().info(f"Published status: {status}")

    def publish_feedback(self, feedback):
        print("callback_feedback draait")
        msg = String()
        msg.data = feedback
        self.feedback_publisher.publish(msg)
        self.get_logger().info(f"Published feedback: {feedback}")

    def startknop_callback(self, request, response):
        if self.reset_active:
            response.success = False
            response.message = "Kan niet starten: reset is bezig"
            return response

        if self.system_state == "running":
            response.success = False
            response.message = "Systeem draait al"
            return response

        self.stop_requested = False

        self.publish_status("running")
        self.publish_feedback("Startsignaal ontvangen, systeem gestart")

        response.success = True
        response.message = "Startsignaal succesvol verwerkt"
        return response
        
    def stopknop_callback(self, request, response):
        if self.system_state not in ["running", "resetting"]:
            response.success = False
            response.message = "Systeem draait niet, stop niet nodig"
            return response

        self.stop_requested = True

        self.publish_status("stopping")
        self.publish_feedback("Stopsignaal ontvangen, systeem stopt na huidige actie")

        response.success = True
        response.message = "Stopverzoek geaccepteerd"
        return response

    def publish_reset_feedback(self, goal_handle, text):
        feedback_msg = Reset.Feedback()
        feedback_msg.current_step = text

        goal_handle.publish_feedback(feedback_msg)
        self.publish_feedback(text)

    def execute_callback(self, goal_handle):
        if self.reset_active:
            result = Reset.Result()
            result.success = False
            result.message = "Reset is al bezig"

            goal_handle.abort()
            return result

        self.reset_active = True
        self.stop_requested = False

        self.publish_status("resetting")
        self.publish_feedback("Reset actie gestart, systeem wordt gereset")

        try:
            self.publish_reset_feedback(
                goal_handle,
                "Loopband leegdraaien en robot homen..."
                )
            time.sleep(3)

            self.publish_reset_feedback(
                goal_handle,
                "Camera kalibreren..."
            )
            time.sleep(2)

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

    controller = HMIController()

    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        pass

    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()