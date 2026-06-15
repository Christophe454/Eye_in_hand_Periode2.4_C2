import sys
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

from PySide2.QtCore import Qt
from PySide2.QtWidgets import (
    QApplication,
    QLabel,
    QFrame,
    QHBoxLayout,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget
)


class TellerPublisher(Node):
    def __init__(self):
        super().__init__('teller_publisher')

        self.counter_publishers = {
            "object_a": self.create_publisher(Int32, 'object_a_count', 10),
            "object_b": self.create_publisher(Int32, 'object_b_count', 10),
            "object_c": self.create_publisher(Int32, 'object_c_count', 10),
            "object_d": self.create_publisher(Int32, 'object_d_count', 10),
            "belt": self.create_publisher(Int32, 'belt_count', 10),
        }

    def publish_count(self, key, value):
        msg = Int32()
        msg.data = value
        self.counter_publishers[key].publish(msg)
        print(f"Verstuurd op topic '{key}_count': {value}")


class CounterRow(QFrame):
    def __init__(self, title, key, ros_node):
        super().__init__()

        self.title = title
        self.key = key
        self.ros_node = ros_node
        self.count = 0

        self.setObjectName("counterRow")
        self.setStyleSheet("""
            QFrame#counterRow {
                background-color: #1f2937;
                border: 3px solid #374151;
                border-radius: 20px;
            }
        """)

        row_layout = QHBoxLayout(self)
        row_layout.setContentsMargins(20, 20, 20, 20)
        row_layout.setSpacing(20)

        self.title_label = QLabel(self.title)
        self.title_label.setStyleSheet("""
            font-size: 24px;
            font-weight: bold;
            color: white;
        """)

        self.minus_button = QPushButton("-")
        self.minus_button.setStyleSheet("""
            QPushButton {
                background-color: #ef4444;
                color: white;
                font-size: 18px;
                font-weight: bold;
                border: none;
                border-radius: 12px;
                min-width: 60px;
                min-height: 60px;
            }
            QPushButton:hover {
                background-color: #dc2626;
            }
        """)

        self.count_label = QLabel(str(self.count))
        self.count_label.setAlignment(Qt.AlignCenter)
        self.count_label.setStyleSheet("""
            font-size: 28px;
            font-weight: bold;
            color: white;
            min-width: 80px;
        """)

        self.plus_button = QPushButton("+")
        self.plus_button.setStyleSheet("""
            QPushButton {
                background-color: #22c55e;
                color: white;
                font-size: 18px;
                font-weight: bold;
                border: none;
                border-radius: 12px;
                min-width: 60px;
                min-height: 60px;
            }
            QPushButton:hover {
                background-color: #16a34a;
            }
        """)

        row_layout.addWidget(self.title_label)
        row_layout.addStretch()
        row_layout.addWidget(self.minus_button)
        row_layout.addWidget(self.count_label)
        row_layout.addWidget(self.plus_button)

        # Iedere rij heeft zijn eigen callbacks
        self.plus_button.clicked.connect(self.increment_count)
        self.minus_button.clicked.connect(self.decrement_count)

        # Stuur beginwaarde direct uit
        self.publish_current_count()

    def publish_current_count(self):
        self.ros_node.publish_count(self.key, self.count)

    def increment_count(self):
        self.count += 1
        self.count_label.setText(str(self.count))
        self.publish_current_count()

    def decrement_count(self):
        if self.count > 0:
            self.count -= 1
            self.count_label.setText(str(self.count))
            self.publish_current_count()


class TellerHMIScreen(QMainWindow):
    def __init__(self, ros_node):
        super().__init__()

        self.ros_node = ros_node

        self.setWindowTitle("Teller HMI")
        self.resize(900, 700)

        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        self.setStyleSheet("""
            QMainWindow {
                background-color: #111827;
            }
            QWidget {
                font-family: Arial;
            }
        """)

        main_layout = QVBoxLayout(central_widget)
        main_layout.setContentsMargins(30, 30, 30, 30)
        main_layout.setSpacing(20)

        title_label = QLabel("TELLER HMI")
        title_label.setStyleSheet("""
            color: white;
            font-size: 28px;
            font-weight: bold;
        """)
        main_layout.addWidget(title_label)

        # Iedere rij heeft een eigen key/topic
        self.object_a_row = CounterRow("Object A", "object_a", self.ros_node)
        self.object_b_row = CounterRow("Object B", "object_b", self.ros_node)
        self.object_c_row = CounterRow("Object C", "object_c", self.ros_node)
        self.object_d_row = CounterRow("Object D", "object_d", self.ros_node)
        self.belt_row = CounterRow("Objecten op band", "belt", self.ros_node)

        main_layout.addWidget(self.object_a_row)
        main_layout.addWidget(self.object_b_row)
        main_layout.addWidget(self.object_c_row)
        main_layout.addWidget(self.object_d_row)
        main_layout.addWidget(self.belt_row)
        main_layout.addStretch()


def main():
    rclpy.init()

    ros_node = TellerPublisher()

    app = QApplication(sys.argv)
    window = TellerHMIScreen(ros_node)
    window.show()

    exit_code = app.exec_()

    ros_node.destroy_node()
    rclpy.shutdown()
    sys.exit(exit_code)


if __name__ == "__main__":
    main()