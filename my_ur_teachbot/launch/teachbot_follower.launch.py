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
    
    # Get launch configurations
    controller_name = LaunchConfiguration('controller_name')
    update_rate = LaunchConfiguration('update_rate')

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



    nodes_to_launch = [
        teachbot_follower_node,
      ]
    return LaunchDescription(declared_arguments + nodes_to_launch)
