// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_H_
#define INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pts'
// Member 'polygons'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FindPath in the package interfaces.
typedef struct interfaces__srv__FindPath_Request
{
  double alpha[2];
  double bta[2];
  double epsilon;
  double boxwidth;
  double boxheight;
  double r0;
  int64_t qtype;
  int64_t seed;
  double deltax;
  double deltay;
  double scale;
  int64_t numpts;
  rosidl_runtime_c__String pts;
  int64_t numpolygons;
  rosidl_runtime_c__String polygons;
} interfaces__srv__FindPath_Request;

// Struct for a sequence of interfaces__srv__FindPath_Request.
typedef struct interfaces__srv__FindPath_Request__Sequence
{
  interfaces__srv__FindPath_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FindPath_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
// Member 'path'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FindPath in the package interfaces.
typedef struct interfaces__srv__FindPath_Response
{
  rosidl_runtime_c__String response;
  rosidl_runtime_c__String path;
} interfaces__srv__FindPath_Response;

// Struct for a sequence of interfaces__srv__FindPath_Response.
typedef struct interfaces__srv__FindPath_Response__Sequence
{
  interfaces__srv__FindPath_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FindPath_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_H_
