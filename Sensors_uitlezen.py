import rclpy
from rclpy.node import Node
from ur_msgs.msg import IOStates
from std_msgs.msg import Bool


class URSensorReader(Node):
    def __init__(self):
        super().__init__('ur_sensor_reader')

        self.sub = self.create_subscription(
            IOStates,
            '/io_and_status_controller/io_states',
            self.io_callback,
            10
        )

        self.sensor_1_pub = self.create_publisher(Bool, '/sensor_1_detected', 10)
        self.sensor_2_pub = self.create_publisher(Bool, '/sensor_2_detected', 10)

        self.last_s1 = None
        self.last_s2 = None

    def io_callback(self, msg):
        sensor_1 = False
        sensor_2 = False

        for digital_input in msg.digital_in_states:
            if digital_input.pin == 0:
                sensor_1 = digital_input.state
            elif digital_input.pin == 1:
                sensor_2 = digital_input.state

        self.sensor_1_pub.publish(Bool(data=sensor_1))
        self.sensor_2_pub.publish(Bool(data=sensor_2))

        if sensor_1 != self.last_s1 or sensor_2 != self.last_s2:
            self.get_logger().info(
                f'Sensor 1 DI0: {sensor_1} | Sensor 2 DI1: {sensor_2}'
            )
            self.last_s1 = sensor_1
            self.last_s2 = sensor_2


def main(args=None):
    rclpy.init(args=args)
    node = URSensorReader()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()