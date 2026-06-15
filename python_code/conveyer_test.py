import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Bool


class ConveyorTest(Node):
    def __init__(self):
        super().__init__('conveyor_test')

        self.belt_count_publisher = self.create_publisher(Int32, 'belt_count', 10)
        self.empty_done_publisher = self.create_publisher(Bool, 'conveyor_empty_done', 10)

        self.belt_count = 0

        self.get_logger().info("Conveyor test gestart")
        self.print_menu()

    def print_menu(self):
        print("")
        print("=== CONVEYOR TEST ===")
        print("count <getal>  -> aantal objecten op band sturen")
        print("empty          -> transportband leeg klaar sturen")
        print("notempty       -> transportband leeg-signaal op false zetten")
        print("q              -> stoppen")
        print("")

    def publish_belt_count(self):
        msg = Int32()
        msg.data = self.belt_count

        self.belt_count_publisher.publish(msg)

        self.get_logger().info(f"belt_count verstuurd: {self.belt_count}")

    def publish_empty_done(self, value):
        msg = Bool()
        msg.data = value

        self.empty_done_publisher.publish(msg)

        self.get_logger().info(f"conveyor_empty_done verstuurd: {value}")

    def run_terminal(self):
        while rclpy.ok():
            user_input = input("conveyor> ").strip().lower()

            if user_input == "q":
                break

            elif user_input.startswith("count"):
                parts = user_input.split()

                if len(parts) != 2:
                    print("Gebruik: count <getal>")
                    continue

                try:
                    self.belt_count = int(parts[1])
                    self.publish_belt_count()
                except ValueError:
                    print("Ongeldig getal")

            elif user_input == "empty":
                self.belt_count = 0
                self.publish_belt_count()
                self.publish_empty_done(True)

            elif user_input == "notempty":
                self.publish_empty_done(False)

            else:
                print("Onbekend commando")
                self.print_menu()


def main(args=None):
    rclpy.init(args=args)

    node = ConveyorTest()

    try:
        node.run_terminal()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()