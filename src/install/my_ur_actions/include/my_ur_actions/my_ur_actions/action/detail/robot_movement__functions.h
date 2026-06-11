// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_ur_actions:action/RobotMovement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_ur_actions/action/robot_movement.h"


#ifndef MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__FUNCTIONS_H_
#define MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "my_ur_actions/msg/rosidl_generator_c__visibility_control.h"

#include "my_ur_actions/action/detail/robot_movement__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement__get_type_hash(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement__get_type_description(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement__get_individual_type_description_source(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement__get_type_description_sources(
  const rosidl_action_type_support_t * type_support);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_Goal
 * )) before or use
 * my_ur_actions__action__RobotMovement_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__init(my_ur_actions__action__RobotMovement_Goal * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Goal__fini(my_ur_actions__action__RobotMovement_Goal * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Goal *
my_ur_actions__action__RobotMovement_Goal__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Goal__destroy(my_ur_actions__action__RobotMovement_Goal * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__are_equal(const my_ur_actions__action__RobotMovement_Goal * lhs, const my_ur_actions__action__RobotMovement_Goal * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__copy(
  const my_ur_actions__action__RobotMovement_Goal * input,
  my_ur_actions__action__RobotMovement_Goal * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_Goal__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_Goal__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_Goal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_Goal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__Sequence__init(my_ur_actions__action__RobotMovement_Goal__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Goal__Sequence__fini(my_ur_actions__action__RobotMovement_Goal__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Goal__Sequence *
my_ur_actions__action__RobotMovement_Goal__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Goal__Sequence__destroy(my_ur_actions__action__RobotMovement_Goal__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__Sequence__are_equal(const my_ur_actions__action__RobotMovement_Goal__Sequence * lhs, const my_ur_actions__action__RobotMovement_Goal__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Goal__Sequence__copy(
  const my_ur_actions__action__RobotMovement_Goal__Sequence * input,
  my_ur_actions__action__RobotMovement_Goal__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_Result
 * )) before or use
 * my_ur_actions__action__RobotMovement_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__init(my_ur_actions__action__RobotMovement_Result * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Result__fini(my_ur_actions__action__RobotMovement_Result * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Result *
my_ur_actions__action__RobotMovement_Result__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Result__destroy(my_ur_actions__action__RobotMovement_Result * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__are_equal(const my_ur_actions__action__RobotMovement_Result * lhs, const my_ur_actions__action__RobotMovement_Result * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__copy(
  const my_ur_actions__action__RobotMovement_Result * input,
  my_ur_actions__action__RobotMovement_Result * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_Result__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_Result__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_Result__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_Result__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__Sequence__init(my_ur_actions__action__RobotMovement_Result__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Result__Sequence__fini(my_ur_actions__action__RobotMovement_Result__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Result__Sequence *
my_ur_actions__action__RobotMovement_Result__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Result__Sequence__destroy(my_ur_actions__action__RobotMovement_Result__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__Sequence__are_equal(const my_ur_actions__action__RobotMovement_Result__Sequence * lhs, const my_ur_actions__action__RobotMovement_Result__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Result__Sequence__copy(
  const my_ur_actions__action__RobotMovement_Result__Sequence * input,
  my_ur_actions__action__RobotMovement_Result__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_Feedback
 * )) before or use
 * my_ur_actions__action__RobotMovement_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__init(my_ur_actions__action__RobotMovement_Feedback * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Feedback__fini(my_ur_actions__action__RobotMovement_Feedback * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Feedback *
my_ur_actions__action__RobotMovement_Feedback__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Feedback__destroy(my_ur_actions__action__RobotMovement_Feedback * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__are_equal(const my_ur_actions__action__RobotMovement_Feedback * lhs, const my_ur_actions__action__RobotMovement_Feedback * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__copy(
  const my_ur_actions__action__RobotMovement_Feedback * input,
  my_ur_actions__action__RobotMovement_Feedback * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_Feedback__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_Feedback__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_Feedback__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_Feedback__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__Sequence__init(my_ur_actions__action__RobotMovement_Feedback__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Feedback__Sequence__fini(my_ur_actions__action__RobotMovement_Feedback__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_Feedback__Sequence *
my_ur_actions__action__RobotMovement_Feedback__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_Feedback__Sequence__destroy(my_ur_actions__action__RobotMovement_Feedback__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__Sequence__are_equal(const my_ur_actions__action__RobotMovement_Feedback__Sequence * lhs, const my_ur_actions__action__RobotMovement_Feedback__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_Feedback__Sequence__copy(
  const my_ur_actions__action__RobotMovement_Feedback__Sequence * input,
  my_ur_actions__action__RobotMovement_Feedback__Sequence * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_SendGoal__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_SendGoal__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_SendGoal__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_SendGoal__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_SendGoal_Request
 * )) before or use
 * my_ur_actions__action__RobotMovement_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__init(my_ur_actions__action__RobotMovement_SendGoal_Request * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Request__fini(my_ur_actions__action__RobotMovement_SendGoal_Request * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Request *
my_ur_actions__action__RobotMovement_SendGoal_Request__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Request__destroy(my_ur_actions__action__RobotMovement_SendGoal_Request * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Request * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Request * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Request * input,
  my_ur_actions__action__RobotMovement_SendGoal_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_SendGoal_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_SendGoal_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_SendGoal_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__init(my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__fini(my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__destroy(my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * input,
  my_ur_actions__action__RobotMovement_SendGoal_Request__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_SendGoal_Response
 * )) before or use
 * my_ur_actions__action__RobotMovement_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__init(my_ur_actions__action__RobotMovement_SendGoal_Response * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Response__fini(my_ur_actions__action__RobotMovement_SendGoal_Response * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Response *
my_ur_actions__action__RobotMovement_SendGoal_Response__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Response__destroy(my_ur_actions__action__RobotMovement_SendGoal_Response * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Response * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Response * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Response * input,
  my_ur_actions__action__RobotMovement_SendGoal_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_SendGoal_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_SendGoal_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_SendGoal_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__init(my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__fini(my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__destroy(my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * input,
  my_ur_actions__action__RobotMovement_SendGoal_Response__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_SendGoal_Event
 * )) before or use
 * my_ur_actions__action__RobotMovement_SendGoal_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__init(my_ur_actions__action__RobotMovement_SendGoal_Event * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Event__fini(my_ur_actions__action__RobotMovement_SendGoal_Event * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Event *
my_ur_actions__action__RobotMovement_SendGoal_Event__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Event__destroy(my_ur_actions__action__RobotMovement_SendGoal_Event * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Event * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Event * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Event * input,
  my_ur_actions__action__RobotMovement_SendGoal_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_SendGoal_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_SendGoal_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_SendGoal_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__init(my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__fini(my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence *
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__destroy(my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__are_equal(const my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * lhs, const my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence__copy(
  const my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * input,
  my_ur_actions__action__RobotMovement_SendGoal_Event__Sequence * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_GetResult__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_GetResult__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_GetResult__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_GetResult__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_GetResult_Request
 * )) before or use
 * my_ur_actions__action__RobotMovement_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__init(my_ur_actions__action__RobotMovement_GetResult_Request * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Request__fini(my_ur_actions__action__RobotMovement_GetResult_Request * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Request *
my_ur_actions__action__RobotMovement_GetResult_Request__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Request__destroy(my_ur_actions__action__RobotMovement_GetResult_Request * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Request * lhs, const my_ur_actions__action__RobotMovement_GetResult_Request * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Request * input,
  my_ur_actions__action__RobotMovement_GetResult_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_GetResult_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_GetResult_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_GetResult_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__init(my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__fini(my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__destroy(my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * lhs, const my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Request__Sequence__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * input,
  my_ur_actions__action__RobotMovement_GetResult_Request__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_GetResult_Response
 * )) before or use
 * my_ur_actions__action__RobotMovement_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__init(my_ur_actions__action__RobotMovement_GetResult_Response * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Response__fini(my_ur_actions__action__RobotMovement_GetResult_Response * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Response *
my_ur_actions__action__RobotMovement_GetResult_Response__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Response__destroy(my_ur_actions__action__RobotMovement_GetResult_Response * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Response * lhs, const my_ur_actions__action__RobotMovement_GetResult_Response * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Response * input,
  my_ur_actions__action__RobotMovement_GetResult_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_GetResult_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_GetResult_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_GetResult_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__init(my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__fini(my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__destroy(my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * lhs, const my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Response__Sequence__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * input,
  my_ur_actions__action__RobotMovement_GetResult_Response__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_GetResult_Event
 * )) before or use
 * my_ur_actions__action__RobotMovement_GetResult_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__init(my_ur_actions__action__RobotMovement_GetResult_Event * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Event__fini(my_ur_actions__action__RobotMovement_GetResult_Event * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Event *
my_ur_actions__action__RobotMovement_GetResult_Event__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Event__destroy(my_ur_actions__action__RobotMovement_GetResult_Event * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Event * lhs, const my_ur_actions__action__RobotMovement_GetResult_Event * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Event * input,
  my_ur_actions__action__RobotMovement_GetResult_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_GetResult_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_GetResult_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_GetResult_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__init(my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__fini(my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence *
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__destroy(my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__are_equal(const my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * lhs, const my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_GetResult_Event__Sequence__copy(
  const my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * input,
  my_ur_actions__action__RobotMovement_GetResult_Event__Sequence * output);

/// Initialize action/RobotMovement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_ur_actions__action__RobotMovement_FeedbackMessage
 * )) before or use
 * my_ur_actions__action__RobotMovement_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__init(my_ur_actions__action__RobotMovement_FeedbackMessage * msg);

/// Finalize action/RobotMovement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_FeedbackMessage__fini(my_ur_actions__action__RobotMovement_FeedbackMessage * msg);

/// Create action/RobotMovement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_FeedbackMessage *
my_ur_actions__action__RobotMovement_FeedbackMessage__create(void);

/// Destroy action/RobotMovement message.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_FeedbackMessage__destroy(my_ur_actions__action__RobotMovement_FeedbackMessage * msg);

/// Check for action/RobotMovement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__are_equal(const my_ur_actions__action__RobotMovement_FeedbackMessage * lhs, const my_ur_actions__action__RobotMovement_FeedbackMessage * rhs);

/// Copy a action/RobotMovement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__copy(
  const my_ur_actions__action__RobotMovement_FeedbackMessage * input,
  my_ur_actions__action__RobotMovement_FeedbackMessage * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_type_hash_t *
my_ur_actions__action__RobotMovement_FeedbackMessage__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeDescription *
my_ur_actions__action__RobotMovement_FeedbackMessage__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource *
my_ur_actions__action__RobotMovement_FeedbackMessage__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_ur_actions__action__RobotMovement_FeedbackMessage__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/RobotMovement messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__init(my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__fini(my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * array);

/// Create array of action/RobotMovement messages.
/**
 * It allocates the memory for the array and calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence *
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/RobotMovement messages.
/**
 * It calls
 * my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
void
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__destroy(my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * array);

/// Check for action/RobotMovement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__are_equal(const my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * lhs, const my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/RobotMovement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_ur_actions
bool
my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence__copy(
  const my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * input,
  my_ur_actions__action__RobotMovement_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_UR_ACTIONS__ACTION__DETAIL__ROBOT_MOVEMENT__FUNCTIONS_H_
