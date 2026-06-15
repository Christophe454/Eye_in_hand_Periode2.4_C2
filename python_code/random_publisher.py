import random
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32


class RandomPublisher(Node):
    def __init__(self):
        super().__init__('random_publisher')

        self.publisher_ = self.create_publisher(Int32, 'random_number', 10)
        self.timer = self.create_timer(1.0, self.publish_random_number)

    def publish_random_number(self):
        msg = Int32()
        msg.data = random.randint(0, 100)

        self.publisher_.publish(msg)
        print(f"Verstuurd: {msg.data}")


def main(args=None):
    rclpy.init(args=args)

    node = RandomPublisher()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()