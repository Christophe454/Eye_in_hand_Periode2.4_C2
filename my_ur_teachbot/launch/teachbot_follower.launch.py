#!/usr/bin/env python3
"""
Launch file for teachbot follower system with enable GUI
Starts both the teachbot follower action node and the enable GUI
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch.conditions import IfCondition
from launch_ros.actions import Node


def generate_launch_description():
    # Declare launch arguments
    declared_arguments = []
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'controller_name',
            default_value='joint_trajectory_controller',
            description='Name of the trajectory controller to use'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'update_rate',
            default_value='0.5',
            description='Update rate in seconds for sending trajectories'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'enable_mode',
            default_value='gui',
            choices=['gui', 'button'],
            description='Enable mode: "gui" for manual GUI button, "button" for teachbot button control'
        )
    )

    # Get launch configurations
    controller_name = LaunchConfiguration('controller_name')
    update_rate = LaunchConfiguration('update_rate')
    enable_mode = LaunchConfiguration('enable_mode')

    # Teachbot follower action node
    teachbot_follower_node = Node(
        package='my_ur_teachbot',
        executable='teachbot_follower_action',
        name='teachbot_follower_action',
        output='screen',
        parameters=[{
            'controller_name': controller_name,
            'update_rate': update_rate,
        }]
    )

    # Enable GUI node (manual button control)
    enable_gui_node = Node(
        package='my_ur_teachbot',
        executable='teachbot_enable_gui',
        name='teachbot_enable_gui',
        output='screen',
        condition=IfCondition(
            PythonExpression(["'", enable_mode, "' == 'gui'"])
        )
    )
    
    # Enable from button node (teachbot button control)
    enable_button_node = Node(
        package='my_ur_teachbot',
        executable='teachbot_enable_from_button',
        name='teachbot_enable_from_button',
        output='screen',
        condition=IfCondition(
            PythonExpression(["'", enable_mode, "' == 'button'"])
        )
    )

    nodes_to_launch = [
        teachbot_follower_node,
        enable_gui_node,
        enable_button_node,
    ]

    return LaunchDescription(declared_arguments + nodes_to_launch)
