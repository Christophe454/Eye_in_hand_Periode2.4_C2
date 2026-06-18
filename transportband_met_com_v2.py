#!/usr/bin/env python3
"""Control conveyor based on ROS2 sensor value."""

import sys
import termios
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, Int32


class Conveyor:
    """Object-oriented wrapper for M310/M311 conveyor serial commands."""

    def __init__(self, port: str) -> None:
        self.serial_file = open(port, "r+b", buffering=0)
        Conveyor.configure_serial_port(self.serial_file.fileno())
        self.response_timeout = 1.0

    @staticmethod
    def configure_serial_port(fd: int) -> None:
        """Configure file descriptor as 115200, 8 data bits, no parity, 1 stop bit."""
        attrs = termios.tcgetattr(fd)

        attrs[0] = termios.IGNPAR
        attrs[1] = 0

        attrs[2] = (
            termios.CLOCAL
            | termios.CREAD
            | termios.CS8
            | termios.B115200
        )
        attrs[2] &= ~termios.PARENB
        attrs[2] &= ~termios.CSTOPB

        attrs[3] = 0

        attrs[4] = termios.B115200
        attrs[5] = termios.B115200

        attrs[6][termios.VMIN] = 0
        attrs[6][termios.VTIME] = 1

        termios.tcsetattr(fd, termios.TCSANOW, attrs)

    def send_line(self, command: str) -> None:
        self.serial_file.write((command + "\r\n").encode("ascii"))
        self.serial_file.flush()

    def read_response(self) -> str:
        deadline = time.monotonic() + self.response_timeout
        chunks = []

        while time.monotonic() < deadline:
            data = self.serial_file.read(256)
            if data:
                chunks.append(data)
                deadline = time.monotonic() + 0.1

        if not chunks:
            return ""

        raw = b"".join(chunks)
        return raw.decode("ascii", errors="replace").strip()

    def send_command_with_response(self, command: str) -> None:
        self.send_line(command)
        print(f"Sent: {command}")
        response = self.read_response()
        print(f"Response: {response if response else '<no response>'}")

    def init(self) -> None:
        self.send_command_with_response("M310 1")

    def set_speed(self, speed: int) -> None:
        if not 0 <= speed <= 255:
            raise ValueError(f"Speed out of range: {speed}. Expected 0..255")
        self.send_command_with_response(f"M311 {speed}")

    def close(self) -> None:
        self.serial_file.close()


class Sensornode(Node):
    def __init__(self, node_name: str, topic_name: str):
        super().__init__(node_name)

        self.sensor_value = False

        self.subscription = self.create_subscription(
            Bool,
            topic_name,
            self.sensor_callback,
            10,
        )

    def sensor_callback(self, msg: Bool) -> None:
        self.sensor_value = msg.data

        if self.sensor_value:
            self.get_logger().info("Sensor is TRUE")
        else:
            self.get_logger().info("Sensor is FALSE")


class CounterNode(Node):
    def __init__(self):
        super().__init__("counter_node")

        self.counter_value = 0

        self.subscription = self.create_subscription(
            Bool,
            "/sensor_begin/object_detected",
            self.sensor_begin_callback,
            10,
        )

        self.subscription = self.create_subscription(
            Bool,
            "/sensor_einde/object_detected",
            self.sensor_einde_callback,
            10
        )

        self.counter_publisher = self.create_publisher(
            Int32,
            "/counter_value",
            10,
            )

        self.get_logger().info("Sensor counter node gestart")
    
    def sensor_begin_callback(self, msg: Bool) -> None:
        if msg.data:
            self.counter_value += 1
            self.publish_counter()
            self.get_logger().info(f"Sensor begin TRUE, counter: {self.counter_value}")
    
    def sensor_einde_callback(self, msg: Bool) -> None:
        if msg.data:
            self.counter_value -= 1
            self.publish_counter()
            self.get_logger().info(f"Sensor einde TRUE, counter: {self.counter_value}")

    def publish_counter(self) -> None:
        msg = Int32()
        msg.data = self.counter_value
        self.counter_publisher.publish(msg)


class Startstopnode(Node):
    def __init__(self):
        super().__init__("startstop_node")

        self.start_stop_value = False

        self.previous_start_value = False
        self.previous_stop_value = False

        self.start_subscriptions = self.create_subscription(
            Bool,
            "/start",
            self.start_callback,
            10
        )

        self.stop_subscriptions = self.create_subscription(
            Bool,
            "/stop",
            self.stop_callback,
            10
        )

    def start_callback(self, msg: Bool) -> None:
        if msg.data and not self.previous_start_value:
            self.start_stop_value = True
            self.get_logger().info("Start ontvangen: transportband AAN")

        self.previous_start_value = msg.data

    def stop_callback(self, msg: Bool) -> None:
        if msg.data and not self.previous_stop_value:
            self.start_stop_value = False
            self.get_logger().info("Stop ontvangen: transportband UIT")

        self.previous_stop_value = msg.data
    
    


# pas het main programma aan als volgt: vervang alles wat sensor begin is naar de counter en laat de rest staan
def main() -> int:
    port = "/dev/ttyUSB0"

    stop_speed = 0
    run_speed = 100

    vertraging_stoppen = 5 #wacht 5 seconden of er nog een object komt voordat je de band stopt
    alles_uit = None #variabele om bij te houden of de band al gestopt is na het detecteren van een object bij de eindsensor

    rclpy.init()

    counter = CounterNode()
    sensor_begin_node = Sensornode("sensor_begin", "/sensor_begin/object_detected")
    sensor_einde_node = Sensornode("sensor_einde", "/sensor_einde/object_detected")
    start_stop_node = Startstopnode()
    conveyor = None

    try:
        conveyor = Conveyor(port)

        conveyor.init()
        conveyor.set_speed(stop_speed)

        previous_counter_value = None
        previous_einde_value = None
        previous_speed = stop_speed

        band_actief = False

        print("Programma gestart. Wachten op sensorwaarde...")

        while rclpy.ok():
            rclpy.spin_once(counter, timeout_sec=0.1)
            rclpy.spin_once(sensor_begin_node, timeout_sec=0.1)
            rclpy.spin_once(sensor_einde_node, timeout_sec=0.1)
            rclpy.spin_once(start_stop_node, timeout_sec=0.1)

            current_counter_value = counter.counter_value
            current_begin_value = sensor_begin_node.sensor_value
            current_einde_value = sensor_einde_node.sensor_value

            current_start_value = start_stop_node.start_stop_value

            if not current_start_value:
                gewenste_snelheid = stop_speed
                band_actief = False
                alles_uit = None

                if previous_speed != gewenste_snelheid:
                    print("Geen startsignaal: programma in stand-by, transportband UIT")
                    conveyor.set_speed(gewenste_snelheid)
                    previous_speed = gewenste_snelheid

                continue

            # Als counter 0 is en beide sensoren FALSE zijn, start een timer
            alles_false = (
                current_counter_value == 0
                and not current_begin_value
                and not current_einde_value
            )

            if alles_false:
                if alles_uit is None:
                    alles_uit= time.monotonic()

                tijd_false = time.monotonic() - alles_uit

                if tijd_false >= vertraging_stoppen:
                    band_actief = False
                    print("Band wordt gestopt. er wordt niks gedetecteerd")
            else:
                alles_uit = None

            # Als er objecten tussen begin en einde zitten, band actief houden
            if current_counter_value > 0:
                band_actief = True

            # Eindsensor heeft voorrang: TRUE betekent stoppen
            if current_einde_value:
                gewenste_snelheid = stop_speed

            # Als de timer band_actief False heeft gemaakt, band uit
            elif not band_actief:
                gewenste_snelheid = stop_speed

            # Anders draait de band
            else:
                gewenste_snelheid = run_speed

            # Alleen reageren als er iets verandert
            if (
                current_counter_value != previous_counter_value
                or current_einde_value != previous_einde_value
                or gewenste_snelheid != previous_speed
            ):
                if current_einde_value:
                    print("Sensor einde TRUE: transportband UIT")
                elif gewenste_snelheid == run_speed:
                    print("Counter is positief / sensor einde FALSE: transportband AAN")
                else:
                    print("Transportband UIT")

                conveyor.set_speed(gewenste_snelheid)

                previous_counter_value = current_counter_value
                previous_einde_value = current_einde_value
                previous_speed = gewenste_snelheid

        return 0

    except KeyboardInterrupt:
        print("Programma gestopt door gebruiker.")
        return 0

    except FileNotFoundError:
        print(f"Serial port not found: {port}", file=sys.stderr)
        return 1

    except PermissionError:
        print(
            f"Permission denied opening {port}. "
            "Try adding your user to dialout or run with proper permissions.",
            file=sys.stderr,
        )
        return 1

    except OSError as exc:
        print(f"Serial communication error on {port}: {exc}", file=sys.stderr)
        return 1

    finally:
        if conveyor is not None:
            try:
                conveyor.set_speed(stop_speed)
                conveyor.close()
            except Exception:
                pass

        counter.destroy_node()
        sensor_begin_node.destroy_node()
        sensor_einde_node.destroy_node()
        start_stop_node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    raise SystemExit(main())