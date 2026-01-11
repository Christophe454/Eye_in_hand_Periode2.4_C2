#!/bin/bash

# Migration script to change robot type across all my_ur_ packages
# Usage: ./migrate.bash <old_type> <new_type>
# Example: ./migrate.bash ur5 ur10e

set -e

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if correct number of arguments provided
if [ "$#" -ne 2 ]; then
    echo -e "${RED}Error: Incorrect number of arguments${NC}"
    echo "Usage: $0 <old_type> <new_type>"
    echo "Example: $0 ur5 ur10e"
    echo ""
    echo "Supported UR robot types:"
    echo "  - ur3, ur3e"
    echo "  - ur5, ur5e"
    echo "  - ur10, ur10e"
    echo "  - ur16e"
    echo "  - ur20"
    exit 1
fi

OLD_TYPE=$1
NEW_TYPE=$2

# Get the script directory and workspace root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}UR Robot Type Migration Script${NC}"
echo -e "${GREEN}========================================${NC}"
echo -e "Old type: ${YELLOW}$OLD_TYPE${NC}"
echo -e "New type: ${YELLOW}$NEW_TYPE${NC}"
echo -e "Workspace: ${YELLOW}$WORKSPACE_ROOT${NC}"
echo ""

# Confirm with user
read -p "This will modify files in the workspace. Continue? (y/n) " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo -e "${RED}Migration cancelled${NC}"
    exit 1
fi

echo ""
echo -e "${GREEN}Starting migration...${NC}"
echo ""

# Counter for modified files
MODIFIED_COUNT=0

# Function to replace text in file
replace_in_file() {
    local file=$1
    local old=$2
    local new=$3
    
    if [ -f "$file" ]; then
        if grep -q "$old" "$file"; then
            sed -i "s/$old/$new/g" "$file"
            echo -e "${GREEN}✓${NC} Modified: $file"
            ((MODIFIED_COUNT++))
        fi
    fi
}

# Process the main URDF/XACRO file
TARGET_FILE="$WORKSPACE_ROOT/my_ur_description/urdf/ur.urdf.xacro"

if [ -f "$TARGET_FILE" ]; then
    echo -e "${YELLOW}Processing file: $TARGET_FILE${NC}"
    replace_in_file "$TARGET_FILE" "$OLD_TYPE" "$NEW_TYPE"
else
    echo -e "${RED}Error: Target file not found: $TARGET_FILE${NC}"
    exit 1
fi

# Process configuration files in my_ur_moveit_config/config
CONFIG_DIR="$WORKSPACE_ROOT/my_ur_moveit_config/config"

if [ -d "$CONFIG_DIR" ]; then
    echo -e "${YELLOW}Processing MoveIt config files${NC}"
    
    # Find and process all relevant config files
    find "$CONFIG_DIR" -maxdepth 1 -type f \
        \( -name "*.yaml" -o -name "*.srdf" -o -name "*.rviz" \) | while read -r file; do
        replace_in_file "$file" "$OLD_TYPE" "$NEW_TYPE"
    done
else
    echo -e "${YELLOW}Warning: MoveIt config directory not found: $CONFIG_DIR${NC}"
fi

# Process launch files in my_ur_bringup/launch
LAUNCH_DIR="$WORKSPACE_ROOT/my_ur_bringup/launch"

if [ -d "$LAUNCH_DIR" ]; then
    echo -e "${YELLOW}Processing launch files${NC}"
    
    # Find and process all launch.py files
    find "$LAUNCH_DIR" -type f -name "*.launch.py" | while read -r file; do
        replace_in_file "$file" "$OLD_TYPE" "$NEW_TYPE"
    done
else
    echo -e "${YELLOW}Warning: Launch directory not found: $LAUNCH_DIR${NC}"
fi

echo ""
echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}Migration completed!${NC}"
echo -e "${GREEN}========================================${NC}"
echo -e "Modified ${YELLOW}$MODIFIED_COUNT${NC} file(s)"
echo ""
echo -e "${YELLOW}Important next steps:${NC}"
echo "1. Review the changes with: git diff"
echo "2. Rebuild the workspace: colcon build"
echo "3. Test the modified configuration"
echo ""
echo -e "${YELLOW}Note:${NC} You may need to update:"
echo "  - URDF/XACRO files with robot-specific dimensions"
echo "  - Joint limits in configuration files"
echo "  - Kinematics solver parameters"
echo ""
