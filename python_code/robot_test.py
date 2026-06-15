import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from geometry_msgs.msg import Vector3


class RobotTest(Node):
    def __init__(self):
        super().__init__('robot_test')

        self.home_done_publisher = self.create_publisher(Bool, 'robot_home_done', 10)
        self.calibration_done_publisher = self.create_publisher(Bool, 'robot_calibration_done', 10)
        self.xyz_publisher = self.create_publisher(Vector3, 'xyz_values', 10)

        self.get_logger().info("Robot test gestart")
        self.print_menu()

    def print_menu(self):
        print("")
        print("=== ROBOT TEST ===")
        print("home              -> robot home klaar sturen")
        print("nothome           -> robot home false sturen")
        print("calib             -> kalibratie klaar sturen")
        print("notcalib          -> kalibratie false sturen")
        print("xyz <x> <y> <z>   -> xyz waarden sturen")
        print("q                 -> stoppen")
        print("")

    def publish_home_done(self, value):
        msg = Bool()
        msg.data = value

        self.home_done_publisher.publish(msg)

        self.get_logger().info(f"robot_home_done verstuurd: {value}")

    def publish_calibration_done(self, value):
        msg = Bool()
        msg.data = value

        self.calibration_done_publisher.publish(msg)

        self.get_logger().info(f"robot_calibration_done verstuurd: {value}")

    def publish_xyz(self, x, y, z):
        msg = Vector3()
        msg.x = x
        msg.y = y
        msg.z = z

        self.xyz_publisher.publish(msg)

        self.get_logger().info(f"xyz_values verstuurd: x={x}, y={y}, z={z}")

    def run_terminal(self):
        while rclpy.ok():
            user_input = input("robot> ").strip().lower()

            if user_input == "q":
                break

            elif user_input == "home":
                self.publish_home_done(True)

            elif user_input == "nothome":
                self.publish_home_done(False)

            elif user_input == "calib":
                self.publish_calibration_done(True)

            elif user_input == "notcalib":
                self.publish_calibration_done(False)

            elif user_input.startswith("xyz"):
                parts = user_input.split()

                if len(parts) != 4:
                    print("Gebruik: xyz <x> <y> <z>")
                    continue

                try:
                    x = float(parts[1])
                    y = float(parts[2])
                    z = float(parts[3])

                    self.publish_xyz(x, y, z)

                except ValueError:
                    print("Ongeldige xyz waarde")

            else:
                print("Onbekend commando")
                self.print_menu()


def main(args=None):
    rclpy.init(args=args)

    node = RobotTest()

    try:
        node.run_terminal()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()