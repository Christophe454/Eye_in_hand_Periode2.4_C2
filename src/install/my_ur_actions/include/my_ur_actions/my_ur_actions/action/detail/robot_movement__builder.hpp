// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_ur_actions:action/RobotMovement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_ur_actions/action/robot_movement.hpp"


#ifndef MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__BUILDER_HPP_
#define MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_ur_actions/action/detail/robot_movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_Goal_speed
{
public:
  explicit Init_RobotMovement_Goal_speed(::my_ur_actions::action::RobotMovement_Goal & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_Goal speed(::my_ur_actions::action::RobotMovement_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

class Init_RobotMovement_Goal_use_camera_target
{
public:
  explicit Init_RobotMovement_Goal_use_camera_target(::my_ur_actions::action::RobotMovement_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Goal_speed use_camera_target(::my_ur_actions::action::RobotMovement_Goal::_use_camera_target_type arg)
  {
    msg_.use_camera_target = std::move(arg);
    return Init_RobotMovement_Goal_speed(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

class Init_RobotMovement_Goal_target_z
{
public:
  explicit Init_RobotMovement_Goal_target_z(::my_ur_actions::action::RobotMovement_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Goal_use_camera_target target_z(::my_ur_actions::action::RobotMovement_Goal::_target_z_type arg)
  {
    msg_.target_z = std::move(arg);
    return Init_RobotMovement_Goal_use_camera_target(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

class Init_RobotMovement_Goal_target_y
{
public:
  explicit Init_RobotMovement_Goal_target_y(::my_ur_actions::action::RobotMovement_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Goal_target_z target_y(::my_ur_actions::action::RobotMovement_Goal::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return Init_RobotMovement_Goal_target_z(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

class Init_RobotMovement_Goal_target_x
{
public:
  explicit Init_RobotMovement_Goal_target_x(::my_ur_actions::action::RobotMovement_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Goal_target_y target_x(::my_ur_actions::action::RobotMovement_Goal::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_RobotMovement_Goal_target_y(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

class Init_RobotMovement_Goal_mode
{
public:
  Init_RobotMovement_Goal_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_Goal_target_x mode(::my_ur_actions::action::RobotMovement_Goal::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_RobotMovement_Goal_target_x(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_Goal>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_Goal_mode();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_Result_final_z
{
public:
  explicit Init_RobotMovement_Result_final_z(::my_ur_actions::action::RobotMovement_Result & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_Result final_z(::my_ur_actions::action::RobotMovement_Result::_final_z_type arg)
  {
    msg_.final_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Result msg_;
};

class Init_RobotMovement_Result_final_y
{
public:
  explicit Init_RobotMovement_Result_final_y(::my_ur_actions::action::RobotMovement_Result & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Result_final_z final_y(::my_ur_actions::action::RobotMovement_Result::_final_y_type arg)
  {
    msg_.final_y = std::move(arg);
    return Init_RobotMovement_Result_final_z(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Result msg_;
};

class Init_RobotMovement_Result_final_x
{
public:
  explicit Init_RobotMovement_Result_final_x(::my_ur_actions::action::RobotMovement_Result & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Result_final_y final_x(::my_ur_actions::action::RobotMovement_Result::_final_x_type arg)
  {
    msg_.final_x = std::move(arg);
    return Init_RobotMovement_Result_final_y(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Result msg_;
};

class Init_RobotMovement_Result_message
{
public:
  explicit Init_RobotMovement_Result_message(::my_ur_actions::action::RobotMovement_Result & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Result_final_x message(::my_ur_actions::action::RobotMovement_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_RobotMovement_Result_final_x(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Result msg_;
};

class Init_RobotMovement_Result_success
{
public:
  Init_RobotMovement_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_Result_message success(::my_ur_actions::action::RobotMovement_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RobotMovement_Result_message(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_Result>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_Result_success();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_Feedback_progress
{
public:
  explicit Init_RobotMovement_Feedback_progress(::my_ur_actions::action::RobotMovement_Feedback & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_Feedback progress(::my_ur_actions::action::RobotMovement_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Feedback msg_;
};

class Init_RobotMovement_Feedback_current_z
{
public:
  explicit Init_RobotMovement_Feedback_current_z(::my_ur_actions::action::RobotMovement_Feedback & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Feedback_progress current_z(::my_ur_actions::action::RobotMovement_Feedback::_current_z_type arg)
  {
    msg_.current_z = std::move(arg);
    return Init_RobotMovement_Feedback_progress(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Feedback msg_;
};

class Init_RobotMovement_Feedback_current_y
{
public:
  explicit Init_RobotMovement_Feedback_current_y(::my_ur_actions::action::RobotMovement_Feedback & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Feedback_current_z current_y(::my_ur_actions::action::RobotMovement_Feedback::_current_y_type arg)
  {
    msg_.current_y = std::move(arg);
    return Init_RobotMovement_Feedback_current_z(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Feedback msg_;
};

class Init_RobotMovement_Feedback_current_x
{
public:
  explicit Init_RobotMovement_Feedback_current_x(::my_ur_actions::action::RobotMovement_Feedback & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_Feedback_current_y current_x(::my_ur_actions::action::RobotMovement_Feedback::_current_x_type arg)
  {
    msg_.current_x = std::move(arg);
    return Init_RobotMovement_Feedback_current_y(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Feedback msg_;
};

class Init_RobotMovement_Feedback_current_state
{
public:
  Init_RobotMovement_Feedback_current_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_Feedback_current_x current_state(::my_ur_actions::action::RobotMovement_Feedback::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return Init_RobotMovement_Feedback_current_x(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_Feedback>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_Feedback_current_state();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_SendGoal_Request_goal
{
public:
  explicit Init_RobotMovement_SendGoal_Request_goal(::my_ur_actions::action::RobotMovement_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_SendGoal_Request goal(::my_ur_actions::action::RobotMovement_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Request msg_;
};

class Init_RobotMovement_SendGoal_Request_goal_id
{
public:
  Init_RobotMovement_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_SendGoal_Request_goal goal_id(::my_ur_actions::action::RobotMovement_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotMovement_SendGoal_Request_goal(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_SendGoal_Request>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_SendGoal_Request_goal_id();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_SendGoal_Response_stamp
{
public:
  explicit Init_RobotMovement_SendGoal_Response_stamp(::my_ur_actions::action::RobotMovement_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_SendGoal_Response stamp(::my_ur_actions::action::RobotMovement_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Response msg_;
};

class Init_RobotMovement_SendGoal_Response_accepted
{
public:
  Init_RobotMovement_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_SendGoal_Response_stamp accepted(::my_ur_actions::action::RobotMovement_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RobotMovement_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_SendGoal_Response>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_SendGoal_Response_accepted();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_SendGoal_Event_response
{
public:
  explicit Init_RobotMovement_SendGoal_Event_response(::my_ur_actions::action::RobotMovement_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_SendGoal_Event response(::my_ur_actions::action::RobotMovement_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Event msg_;
};

class Init_RobotMovement_SendGoal_Event_request
{
public:
  explicit Init_RobotMovement_SendGoal_Event_request(::my_ur_actions::action::RobotMovement_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_SendGoal_Event_response request(::my_ur_actions::action::RobotMovement_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RobotMovement_SendGoal_Event_response(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Event msg_;
};

class Init_RobotMovement_SendGoal_Event_info
{
public:
  Init_RobotMovement_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_SendGoal_Event_request info(::my_ur_actions::action::RobotMovement_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RobotMovement_SendGoal_Event_request(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_SendGoal_Event>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_SendGoal_Event_info();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_GetResult_Request_goal_id
{
public:
  Init_RobotMovement_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_ur_actions::action::RobotMovement_GetResult_Request goal_id(::my_ur_actions::action::RobotMovement_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_GetResult_Request>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_GetResult_Request_goal_id();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_GetResult_Response_result
{
public:
  explicit Init_RobotMovement_GetResult_Response_result(::my_ur_actions::action::RobotMovement_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_GetResult_Response result(::my_ur_actions::action::RobotMovement_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Response msg_;
};

class Init_RobotMovement_GetResult_Response_status
{
public:
  Init_RobotMovement_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_GetResult_Response_result status(::my_ur_actions::action::RobotMovement_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotMovement_GetResult_Response_result(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_GetResult_Response>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_GetResult_Response_status();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_GetResult_Event_response
{
public:
  explicit Init_RobotMovement_GetResult_Event_response(::my_ur_actions::action::RobotMovement_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_GetResult_Event response(::my_ur_actions::action::RobotMovement_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Event msg_;
};

class Init_RobotMovement_GetResult_Event_request
{
public:
  explicit Init_RobotMovement_GetResult_Event_request(::my_ur_actions::action::RobotMovement_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_RobotMovement_GetResult_Event_response request(::my_ur_actions::action::RobotMovement_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RobotMovement_GetResult_Event_response(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Event msg_;
};

class Init_RobotMovement_GetResult_Event_info
{
public:
  Init_RobotMovement_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_GetResult_Event_request info(::my_ur_actions::action::RobotMovement_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RobotMovement_GetResult_Event_request(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_GetResult_Event>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_GetResult_Event_info();
}

}  // namespace my_ur_actions


namespace my_ur_actions
{

namespace action
{

namespace builder
{

class Init_RobotMovement_FeedbackMessage_feedback
{
public:
  explicit Init_RobotMovement_FeedbackMessage_feedback(::my_ur_actions::action::RobotMovement_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_ur_actions::action::RobotMovement_FeedbackMessage feedback(::my_ur_actions::action::RobotMovement_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_FeedbackMessage msg_;
};

class Init_RobotMovement_FeedbackMessage_goal_id
{
public:
  Init_RobotMovement_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMovement_FeedbackMessage_feedback goal_id(::my_ur_actions::action::RobotMovement_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotMovement_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_ur_actions::action::RobotMovement_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_ur_actions::action::RobotMovement_FeedbackMessage>()
{
  return my_ur_actions::action::builder::Init_RobotMovement_FeedbackMessage_goal_id();
}

}  // namespace my_ur_actions

#endif  // MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__BUILDER_HPP_
