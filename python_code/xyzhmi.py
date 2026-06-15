import sys
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3

from PySide2.QtCore import Qt
from PySide2.QtGui import QDoubleValidator
from PySide2.QtWidgets import (
    QApplication,
    QLabel,
    QFrame,
    QLineEdit,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QHBoxLayout,
    QWidget
)


class XYZPublisher(Node):
    def __init__(self):
        super().__init__('xyz_publisher')
        self.publisher_ = self.create_publisher(Vector3, 'xyz_values', 10)

    def publish_xyz(self, x, y, z):
        msg = Vector3()
        msg.x = x
        msg.y = y
        msg.z = z

        self.publisher_.publish(msg)
        print(f"Verstuurd op topic 'xyz_values': x={x}, y={y}, z={z}")


class XYZHMIScreen(QMainWindow):
    def __init__(self, ros_node):
        super().__init__()

        self.ros_node = ros_node

        self.setWindowTitle("XYZ HMI")
        self.resize(700, 500)

        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        self.setStyleSheet("""
            QMainWindow {
                background-color: #111827;
            }
            QWidget {
                font-family: Arial;
                color: white;
            }
            QLineEdit {
                background-color: #1f2937;
                border: 2px solid #374151;
                border-radius: 12px;
                padding: 12px;
                font-size: 22px;
                color: white;
            }
            QLineEdit:focus {
                border: 2px solid #3b82f6;
            }
            QPushButton {
                background-color: #22c55e;
                color: white;
                font-size: 22px;
                font-weight: bold;
                border: none;
                border-radius: 14px;
                min-height: 60px;
            }
            QPushButton:hover {
                background-color: #16a34a;
            }
        """)

        main_layout = QVBoxLayout(central_widget)
        main_layout.setContentsMargins(30, 30, 30, 30)
        main_layout.setSpacing(20)

        title_label = QLabel("XYZ HMI")
        title_label.setStyleSheet("""
            font-size: 30px;
            font-weight: bold;
            color: white;
        """)
        main_layout.addWidget(title_label)

        subtitle_label = QLabel("Vul de X-, Y- en Z-waarde in en verstuur ze als ROS 2 topic")
        subtitle_label.setStyleSheet("""
            font-size: 16px;
            color: #cbd5e1;
        """)
        main_layout.addWidget(subtitle_label)

        input_frame = QFrame()
        input_frame.setStyleSheet("""
            QFrame {
                background-color: #1f2937;
                border: 3px solid #374151;
                border-radius: 20px;
            }
        """)
        input_layout = QVBoxLayout(input_frame)
        input_layout.setContentsMargins(25, 25, 25, 25)
        input_layout.setSpacing(18)

        # Alleen numerieke waarden toestaan (kommagetallen)
        self.double_validator = QDoubleValidator()

        # X
        self.x_label = QLabel("X waarde")
        self.x_label.setStyleSheet("font-size: 22px; font-weight: bold;")
        self.x_input = QLineEdit()
        self.x_input.setPlaceholderText("bijv. 1.25")
        self.x_input.setValidator(self.double_validator)

        # Y
        self.y_label = QLabel("Y waarde")
        self.y_label.setStyleSheet("font-size: 22px; font-weight: bold;")
        self.y_input = QLineEdit()
        self.y_input.setPlaceholderText("bijv. 2.50")
        self.y_input.setValidator(self.double_validator)

        # Z
        self.z_label = QLabel("Z waarde")
        self.z_label.setStyleSheet("font-size: 22px; font-weight: bold;")
        self.z_input = QLineEdit()
        self.z_input.setPlaceholderText("bijv. 3.75")
        self.z_input.setValidator(self.double_validator)

        input_layout.addWidget(self.x_label)
        input_layout.addWidget(self.x_input)
        input_layout.addWidget(self.y_label)
        input_layout.addWidget(self.y_input)
        input_layout.addWidget(self.z_label)
        input_layout.addWidget(self.z_input)

        main_layout.addWidget(input_frame)

        # Buttons
        button_layout = QHBoxLayout()
        button_layout.setSpacing(15)

        self.send_button = QPushButton("VERSTUUR XYZ")
        self.clear_button = QPushButton("LEEGMAKEN")

        self.clear_button.setStyleSheet("""
            QPushButton {
                background-color: #f59e0b;
                color: white;
                font-size: 22px;
                font-weight: bold;
                border: none;
                border-radius: 14px;
                min-height: 60px;
            }
            QPushButton:hover {
                background-color: #d97706;
            }
        """)

        button_layout.addWidget(self.send_button)
        button_layout.addWidget(self.clear_button)

        main_layout.addLayout(button_layout)

        # Statusvak
        self.status_frame = QFrame()
        self.status_frame.setStyleSheet("""
            QFrame {
                background-color: #1f2937;
                border: 3px solid #374151;
                border-radius: 20px;
            }
        """)
        status_layout = QVBoxLayout(self.status_frame)
        status_layout.setContentsMargins(20, 20, 20, 20)

        self.status_title = QLabel("STATUS")
        self.status_title.setStyleSheet("""
            font-size: 16px;
            color: #94a3b8;
            font-weight: bold;
        """)

        self.status_label = QLabel("Nog niets verstuurd")
        self.status_label.setStyleSheet("""
            font-size: 22px;
            font-weight: bold;
            color: white;
        """)

        status_layout.addWidget(self.status_title)
        status_layout.addWidget(self.status_label)

        main_layout.addWidget(self.status_frame)
        main_layout.addStretch()

        # Signals
        self.send_button.clicked.connect(self.send_xyz)
        self.clear_button.clicked.connect(self.clear_inputs)

        # Enter in een veld = ook versturen
        self.x_input.returnPressed.connect(self.send_xyz)
        self.y_input.returnPressed.connect(self.send_xyz)
        self.z_input.returnPressed.connect(self.send_xyz)

    def set_status(self, text, color="white"):
        self.status_label.setText(text)
        self.status_label.setStyleSheet(f"""
            font-size: 22px;
            font-weight: bold;
            color: {color};
        """)

    def send_xyz(self):
        x_text = self.x_input.text().strip()
        y_text = self.y_input.text().strip()
        z_text = self.z_input.text().strip()

        if not x_text or not y_text or not z_text:
            self.set_status("Vul eerst X, Y en Z in", "#ef4444")
            return

        try:
            x = float(x_text)
            y = float(y_text)
            z = float(z_text)
        except ValueError:
            self.set_status("Ongeldige invoer", "#ef4444")
            return

        self.ros_node.publish_xyz(x, y, z)
        self.set_status(f"Verstuurd: X={x}, Y={y}, Z={z}", "#22c55e")

    def clear_inputs(self):
        self.x_input.clear()
        self.y_input.clear()
        self.z_input.clear()
        self.set_status("Velden geleegd", "#f59e0b")


def main():
    rclpy.init()
    ros_node = XYZPublisher()

    app = QApplication(sys.argv)
    window = XYZHMIScreen(ros_node)
    window.show()

    exit_code = app.exec_()

    ros_node.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)


if __name__ == "__main__":
    main()