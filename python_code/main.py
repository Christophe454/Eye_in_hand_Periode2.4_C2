import sys
from PySide2.QtWidgets import QApplication, QMainWindow, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QGridLayout, QFrame, QLabel, QSizePolicy
from PySide2.QtCore import QTimer
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import Int32, String
from std_srvs.srv import Trigger
from geometry_msgs.msg import Vector3
from hmi_interfaces.action import Reset


feedback_log = []
max_feedback_lines = 5

class HMISubscriber(Node):
    def __init__(self):
        super().__init__('hmi_subscriber')

        self.random_subscription = self.create_subscription(
            Int32,
            'random_number',
            self.number_callback,
            10
        )

        self.object_a_subscription = self.create_subscription(
            Int32,
            'object_a_count',
            self.object_a_callback,
            10
        )

        self.object_b_subscription = self.create_subscription(
            Int32,
            'object_b_count',
            self.object_b_callback,
            10
        )

        self.object_c_subscription = self.create_subscription(
            Int32,
            'object_c_count',
            self.object_c_callback,
            10
        )

        self.object_d_subscription = self.create_subscription(
            Int32,
            'object_d_count',
            self.object_d_callback,
            10
        )      

        self.belt_subscription = self.create_subscription(
            Int32,
            'belt_count',
            self.belt_callback,
            10
        )


        self.xyz_subscription = self.create_subscription(
            Vector3,
            'xyz_values',
            self.xyz_callback,
            10
        )

        self.status_subscription = self.create_subscription(
            String,
            'status',
            self.status_callback,
            10
        )

        self.feedback_subscription = self.create_subscription(
            String,
            'hmi_feedback',
            self.feedback_callback,
            10
        )

    def number_callback(self, msg):
        camera_label.setText(str(msg.data))

    def object_a_callback(self, msg):
        object_a_count.setText(str(msg.data))

    def object_b_callback(self, msg):
        object_b_count.setText(str(msg.data))

    def object_c_callback(self, msg):
        object_c_count.setText(str(msg.data))   

    def object_d_callback(self, msg):
        object_d_count.setText(str(msg.data))

    def belt_callback(self, msg):
        belt_count.setText(str(msg.data))   


    def xyz_callback(self, msg):
        kalibratie_count.setText(f"x: {msg.x:.2f}, y: {msg.y:.2f}, z: {msg.z:.2f}")

    def status_callback(self, msg):
        print("HMI ontvangt status update: ", msg.data)
        status = msg.data.lower()
        self.get_logger().info(f"Received status: {status}")

        if status in ["standby", "running", "stopping", "resetting", "calibrating"]:
           set_status(status)

    def feedback_callback(self, msg):
        print("HMI ontvangt feedback update: ", msg.data)
        
        feedback_log.append(msg.data)

        if len(feedback_log) > max_feedback_lines:
            feedback_log.pop(0)
            
        html_lines = []

        for i, line in enumerate(feedback_log):
            if i == len(feedback_log) - 1:
                html_lines.append(f"<b><span style='color:#ffffff;'>> {line}</span><b>")
            else:
                html_lines.append(f"<span style='color:#9ca3af;'>{line}</span>")

        feedback_value.setText("<br>".join(html_lines))

    
class HMIServiceClient(Node):
    def __init__(self):
        super().__init__('hmi_service_client')
        self.startknop_client = self.create_client(Trigger, 'startknop')
        self.stopknop_client = self.create_client(Trigger, 'stopknop')
        self.resetknop_client = ActionClient(self, Reset, 'reset_action')

    def call_startknop(self):
        print("Startknop service aanroepen...")

        if not self.startknop_client.service_is_ready():
            print("Startknop service is niet beschikbaar")
            feedback_value.setText("Start service is niet beschikbaar")
            return

        request = Trigger.Request()
        future = self.startknop_client.call_async(request)
        future.add_done_callback(self.start_response_callback)

    def start_response_callback(self, future):
        try:
            response = future.result()
            print("Start response:", response.message)
            feedback_value.setText(response.message)
        except Exception as e:
            print("Start service fout:", e)
            feedback_value.setText(f"Start service fout: {e}")

    def call_stopknop(self):
        print("Stopknop service aanroepen...")

        if not self.stopknop_client.service_is_ready():
            print("Stopknop service is niet beschikbaar")
            feedback_value.setText("Stop service is niet beschikbaar")
            return

        request = Trigger.Request()
        future = self.stopknop_client.call_async(request)
        future.add_done_callback(self.stop_response_callback)

    def stop_response_callback(self, future):
        try:
            response = future.result()
            print("Stop response:", response.message)
            feedback_value.setText(response.message)
        except Exception as e:
            print("Stop service fout:", e)
            feedback_value.setText(f"Stop service fout: {e}")

    def call_resetknop(self):
        print("Resetknop actie aanroepen...")

        if not self.resetknop_client.wait_for_server(timeout_sec=1.0):
            print("Reset actie server is niet beschikbaar")
            feedback_value.setText("Reset actie server is niet beschikbaar")
            return
        
        goal_msg = Reset.Goal()
        goal_msg.start_reset = True

        send_goal_future = self.resetknop_client.send_goal_async(
            goal_msg,
            feedback_callback=self.reset_feedback_callback
        )

        send_goal_future.add_done_callback(self.reset_goal_response_callback)

    def reset_feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback.current_step
        print(f"Reset actie feedback: {feedback}")
        self.get_logger().info(f"Received reset feedback: {feedback}")
        feedback_value.setText(f"Reset: {feedback}")

    def reset_goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            print('reset goal geweigerd')
            feedback_value.setText("Reset actie geweigerd")
            return

        print("reset goal geaccepteerd")

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.reset_result_callback)

    def reset_result_callback(self, future):
        result = future.result().result
        print("reset result:", result.message)
        feedback_value.setText(result.message)
       

app = QApplication(sys.argv)

window = QMainWindow()
window.setWindowTitle("Mijn HMI")
window.resize(1200, 700)
window.setStyleSheet("""
    QMainWindow {
        background-color: #111827;
    }

    QWidget {
        color: white;
        font-family: Arial;
    }
""")

central_widget = QWidget()
window.setCentralWidget(central_widget)
main_layout = QHBoxLayout(central_widget)
main_layout.setContentsMargins(50, 50, 50, 50)

camera_frame = QFrame()
camera_frame.setStyleSheet("background-color: black; border-radius: 20px;")
camera_frame.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

camera_label = QLabel("Wacht op topic...", camera_frame)
camera_label.setStyleSheet("color: white; font-size: 40px; font-weight: bold;")
camera_label.move(60, 60)

rclpy.init()
ros_subscriber = HMISubscriber()
ros_client = HMIServiceClient()

ros_timer = QTimer()
ros_timer.timeout.connect(lambda: (
    rclpy.spin_once(ros_subscriber, timeout_sec=0),
    rclpy.spin_once(ros_client, timeout_sec=0)
))

ros_timer.start(10)

right_panel = QWidget()
right_panel.setFixedWidth(360)

right_layout = QVBoxLayout(right_panel)
right_layout.setContentsMargins(0, 0, 0, 0)

status_box = QFrame()
status_box.setObjectName("statusBox")
status_box.setStyleSheet(
    """
    QFrame#statusBox {
        background-color: #1f2937;
        border: 10px solid yellow;
        border-radius: 16px;
        padding: 24px;
    }
    """
)

status_layout = QVBoxLayout(status_box)

status_title = QLabel("STATUS")
status_title.setStyleSheet("color: #9ca3af; font-size: 12px; font-weight: bold;")

status_value = QLabel("Standby")
status_value.setStyleSheet("color: white; font-size: 24px; font-weight: bold;")

status_layout.addWidget(status_title)
status_layout.addWidget(status_value)

right_layout.addWidget(status_box)

count_box = QFrame()
count_box.setStyleSheet(
    "background-color: #1f2937; border-radius: 16px;"
)

count_layout = QVBoxLayout(count_box)
count_layout.setContentsMargins(20, 20, 20, 20)

count_title = QLabel("UITGESORTEERD")
count_title.setStyleSheet("color: #9ca3af; font-size: 12px; font-weight: bold;")

count_layout.addWidget(count_title)

row_a = QHBoxLayout()
object_a_label = QLabel("Object A")
object_a_label.setStyleSheet("color: white; font-size: 15px;")
object_a_count = QLabel("0")
object_a_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")
row_a.addWidget(object_a_label)
row_a.addStretch()
row_a.addWidget(object_a_count)
count_layout.addLayout(row_a)

row_b = QHBoxLayout()
object_b_label = QLabel("Object B")
object_b_label.setStyleSheet("color: white; font-size: 15px;")
object_b_count = QLabel("0")
object_b_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")
row_b.addWidget(object_b_label)
row_b.addStretch()
row_b.addWidget(object_b_count)
count_layout.addLayout(row_b)

row_c = QHBoxLayout()
object_c_label = QLabel("Object C")
object_c_label.setStyleSheet("color: white; font-size: 15px;")
object_c_count = QLabel("0")
object_c_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")
row_c.addWidget(object_c_label)
row_c.addStretch()
row_c.addWidget(object_c_count)
count_layout.addLayout(row_c)

row_d = QHBoxLayout()
object_d_label = QLabel("Object D")
object_d_label.setStyleSheet("color: white; font-size: 15px;")
object_d_count = QLabel("0")
object_d_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")
row_d.addWidget(object_d_label)
row_d.addStretch()
row_d.addWidget(object_d_count)
count_layout.addLayout(row_d)

right_layout.addWidget(count_box)

belt_box = QFrame()
belt_box.setStyleSheet(
    "background-color: #1f2937; border-radius: 16px;"
)

belt_layout = QVBoxLayout(belt_box)
belt_layout.setContentsMargins(20, 20, 20, 20)

belt_row = QHBoxLayout()

belt_label = QLabel("Objecten op band")
belt_label.setStyleSheet("color: white; font-size: 15px;")

belt_count = QLabel("0")
belt_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")

belt_row.addWidget(belt_label)
belt_row.addStretch()
belt_row.addWidget(belt_count)

belt_layout.addLayout(belt_row)

right_layout.addWidget(belt_box)

feedback_box = QFrame()
feedback_box.setFixedHeight(170)
feedback_box.setStyleSheet("""
    Qframe { 
        background-color: #0f172a;
        border: 2px solid #374151;
        border-radius: 14px;
    }
""")

feedback_layout = QVBoxLayout(feedback_box )
feedback_layout.setContentsMargins(20, 20, 20, 20)

feedback_title = QLabel("SYSTEEM MELDINGEN")
feedback_title.setStyleSheet("""
    color: #9ca3af;
    font-size: 15px;
    font-weight: bold;
    """)
    
feedback_value = QLabel("")
feedback_value.setFixedHeight(110)
feedback_value.setStyleSheet("""
    color: white;
    font-size: 14px;
    font-weight: normal;
    """)

feedback_value.setWordWrap(True)

feedback_layout.addWidget(feedback_title)
feedback_layout.addWidget(feedback_value)

right_layout.addWidget(feedback_box)
   
kalibratie_box = QFrame()
kalibratie_box.setStyleSheet(
    "background-color: #1f2937; border-radius: 16px;"
)

kalibratie_layout = QVBoxLayout(kalibratie_box)
kalibratie_layout.setContentsMargins(20, 20, 20, 20)

kalibratie_row = QHBoxLayout()

kalibratie_label = QLabel("Kalibratie status")
kalibratie_label.setStyleSheet("color: white; font-size: 15px;")

kalibratie_count = QLabel("Niet gekalibreerd")
kalibratie_count.setStyleSheet("color: white; font-size: 15px; font-weight: bold;")

kalibratie_row.addWidget(kalibratie_label)
kalibratie_row.addStretch()
kalibratie_row.addWidget(kalibratie_count)

kalibratie_layout.addLayout(kalibratie_row)
right_layout.addWidget(kalibratie_box)


def set_status(status_name):
    status_colors = {
    "standby": "yellow",
    "running": "green",
    "stopping": "orange",
    "resetting": "blue",
    "calibrating": "purple"
}

    status_texts = {
    "standby": "Standby",
    "running": "Running",
    "stopping": "Stopping",
    "resetting": "Resetting",
    "calibrating": "Calibrating"
}


    color = status_colors[status_name]
    text = status_texts[status_name]

    status_value.setText(text)

    status_box.setStyleSheet(f"""
        QFrame#statusBox {{
            background-color: #1f2937;
            border: 10px solid {color};
            border-radius: 16px;
            padding: 24px;
        }}
    """)

set_status("standby")

main_layout.addWidget(camera_frame, 4)
main_layout.addWidget(right_panel, 1)

bottom_row = QHBoxLayout()

right_layout.addStretch()
right_layout.addLayout(bottom_row)

bottom_row.addStretch()

button_layout = QHBoxLayout()
button_layout.setSpacing(15)

start_button = QPushButton("START")
stop_button = QPushButton("STOP")
reset_button = QPushButton("RESET")
#calibration_button = QPushButton("CALIBRATION")

start_button.setStyleSheet("""
    background-color: green;
    color: black;
""")

stop_button.setStyleSheet("""
    background-color: red;
    color: black;
""")

reset_button.setStyleSheet("""
    background-color: blue;
    color: black;
""")

#calibration_button.setStyleSheet("""
  #  background-color: purple;
    #color: black;
#""")

start_button.clicked.connect(lambda checked=False: ros_client.call_startknop())
stop_button.clicked.connect(lambda checked=False: ros_client.call_stopknop())
reset_button.clicked.connect(lambda checked=False: ros_client.call_resetknop())


start_button.setFixedSize(110, 60)
stop_button.setFixedSize(110, 60)
reset_button.setFixedSize(110, 60)
#calibration_button.setFixedSize(150, 60)

button_layout.addWidget(start_button)
button_layout.addWidget(stop_button)
button_layout.addWidget(reset_button)
#button_layout.addWidget(calibration_button)

bottom_row.addLayout(button_layout)
window.show()

exit_code = app.exec_()

ros_subscriber.destroy_node()
ros_client.destroy_node()
rclpy.shutdown()

sys.exit(exit_code)