#!/bin/bash

# Save the current directory
current_dir=$(pwd)
cd ../..

# Update package lists
sudo apt update

# Check is the package "ros-$ROS_DISTRO-ur-robot-driver" is installed
if dpkg -s ros-$ROS_DISTRO-ur-robot-driver &> /dev/null; then
    echo "Package ros-$ROS_DISTRO-ur-robot-driver is already installed."
else
    echo "Package ros-$ROS_DISTRO-ur-robot-driver is not installed. Installing..."
    git clone -b $ROS_DISTRO https://github.com/UniversalRobots/Universal_Robots_ROS2_Driver.git
fi

#check is the package "ros-$ROS_DISTRO-ur-description" is installed
if dpkg -s ros-$ROS_DISTRO-ur-description &> /dev/null; then
    echo "Package ros-$ROS_DISTRO-ur-description is already installed."
else
    echo "Package ros-$ROS_DISTRO-ur-description is not installed. Installing..."
    git clone -b $ROS_DISTRO https://github.com/UniversalRobots/Universal_Robots_ROS2_Description.git
fi

# Install dependencies and build the workspace
cd ..
rosdep update
rosdep install --ignore-src --from-paths src -y

# Build the workspace
colcon build --symlink-install
source install/setup.bash

# Add source command to .bashrc if it doesn't already exist
if ! grep -Fxq "source $(pwd)/install/setup.bash" ~/.bashrc; then
    echo "source $(pwd)/install/setup.bash" >> ~/.bashrc
    echo "Added source command to .bashrc"
else
    echo "Source command already exists in .bashrc"
fi  

#return to the original directory
cd "$current_dir"
