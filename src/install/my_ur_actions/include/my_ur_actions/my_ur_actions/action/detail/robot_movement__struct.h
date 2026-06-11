// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_ur_actions:action/RobotMovement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_ur_actions/action/robot_movement.h"


#ifndef MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_H_
#define MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_Goal
{
  /// Type beweging
  rosidl_runtime_c__String mode;
  /// Voor vaste positie
  double target_x;
  double target_y;
  double target_z;
  /// Cameradoel gedetecteerd?
  bool use_camera_target;
  /// Snelheid
  double speed;
} my_ur_actions__action__RobotMovement_Goal;

// Struct for a sequence of my_ur_actions__action__RobotMovement_Goal.
typedef struct my_ur_actions__action__RobotMovement_Goal__Sequence
{
  my_ur_actions__action__RobotMovement_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_Result
{
  /// ===== RESULT =====
  bool success;
  rosidl_runtime_c__String message;
  /// Eindpositie
  double final_x;
  double final_y;
  double final_z;
} my_ur_actions__action__RobotMovement_Result;

// Struct for a sequence of my_ur_actions__action__RobotMovement_Result.
typedef struct my_ur_actions__action__RobotMovement_Result__Sequence
{
  my_ur_actions__action__RobotMovement_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_state'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_Feedback
{
  /// ===== FEEDBACK =====
  /// Huidige status
  rosidl_runtime_c__String current_state;
  /// Huidige positie
  double current_x;
  double current_y;
  double current_z;
  /// Percentage gereed
  double progress;
} my_ur_actions__action__RobotMovement_Feedback;

// Struct for a sequence of my_ur_actions__action__RobotMovement_Feedback.
typedef struct my_ur_actions__action__RobotMovement_Feedback__Sequence
{
  my_ur_actions__action__RobotMovement_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "my_ur_actions/action/detail/robot_movement__struct.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_ur_actions__action__RobotMovement_Goal goal;
} my_ur_actions__action__RobotMovement_SendGoal_Request;

// Struct for a sequence of my_ur_actions__action__RobotMovement_SendGoal_Request.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence
{
  my_ur_actions__action__RobotMovement_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} my_ur_actions__action__RobotMovement_SendGoal_Response;

// Struct for a sequence of my_ur_actions__action__RobotMovement_SendGoal_Response.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence
{
  my_ur_actions__action__RobotMovement_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  my_ur_actions__action__RobotMovement_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  my_ur_actions__action__RobotMovement_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence request;
  my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence response;
} my_ur_actions__action__RobotMovement_SendGoal_Event;

// Struct for a sequence of my_ur_actions__action__RobotMovement_SendGoal_Event.
typedef struct my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence
{
  my_ur_actions__action__RobotMovement_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} my_ur_actions__action__RobotMovement_GetResult_Request;

// Struct for a sequence of my_ur_actions__action__RobotMovement_GetResult_Request.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Request__Sequence
{
  my_ur_actions__action__RobotMovement_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "my_ur_actions/action/detail/robot_movement__struct.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Response
{
  int8_t status;
  my_ur_actions__action__RobotMovement_Result result;
} my_ur_actions__action__RobotMovement_GetResult_Response;

// Struct for a sequence of my_ur_actions__action__RobotMovement_GetResult_Response.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Response__Sequence
{
  my_ur_actions__action__RobotMovement_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  my_ur_actions__action__RobotMovement_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  my_ur_actions__action__RobotMovement_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  my_ur_actions__action__RobotMovement_GetResult_Request__Sequence request;
  my_ur_actions__action__RobotMovement_GetResult_Response__Sequence response;
} my_ur_actions__action__RobotMovement_GetResult_Event;

// Struct for a sequence of my_ur_actions__action__RobotMovement_GetResult_Event.
typedef struct my_ur_actions__action__RobotMovement_GetResult_Event__Sequence
{
  my_ur_actions__action__RobotMovement_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "my_ur_actions/action/detail/robot_movement__struct.h"

/// Struct defined in action/RobotMovement in the package my_ur_actions.
typedef struct my_ur_actions__action__RobotMovement_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_ur_actions__action__RobotMovement_Feedback feedback;
} my_ur_actions__action__RobotMovement_FeedbackMessage;

// Struct for a sequence of my_ur_actions__action__RobotMovement_FeedbackMessage.
typedef struct my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence
{
  my_ur_actions__action__RobotMovement_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_H_
