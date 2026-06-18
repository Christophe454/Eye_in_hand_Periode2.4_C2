import threading
import tkinter as tk

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from std_msgs.msg import Bool


from transportband_package.action import ResetNoodstop


class SensorHMISimulator(Node):
    def __init__(self):
        super().__init__('sensor_hmi_simulator')

        self.publisher_begin = self.create_publisher(
            Bool,
            '/sensor_begin/object_detected',
            10
        )

        self.publisher_einde = self.create_publisher(
            Bool,
            '/sensor_einde/object_detected',
            10
        )

        self.publisher_start = self.create_publisher(
            Bool,
            '/start',
            10
        )

        self.publisher_stop = self.create_publisher(
            Bool,
            '/stop',
            10
        )

        self.publisher_noodstop = self.create_publisher(
            Bool,
            '/noodstop',
            10
        )

        # Reset is een ActionClient
        self.reset_action_client = ActionClient(
            self,
            ResetNoodstop,
            'reset_noodstop'
        )

        self.sensor_begin_waarde = False
        self.sensor_einde_waarde = False
        self.start_waarde = False
        self.stop_waarde = False
        self.noodstop_waarde = True
        self.reset_waarde = False

        self.get_logger().info('Sensor HMI simulator gestart')

    # -------------------------
    # Topic publishers
    # -------------------------

    def publish_begin_sensor(self, waarde: bool):
        msg = Bool()
        msg.data = waarde
        self.sensor_begin_waarde = waarde

        self.publisher_begin.publish(msg)
        self.get_logger().info(f'Begin sensor gestuurd: {waarde}')

    def publish_einde_sensor(self, waarde: bool):
        msg = Bool()
        msg.data = waarde
        self.sensor_einde_waarde = waarde

        self.publisher_einde.publish(msg)
        self.get_logger().info(f'Einde sensor gestuurd: {waarde}')

    def publish_start(self, waarde: bool):
        msg = Bool()
        msg.data = waarde
        self.start_waarde = waarde

        self.publisher_start.publish(msg)
        self.get_logger().info(f'Start gestuurd: {waarde}')

    def publish_stop(self, waarde: bool):
        msg = Bool()
        msg.data = waarde
        self.stop_waarde = waarde

        self.publisher_stop.publish(msg)
        self.get_logger().info(f'Stop gestuurd: {waarde}')

    def publish_noodstop(self, waarde: bool):
        msg = Bool()
        msg.data = waarde
        self.noodstop_waarde = waarde

        self.publisher_noodstop.publish(msg)
        self.get_logger().info(f'Noodstop gestuurd: {waarde}')

    # -------------------------
    # Reset ActionClient
    # -------------------------

    def call_reset_action(self, waarde: bool):
        self.reset_waarde = waarde

        if not self.reset_action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().warn(
                'Reset action server /reset_noodstop is niet beschikbaar'
            )
            return

        goal_msg = ResetNoodstop.Goal()

        # BELANGRIJK:
        # Deze regel moet overeenkomen met jouw .action bestand.
        #
        # Als jouw .action bijvoorbeeld dit heeft:
        # bool reset
        # ---
        # bool success
        # string message
        #
        # dan is deze regel goed:
        goal_msg.reset = waarde

        # Als jouw goal veld anders heet, pas alleen bovenstaande regel aan.
        # Voorbeelden:
        # goal_msg.data = waarde
        # goal_msg.reset_noodstop = waarde

        self.get_logger().info(f'Reset action goal gestuurd: {waarde}')

        send_goal_future = self.reset_action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(self.reset_goal_response_callback)

    def reset_goal_response_callback(self, future):
        try:
            goal_handle = future.result()
        except Exception as e:
            self.get_logger().error(f'Fout bij versturen reset action goal: {e}')
            return

        if not goal_handle.accepted:
            self.get_logger().warn('Reset action goal is geweigerd')
            return

        self.get_logger().info('Reset action goal is geaccepteerd')

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.reset_result_callback)

    def reset_result_callback(self, future):
        try:
            result = future.result().result
            self.get_logger().info(f'Reset action resultaat: {result}')
        except Exception as e:
            self.get_logger().error(f'Fout bij reset action resultaat: {e}')


class SensorHMI:
    def __init__(self, ros_node: SensorHMISimulator):
        self.ros_node = ros_node

        self.root = tk.Tk()
        self.root.title("Sensor HMI Simulator")
        self.root.geometry("420x820")
        self.root.resizable(False, False)

        self.begin_status = tk.StringVar(value="BEGIN SENSOR: FALSE")
        self.einde_status = tk.StringVar(value="EINDE SENSOR: FALSE")
        self.start_status = tk.StringVar(value="START: FALSE")
        self.stop_status = tk.StringVar(value="STOP: FALSE")
        self.noodstop_status = tk.StringVar(value="NOODSTOP: TRUE")
        self.reset_status = tk.StringVar(value="RESET ACTION: FALSE")

        self.build_layout()

    def build_layout(self):
        title = tk.Label(
            self.root,
            text="Sensor Simulatie HMI",
            font=("Arial", 18, "bold")
        )
        title.pack(pady=10)

        # Begin sensor
        begin_frame = tk.LabelFrame(
            self.root,
            text="Begin Sensor",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        begin_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            begin_frame,
            textvariable=self.begin_status,
            font=("Arial", 12)
        ).pack(pady=4)

        begin_buttons = tk.Frame(begin_frame)
        begin_buttons.pack()

        tk.Button(
            begin_buttons,
            text="TRUE",
            width=10,
            command=self.begin_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            begin_buttons,
            text="FALSE",
            width=10,
            command=self.begin_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            begin_buttons,
            text="PULS",
            width=10,
            command=self.begin_pulse
        ).grid(row=0, column=2, padx=5)

        # Einde sensor
        einde_frame = tk.LabelFrame(
            self.root,
            text="Einde Sensor",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        einde_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            einde_frame,
            textvariable=self.einde_status,
            font=("Arial", 12)
        ).pack(pady=4)

        einde_buttons = tk.Frame(einde_frame)
        einde_buttons.pack()

        tk.Button(
            einde_buttons,
            text="TRUE",
            width=10,
            command=self.einde_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            einde_buttons,
            text="FALSE",
            width=10,
            command=self.einde_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            einde_buttons,
            text="PULS",
            width=10,
            command=self.einde_pulse
        ).grid(row=0, column=2, padx=5)

        # Start
        start_frame = tk.LabelFrame(
            self.root,
            text="Start",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        start_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            start_frame,
            textvariable=self.start_status,
            font=("Arial", 12)
        ).pack(pady=4)

        start_buttons = tk.Frame(start_frame)
        start_buttons.pack()

        tk.Button(
            start_buttons,
            text="TRUE",
            width=10,
            command=self.start_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            start_buttons,
            text="FALSE",
            width=10,
            command=self.start_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            start_buttons,
            text="PULS",
            width=10,
            command=self.start_pulse
        ).grid(row=0, column=2, padx=5)

        # Stop
        stop_frame = tk.LabelFrame(
            self.root,
            text="Stop",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        stop_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            stop_frame,
            textvariable=self.stop_status,
            font=("Arial", 12)
        ).pack(pady=4)

        stop_buttons = tk.Frame(stop_frame)
        stop_buttons.pack()

        tk.Button(
            stop_buttons,
            text="TRUE",
            width=10,
            command=self.stop_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            stop_buttons,
            text="FALSE",
            width=10,
            command=self.stop_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            stop_buttons,
            text="PULS",
            width=10,
            command=self.stop_pulse
        ).grid(row=0, column=2, padx=5)

        # Noodstop
        noodstop_frame = tk.LabelFrame(
            self.root,
            text="Noodstop",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        noodstop_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            noodstop_frame,
            textvariable=self.noodstop_status,
            font=("Arial", 12)
        ).pack(pady=4)

        noodstop_buttons = tk.Frame(noodstop_frame)
        noodstop_buttons.pack()

        tk.Button(
            noodstop_buttons,
            text="TRUE",
            width=10,
            command=self.noodstop_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            noodstop_buttons,
            text="FALSE",
            width=10,
            command=self.noodstop_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            noodstop_buttons,
            text="PULS",
            width=10,
            command=self.noodstop_pulse
        ).grid(row=0, column=2, padx=5)

        # Reset action
        reset_frame = tk.LabelFrame(
            self.root,
            text="Reset Action",
            font=("Arial", 12, "bold"),
            padx=10,
            pady=8
        )
        reset_frame.pack(fill="x", padx=20, pady=5)

        tk.Label(
            reset_frame,
            textvariable=self.reset_status,
            font=("Arial", 12)
        ).pack(pady=4)

        reset_buttons = tk.Frame(reset_frame)
        reset_buttons.pack()

        tk.Button(
            reset_buttons,
            text="TRUE",
            width=10,
            command=self.reset_true
        ).grid(row=0, column=0, padx=5)

        tk.Button(
            reset_buttons,
            text="FALSE",
            width=10,
            command=self.reset_false
        ).grid(row=0, column=1, padx=5)

        tk.Button(
            reset_buttons,
            text="PULS",
            width=10,
            command=self.reset_pulse
        ).grid(row=0, column=2, padx=5)

        # Afsluitknop
        tk.Button(
            self.root,
            text="Sluiten",
            width=20,
            command=self.close
        ).pack(pady=10)

    # -------------------------
    # Begin sensor functies
    # -------------------------

    def begin_true(self):
        self.ros_node.publish_begin_sensor(True)
        self.begin_status.set("BEGIN SENSOR: TRUE")

    def begin_false(self):
        self.ros_node.publish_begin_sensor(False)
        self.begin_status.set("BEGIN SENSOR: FALSE")

    def begin_pulse(self):
        self.begin_true()
        self.root.after(1000, self.begin_false)

    # -------------------------
    # Einde sensor functies
    # -------------------------

    def einde_true(self):
        self.ros_node.publish_einde_sensor(True)
        self.einde_status.set("EINDE SENSOR: TRUE")

    def einde_false(self):
        self.ros_node.publish_einde_sensor(False)
        self.einde_status.set("EINDE SENSOR: FALSE")

    def einde_pulse(self):
        self.einde_true()
        self.root.after(1000, self.einde_false)

    # -------------------------
    # Start functies
    # -------------------------

    def start_true(self):
        self.ros_node.publish_start(True)
        self.start_status.set("START: TRUE")

    def start_false(self):
        self.ros_node.publish_start(False)
        self.start_status.set("START: FALSE")

    def start_pulse(self):
        self.start_true()
        self.root.after(1000, self.start_false)

    # -------------------------
    # Stop functies
    # -------------------------

    def stop_true(self):
        self.ros_node.publish_stop(True)
        self.stop_status.set("STOP: TRUE")

    def stop_false(self):
        self.ros_node.publish_stop(False)
        self.stop_status.set("STOP: FALSE")

    def stop_pulse(self):
        self.stop_true()
        self.root.after(1000, self.stop_false)

    # -------------------------
    # Noodstop functies
    # -------------------------

    def noodstop_true(self):
        self.ros_node.publish_noodstop(True)
        self.noodstop_status.set("NOODSTOP: TRUE")

    def noodstop_false(self):
        self.ros_node.publish_noodstop(False)
        self.noodstop_status.set("NOODSTOP: FALSE")

    def noodstop_pulse(self):
        self.noodstop_true()
        self.root.after(1000, self.noodstop_false)

    # -------------------------
    # Reset action functies
    # -------------------------

    def reset_true(self):
        self.ros_node.call_reset_action(True)
        self.reset_status.set("RESET ACTION: TRUE")

    def reset_false(self):
        self.ros_node.call_reset_action(False)
        self.reset_status.set("RESET ACTION: FALSE")

    def reset_pulse(self):
        self.reset_true()
        self.root.after(1000, self.reset_false)

    def close(self):
        self.root.quit()
        self.root.destroy()

    def run(self):
        self.root.mainloop()


def ros_spin_thread(node):
    rclpy.spin(node)


def main(args=None):
    rclpy.init(args=args)

    node = SensorHMISimulator()

    thread = threading.Thread(
        target=ros_spin_thread,
        args=(node,),
        daemon=True
    )
    thread.start()

    hmi = SensorHMI(node)

    try:
        hmi.run()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()