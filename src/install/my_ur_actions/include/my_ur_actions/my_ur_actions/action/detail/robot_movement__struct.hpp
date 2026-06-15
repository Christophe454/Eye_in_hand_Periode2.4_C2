// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_ur_actions:action/RobotMovement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_ur_actions/action/robot_movement.hpp"


#ifndef MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_HPP_
#define MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_Goal __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_Goal __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_Goal_
{
  using Type = RobotMovement_Goal_<ContainerAllocator>;

  explicit RobotMovement_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->target_x = 0.0;
      this->target_y = 0.0;
      this->target_z = 0.0;
      this->use_camera_target = false;
      this->speed = 0.0;
    }
  }

  explicit RobotMovement_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->target_x = 0.0;
      this->target_y = 0.0;
      this->target_z = 0.0;
      this->use_camera_target = false;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _target_x_type =
    double;
  _target_x_type target_x;
  using _target_y_type =
    double;
  _target_y_type target_y;
  using _target_z_type =
    double;
  _target_z_type target_z;
  using _use_camera_target_type =
    bool;
  _use_camera_target_type use_camera_target;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__target_x(
    const double & _arg)
  {
    this->target_x = _arg;
    return *this;
  }
  Type & set__target_y(
    const double & _arg)
  {
    this->target_y = _arg;
    return *this;
  }
  Type & set__target_z(
    const double & _arg)
  {
    this->target_z = _arg;
    return *this;
  }
  Type & set__use_camera_target(
    const bool & _arg)
  {
    this->use_camera_target = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Goal
    std::shared_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Goal
    std::shared_ptr<my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_Goal_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->target_x != other.target_x) {
      return false;
    }
    if (this->target_y != other.target_y) {
      return false;
    }
    if (this->target_z != other.target_z) {
      return false;
    }
    if (this->use_camera_target != other.use_camera_target) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_Goal_

// alias to use template instance with default allocator
using RobotMovement_Goal =
  my_ur_actions::action::RobotMovement_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_Result __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_Result __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_Result_
{
  using Type = RobotMovement_Result_<ContainerAllocator>;

  explicit RobotMovement_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->final_x = 0.0;
      this->final_y = 0.0;
      this->final_z = 0.0;
    }
  }

  explicit RobotMovement_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->final_x = 0.0;
      this->final_y = 0.0;
      this->final_z = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _final_x_type =
    double;
  _final_x_type final_x;
  using _final_y_type =
    double;
  _final_y_type final_y;
  using _final_z_type =
    double;
  _final_z_type final_z;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__final_x(
    const double & _arg)
  {
    this->final_x = _arg;
    return *this;
  }
  Type & set__final_y(
    const double & _arg)
  {
    this->final_y = _arg;
    return *this;
  }
  Type & set__final_z(
    const double & _arg)
  {
    this->final_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Result
    std::shared_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Result
    std::shared_ptr<my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->final_x != other.final_x) {
      return false;
    }
    if (this->final_y != other.final_y) {
      return false;
    }
    if (this->final_z != other.final_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_Result_

// alias to use template instance with default allocator
using RobotMovement_Result =
  my_ur_actions::action::RobotMovement_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_Feedback __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_Feedback_
{
  using Type = RobotMovement_Feedback_<ContainerAllocator>;

  explicit RobotMovement_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_state = "";
      this->current_x = 0.0;
      this->current_y = 0.0;
      this->current_z = 0.0;
      this->progress = 0.0;
    }
  }

  explicit RobotMovement_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_state = "";
      this->current_x = 0.0;
      this->current_y = 0.0;
      this->current_z = 0.0;
      this->progress = 0.0;
    }
  }

  // field types and members
  using _current_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_state_type current_state;
  using _current_x_type =
    double;
  _current_x_type current_x;
  using _current_y_type =
    double;
  _current_y_type current_y;
  using _current_z_type =
    double;
  _current_z_type current_z;
  using _progress_type =
    double;
  _progress_type progress;

  // setters for named parameter idiom
  Type & set__current_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_state = _arg;
    return *this;
  }
  Type & set__current_x(
    const double & _arg)
  {
    this->current_x = _arg;
    return *this;
  }
  Type & set__current_y(
    const double & _arg)
  {
    this->current_y = _arg;
    return *this;
  }
  Type & set__current_z(
    const double & _arg)
  {
    this->current_z = _arg;
    return *this;
  }
  Type & set__progress(
    const double & _arg)
  {
    this->progress = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Feedback
    std::shared_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_Feedback
    std::shared_ptr<my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_Feedback_ & other) const
  {
    if (this->current_state != other.current_state) {
      return false;
    }
    if (this->current_x != other.current_x) {
      return false;
    }
    if (this->current_y != other.current_y) {
      return false;
    }
    if (this->current_z != other.current_z) {
      return false;
    }
    if (this->progress != other.progress) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_Feedback_

// alias to use template instance with default allocator
using RobotMovement_Feedback =
  my_ur_actions::action::RobotMovement_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "my_ur_actions/action/detail/robot_movement__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Request __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_SendGoal_Request_
{
  using Type = RobotMovement_SendGoal_Request_<ContainerAllocator>;

  explicit RobotMovement_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit RobotMovement_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const my_ur_actions::action::RobotMovement_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Request
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Request
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_SendGoal_Request_

// alias to use template instance with default allocator
using RobotMovement_SendGoal_Request =
  my_ur_actions::action::RobotMovement_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Response __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_SendGoal_Response_
{
  using Type = RobotMovement_SendGoal_Response_<ContainerAllocator>;

  explicit RobotMovement_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit RobotMovement_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Response
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Response
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_SendGoal_Response_

// alias to use template instance with default allocator
using RobotMovement_SendGoal_Response =
  my_ur_actions::action::RobotMovement_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Event __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_SendGoal_Event_
{
  using Type = RobotMovement_SendGoal_Event_<ContainerAllocator>;

  explicit RobotMovement_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RobotMovement_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Event
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_SendGoal_Event
    std::shared_ptr<my_ur_actions::action::RobotMovement_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_SendGoal_Event_

// alias to use template instance with default allocator
using RobotMovement_SendGoal_Event =
  my_ur_actions::action::RobotMovement_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions

namespace my_ur_actions
{

namespace action
{

struct RobotMovement_SendGoal
{
  using Request = my_ur_actions::action::RobotMovement_SendGoal_Request;
  using Response = my_ur_actions::action::RobotMovement_SendGoal_Response;
  using Event = my_ur_actions::action::RobotMovement_SendGoal_Event;
};

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Request __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_GetResult_Request_
{
  using Type = RobotMovement_GetResult_Request_<ContainerAllocator>;

  explicit RobotMovement_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit RobotMovement_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Request
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Request
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_GetResult_Request_

// alias to use template instance with default allocator
using RobotMovement_GetResult_Request =
  my_ur_actions::action::RobotMovement_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'result'
// already included above
// #include "my_ur_actions/action/detail/robot_movement__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Response __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_GetResult_Response_
{
  using Type = RobotMovement_GetResult_Response_<ContainerAllocator>;

  explicit RobotMovement_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit RobotMovement_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    my_ur_actions::action::RobotMovement_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const my_ur_actions::action::RobotMovement_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Response
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Response
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_GetResult_Response_

// alias to use template instance with default allocator
using RobotMovement_GetResult_Response =
  my_ur_actions::action::RobotMovement_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Event __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_GetResult_Event_
{
  using Type = RobotMovement_GetResult_Event_<ContainerAllocator>;

  explicit RobotMovement_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RobotMovement_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_ur_actions::action::RobotMovement_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Event
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_GetResult_Event
    std::shared_ptr<my_ur_actions::action::RobotMovement_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_GetResult_Event_

// alias to use template instance with default allocator
using RobotMovement_GetResult_Event =
  my_ur_actions::action::RobotMovement_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions

namespace my_ur_actions
{

namespace action
{

struct RobotMovement_GetResult
{
  using Request = my_ur_actions::action::RobotMovement_GetResult_Request;
  using Response = my_ur_actions::action::RobotMovement_GetResult_Response;
  using Event = my_ur_actions::action::RobotMovement_GetResult_Event;
};

}  // namespace action

}  // namespace my_ur_actions


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "my_ur_actions/action/detail/robot_movement__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_ur_actions__action__RobotMovement_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__my_ur_actions__action__RobotMovement_FeedbackMessage __declspec(deprecated)
#endif

namespace my_ur_actions
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotMovement_FeedbackMessage_
{
  using Type = RobotMovement_FeedbackMessage_<ContainerAllocator>;

  explicit RobotMovement_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit RobotMovement_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const my_ur_actions::action::RobotMovement_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_FeedbackMessage
    std::shared_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_ur_actions__action__RobotMovement_FeedbackMessage
    std::shared_ptr<my_ur_actions::action::RobotMovement_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMovement_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMovement_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMovement_FeedbackMessage_

// alias to use template instance with default allocator
using RobotMovement_FeedbackMessage =
  my_ur_actions::action::RobotMovement_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_ur_actions

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace my_ur_actions
{

namespace action
{

struct RobotMovement
{
  /// The goal message defined in the action definition.
  using Goal = my_ur_actions::action::RobotMovement_Goal;
  /// The result message defined in the action definition.
  using Result = my_ur_actions::action::RobotMovement_Result;
  /// The feedback message defined in the action definition.
  using Feedback = my_ur_actions::action::RobotMovement_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = my_ur_actions::action::RobotMovement_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = my_ur_actions::action::RobotMovement_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = my_ur_actions::action::RobotMovement_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct RobotMovement RobotMovement;

}  // namespace action

}  // namespace my_ur_actions

#endif  // MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__STRUCT_HPP_
