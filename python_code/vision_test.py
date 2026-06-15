import random

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32


class VisionTest(Node):
    def __init__(self):
        super().__init__('vision_test')

        self.object_a_publisher = self.create_publisher(Int32, 'object_a_count', 10)
        self.object_b_publisher = self.create_publisher(Int32, 'object_b_count', 10)
        self.object_c_publisher = self.create_publisher(Int32, 'object_c_count', 10)
        self.object_d_publisher = self.create_publisher(Int32, 'object_d_count', 10)

        self.random_publisher = self.create_publisher(Int32, 'random_number', 10)

        self.object_a_count = 0
        self.object_b_count = 0
        self.object_c_count = 0
        self.object_d_count = 0

        self.get_logger().info("Vision test gestart")
        self.publish_all_counts()
        self.print_menu()

    def print_menu(self):
        print("")
        print("=== VISION TEST ===")
        print("a              -> object A +1")
        print("b              -> object B +1")
        print("c              -> object C +1")
        print("d              -> object D +1")
        print("set a <getal>  -> object A count zetten")
        print("set b <getal>  -> object B count zetten")
        print("set c <getal>  -> object C count zetten")
        print("set d <getal>  -> object D count zetten")
        print("camera <getal> -> cameravlak getal sturen")
        print("rand           -> random cameravlak getal sturen")
        print("reset          -> alle tellers naar 0")
        print("q              -> stoppen")
        print("")

    def publish_count(self, publisher, value, name):
        msg = Int32()
        msg.data = value

        publisher.publish(msg)

        self.get_logger().info(f"{name} verstuurd: {value}")

    def publish_all_counts(self):
        self.publish_count(self.object_a_publisher, self.object_a_count, "object_a_count")
        self.publish_count(self.object_b_publisher, self.object_b_count, "object_b_count")
        self.publish_count(self.object_c_publisher, self.object_c_count, "object_c_count")
        self.publish_count(self.object_d_publisher, self.object_d_count, "object_d_count")

    def publish_camera_number(self, value):
        msg = Int32()
        msg.data = value

        self.random_publisher.publish(msg)

        self.get_logger().info(f"random_number verstuurd: {value}")

    def run_terminal(self):
        while rclpy.ok():
            user_input = input("vision> ").strip().lower()

            if user_input == "q":
                break

            elif user_input == "a":
                self.object_a_count += 1
                self.publish_all_counts()

            elif user_input == "b":
                self.object_b_count += 1
                self.publish_all_counts()

            elif user_input == "c":
                self.object_c_count += 1
                self.publish_all_counts()

            elif user_input == "d":
                self.object_d_count += 1
                self.publish_all_counts()

            elif user_input == "reset":
                self.object_a_count = 0
                self.object_b_count = 0
                self.object_c_count = 0
                self.object_d_count = 0
                self.publish_all_counts()

            elif user_input == "rand":
                self.publish_camera_number(random.randint(0, 100))

            elif user_input.startswith("camera"):
                parts = user_input.split()

                if len(parts) != 2:
                    print("Gebruik: camera <getal>")
                    continue

                try:
                    value = int(parts[1])
                    self.publish_camera_number(value)
                except ValueError:
                    print("Ongeldig getal")

            elif user_input.startswith("set"):
                parts = user_input.split()

                if len(parts) != 3:
                    print("Gebruik: set a <getal>")
                    continue

                object_type = parts[1]

                try:
                    value = int(parts[2])
                except ValueError:
                    print("Ongeldig getal")
                    continue

                if value < 0:
                    print("Aantal mag niet negatief zijn")
                    continue

                if object_type == "a":
                    self.object_a_count = value
                elif object_type == "b":
                    self.object_b_count = value
                elif object_type == "c":
                    self.object_c_count = value
                elif object_type == "d":
                    self.object_d_count = value
                else:
                    print("Gebruik object type: a, b, c of d")
                    continue

                self.publish_all_counts()

            else:
                print("Onbekend commando")
                self.print_menu()


def main(args=None):
    rclpy.init(args=args)

    node = VisionTest()

    try:
        node.run_terminal()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()