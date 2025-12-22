#!/usr/bin/env python3
"""
TeachBot Enable from Button State

This node subscribes to /teachbot/state topic and monitors button 1.
When button 1 is pressed, it toggles the /teachbot/enable topic.
The current enable state is displayed in a GUI.
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
import tkinter as tk
from tkinter import ttk
from teachbot_interfaces.msg import TeachbotState

class TeachBotEnableFromButton(Node):
    """Node that enables/disables teachbot following based on button 1 from /teachbot/state."""
    
    def __init__(self):
        super().__init__('teachbot_enable_from_button')
        
        # Declare parameters
        self.declare_parameter('state_topic', '/teachbot/state')
        self.declare_parameter('enable_topic', '/teachbot/enable')
        self.declare_parameter('button_index', 1)  # Button 1 (index 1)
        self.declare_parameter('publish_rate', 10.0)  # Hz
        
        # Get parameters
        state_topic = self.get_parameter('state_topic').value
        enable_topic = self.get_parameter('enable_topic').value
        self.button_index = self.get_parameter('button_index').value
        publish_rate = self.get_parameter('publish_rate').value
        
        # Create publisher for enable state
        self.enable_pub = self.create_publisher(Bool, enable_topic, 10)
        
        # Create subscriber for teachbot state
        self.state_sub = self.create_subscription(
            TeachbotState,
            state_topic,
            self.state_callback,
            10
        )
        
        # Create timer to publish enable state at regular intervals
        self.timer = self.create_timer(1.0 / publish_rate, self.publish_enable_state)
        
        # State
        self.enabled = False
        self.last_button_state = 0  # Track last button state for edge detection
        
        # Create GUI
        self.create_gui()
        
        self.get_logger().info(f'Subscribed to {state_topic}')
        self.get_logger().info(f'Publishing enable state to {enable_topic}')
        self.get_logger().info(f'Monitoring button index {self.button_index}')
        self.get_logger().info('GUI ready. Press button 1 on teachbot to toggle enable/disable.')
    
    def state_callback(self, msg):
        
        current_button_state = msg.btn1
        
        # Detect rising edge (button press)
        if current_button_state == 1 and self.last_button_state == 0:
            self.toggle_enable()
        
        self.last_button_state = current_button_state
    
    def toggle_enable(self):
        """Toggle the enable state."""
        self.enabled = not self.enabled
        self.update_gui()
        self.get_logger().info(f'TeachBot following {"ENABLED" if self.enabled else "DISABLED"}')
    
    def publish_enable_state(self):
        """Publish the current enable state."""
        msg = Bool()
        msg.data = self.enabled
        self.enable_pub.publish(msg)
    
    def create_gui(self):
        """Create the GUI window to display enable state."""
        self.root = tk.Tk()
        self.root.title("TeachBot Enable Status")
        self.root.geometry("350x200")
        
        # Configure style
        style = ttk.Style()
        style.configure('TLabel', font=('Arial', 12))
        
        # Main frame
        main_frame = ttk.Frame(self.root, padding="20")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Title
        title_label = ttk.Label(
            main_frame,
            text="TeachBot Enable Control",
            font=('Arial', 14, 'bold')
        )
        title_label.grid(row=0, column=0, pady=10)
        
        # Status label
        self.status_label = ttk.Label(
            main_frame, 
            text="TeachBot Following: DISABLED",
            font=('Arial', 12, 'bold')
        )
        self.status_label.grid(row=1, column=0, pady=10)
        
        # Status indicator (visual box)
        self.status_canvas = tk.Canvas(
            main_frame,
            width=200,
            height=60,
            bg='#ffcccc',
            highlightthickness=2,
            highlightbackground='#cc0000'
        )
        self.status_canvas.grid(row=2, column=0, pady=10)
        
        self.status_text = self.status_canvas.create_text(
            100, 30,
            text="DISABLED",
            font=('Arial', 20, 'bold'),
            fill='#cc0000'
        )
        
        # Instruction label
        instruction_label = ttk.Label(
            main_frame,
            text="Press button 1 on teachbot to toggle",
            font=('Arial', 10, 'italic')
        )
        instruction_label.grid(row=3, column=0, pady=10)
        
        # Configure grid weights
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        main_frame.columnconfigure(0, weight=1)
        
        # Handle window close
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)
    
    def update_gui(self):
        """Update the GUI to reflect current state."""
        if self.enabled:
            self.status_label.config(
                text="TeachBot Following: ENABLED",
                foreground='green'
            )
            self.status_canvas.config(
                bg='#ccffcc',
                highlightbackground='#00cc00'
            )
            self.status_canvas.itemconfig(
                self.status_text,
                text="ENABLED",
                fill='#00cc00'
            )
        else:
            self.status_label.config(
                text="TeachBot Following: DISABLED",
                foreground='red'
            )
            self.status_canvas.config(
                bg='#ffcccc',
                highlightbackground='#cc0000'
            )
            self.status_canvas.itemconfig(
                self.status_text,
                text="DISABLED",
                fill='#cc0000'
            )
    
    def update_ros(self):
        """Update ROS while keeping GUI responsive."""
        rclpy.spin_once(self, timeout_sec=0.01)
        self.root.after(10, self.update_ros)
    
    def on_closing(self):
        """Handle window closing."""
        self.get_logger().info('Closing TeachBot Enable GUI')
        self.root.quit()
    
    def run(self):
        """Run the GUI event loop."""
        self.root.after(10, self.update_ros)
        self.root.mainloop()


def main(args=None):
    rclpy.init(args=args)
    
    try:
        node = TeachBotEnableFromButton()
        node.run()
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f'Error: {e}')
    finally:
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
