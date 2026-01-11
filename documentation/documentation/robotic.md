# Robotic grippers







:::::{card} 

::::{tab-set}

:::{tab-item} Vinger-gripper

```cd ~/my_ur_ws/src

```

[vinger-gripper](https://github.com/PickNikRobotics/ros2_robotiq_gripper)

:::

:::{tab-item} Vacuum-gripper

```bash
cd ~/my_ur_ws/src
git clone https://github.com/PickNikRobotics/ros2_epick_gripper.git
git clone https://github.com/RoverRobotics-forks/serial-ros2.git serial
touch ~/my_ur_ws/src/ros2_epick_gripper/epick_moveit_studio/COLCON_IGNORE

```

```bash
rosdep update
rosdep install --ignore-src --from-paths src -y
```
```
# Build the workspace
cd ~/my_ur_ws
colcon build --symlink-install
source install/setup.bash
```

[vacuum-gripper](https://github.com/PickNikRobotics/ros2_epick_gripper)

:::

::::

:::::
