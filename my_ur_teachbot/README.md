# UR TeachBot Follower

This package contains ROS2 nodes that allow a UR robot to follow joint positions published by a teachbot device.

## Overview

The teachbot device publishes joint states on `/teachbot/joint_states`, and these nodes command the UR robot to move to match those positions using MoveIt.

## Available Nodes

### 1. `ur_teachbot_commander` ⭐ **RECOMMENDED - Simplest & Works**

This node directly publishes trajectory commands to the robot controller. It's the simplest and most direct approach.

**Usage:**
```bash
ros2 run my_ur_teachbot ur_teachbot_commander
```

**Parameters:**
- `teachbot_topic` (default: `/teachbot/joint_states`) - Topic to subscribe to for teachbot commands
- `controller_name` (default: `scaled_joint_trajectory_controller`) - Name of the joint trajectory controller
- `update_rate` (default: `0.5`) - Seconds between updates
- `position_tolerance` (default: `0.01`) - Minimum position change (radians) to trigger movement
- `trajectory_duration` (default: `0.5`) - Duration for each trajectory segment

**Example with custom parameters:**
```bash
ros2 run my_ur_teachbot ur_teachbot_commander --ros-args \
  -p teachbot_topic:=/my_teachbot/joint_states \
  -p update_rate:=0.2 \
  -p trajectory_duration:=0.3
```

### 2. `ur_teachbot_action` ✅ **Action Client - Robust**

This node uses action client to send trajectory goals. More robust with feedback and result handling.

**Usage:**
```bash
ros2 run my_ur_teachbot ur_teachbot_action
```

**Parameters:**
- `teachbot_topic` (default: `/teachbot/joint_states`)
- `controller_name` (default: `scaled_joint_trajectory_controller`)
- `update_rate` (default: `0.5`)
- `position_tolerance` (default: `0.01`)
- `trajectory_duration` (default: `0.5`)

### 3. `ur_teachbot_follower` ⚠️ **MoveIt Python API - Advanced**

This node uses the MoveIt Python API for motion planning. Requires MoveIt to be properly configured.

**Usage:**
```bash
ros2 run my_ur_teachbot ur_teachbot_follower
```

**Parameters:**
- `teachbot_topic` (default: `/teachbot/joint_states`)
- `move_group_name` (default: `arm`)
- `update_rate` (default: `0.5`)
- `position_tolerance` (default: `0.01`)

### 4. `ur_teachbot_simple` ⚠️ **MoveGroup Interface - Experimental**

This node uses MoveIt's MoveGroup interface. May have compatibility issues.

**Usage:**
```bash
ros2 run my_ur_teachbot ur_teachbot_simple
```

**Parameters:**
- `teachbot_topic` (default: `/teachbot/joint_states`)
- `move_group_name` (default: `ur_manipulator`)
- `update_rate` (default: `1.0`)
- `position_tolerance` (default: `0.01`)
- `velocity_scaling` (default: `0.3`) - Maximum velocity scaling factor
- `acceleration_scaling` (default: `0.3`) - Maximum acceleration scaling factor

## Complete Workflow

1. **Build the package:**
   ```bash
   cd ~/ur_ws
   colcon build --packages-select my_ur_teachbot
   source install/setup.bash
   ```

2. **Launch your UR robot with MoveIt:**
   ```bash
   # For simulation:
   ros2 launch my_ur_bringup ur5e_bringup_sim.launch.py
   
   # Or for real robot:
   ros2 launch my_ur_bringup ur5e_bringup.launch.py robot_ip:=<ROBOT_IP>
   ```

3. **Start your teachbot device** (ensure it publishes to `/teachbot/joint_states`)

4. **Run the follower node:**
   ```bash
   ros2 run my_ur_teachbot ur_teachbot_commander
   ```

## Joint Names

Make sure the joint names in the teachbot message match the UR robot joint names:
- `shoulder_pan_joint`
- `shoulder_lift_joint`
- `elbow_joint`
- `wrist_1_joint`
- `wrist_2_joint`
- `wrist_3_joint`

## Troubleshooting

### Robot doesn't move
- Check that `/teachbot/joint_states` is being published: `ros2 topic echo /teachbot/joint_states`
- Verify MoveIt is running: `ros2 node list | grep move_group`
- Check for errors: `ros2 topic echo /rosout`

### Movement is too slow/fast
- Adjust `update_rate` parameter (lower = faster updates)
- For `ur_teachbot_simple`, adjust `velocity_scaling` and `acceleration_scaling`
- For `ur_teachbot_commander`, adjust `trajectory_duration`

### Joint names don't match
- Check your teachbot joint names: `ros2 topic echo /teachbot/joint_states --once`
- Verify UR joint names: `ros2 topic echo /joint_states --once`

## Safety Notes

⚠️ **Warning**: This node will command the robot to follow the teachbot positions. Ensure:
- The workspace is clear of obstacles
- Emergency stop is accessible
- The robot is in a safe starting configuration
- You start with slow update rates and small movements to test

## License

TODO: Add license information
