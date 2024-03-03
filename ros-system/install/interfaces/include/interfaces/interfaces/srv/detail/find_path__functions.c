// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice
#include "interfaces/srv/detail/find_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pts`
// Member `polygons`
#include "rosidl_runtime_c/string_functions.h"

bool
interfaces__srv__FindPath_Request__init(interfaces__srv__FindPath_Request * msg)
{
  if (!msg) {
    return false;
  }
  // alpha
  msg->alpha[0] = 10.0l;
  msg->alpha[1] = 360.0l;
  // bta
  msg->bta[0] = 500.0l;
  msg->bta[1] = 20.0l;
  // epsilon
  msg->epsilon = 1.0l;
  // boxwidth
  msg->boxwidth = 512.0l;
  // boxheight
  msg->boxheight = 512.0l;
  // r0
  msg->r0 = 30.0l;
  // qtype
  msg->qtype = 0ll;
  // seed
  msg->seed = 111ll;
  // deltax
  msg->deltax = 0.0l;
  // deltay
  msg->deltay = 0.0l;
  // scale
  msg->scale = 1.0l;
  // numpts
  msg->numpts = 12ll;
  // pts
  if (!rosidl_runtime_c__String__init(&msg->pts)) {
    interfaces__srv__FindPath_Request__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->pts, "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92");
    if (!success) {
      goto abort_init_0;
    }
  }
  // numpolygons
  msg->numpolygons = 3ll;
  // polygons
  if (!rosidl_runtime_c__String__init(&msg->polygons)) {
    interfaces__srv__FindPath_Request__fini(msg);
    return false;
  }
  {
    bool success = rosidl_runtime_c__String__assign(&msg->polygons, "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10");
    if (!success) {
      goto abort_init_1;
    }
  }
  return true;
abort_init_1:
  rosidl_runtime_c__String__fini(&msg->pts);
abort_init_0:
  return false;
}

void
interfaces__srv__FindPath_Request__fini(interfaces__srv__FindPath_Request * msg)
{
  if (!msg) {
    return;
  }
  // alpha
  // bta
  // epsilon
  // boxwidth
  // boxheight
  // r0
  // qtype
  // seed
  // deltax
  // deltay
  // scale
  // numpts
  // pts
  rosidl_runtime_c__String__fini(&msg->pts);
  // numpolygons
  // polygons
  rosidl_runtime_c__String__fini(&msg->polygons);
}

bool
interfaces__srv__FindPath_Request__are_equal(const interfaces__srv__FindPath_Request * lhs, const interfaces__srv__FindPath_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alpha
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->alpha[i] != rhs->alpha[i]) {
      return false;
    }
  }
  // bta
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->bta[i] != rhs->bta[i]) {
      return false;
    }
  }
  // epsilon
  if (lhs->epsilon != rhs->epsilon) {
    return false;
  }
  // boxwidth
  if (lhs->boxwidth != rhs->boxwidth) {
    return false;
  }
  // boxheight
  if (lhs->boxheight != rhs->boxheight) {
    return false;
  }
  // r0
  if (lhs->r0 != rhs->r0) {
    return false;
  }
  // qtype
  if (lhs->qtype != rhs->qtype) {
    return false;
  }
  // seed
  if (lhs->seed != rhs->seed) {
    return false;
  }
  // deltax
  if (lhs->deltax != rhs->deltax) {
    return false;
  }
  // deltay
  if (lhs->deltay != rhs->deltay) {
    return false;
  }
  // scale
  if (lhs->scale != rhs->scale) {
    return false;
  }
  // numpts
  if (lhs->numpts != rhs->numpts) {
    return false;
  }
  // pts
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pts), &(rhs->pts)))
  {
    return false;
  }
  // numpolygons
  if (lhs->numpolygons != rhs->numpolygons) {
    return false;
  }
  // polygons
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->polygons), &(rhs->polygons)))
  {
    return false;
  }
  return true;
}

bool
interfaces__srv__FindPath_Request__copy(
  const interfaces__srv__FindPath_Request * input,
  interfaces__srv__FindPath_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // alpha
  for (size_t i = 0; i < 2; ++i) {
    output->alpha[i] = input->alpha[i];
  }
  // bta
  for (size_t i = 0; i < 2; ++i) {
    output->bta[i] = input->bta[i];
  }
  // epsilon
  output->epsilon = input->epsilon;
  // boxwidth
  output->boxwidth = input->boxwidth;
  // boxheight
  output->boxheight = input->boxheight;
  // r0
  output->r0 = input->r0;
  // qtype
  output->qtype = input->qtype;
  // seed
  output->seed = input->seed;
  // deltax
  output->deltax = input->deltax;
  // deltay
  output->deltay = input->deltay;
  // scale
  output->scale = input->scale;
  // numpts
  output->numpts = input->numpts;
  // pts
  if (!rosidl_runtime_c__String__copy(
      &(input->pts), &(output->pts)))
  {
    return false;
  }
  // numpolygons
  output->numpolygons = input->numpolygons;
  // polygons
  if (!rosidl_runtime_c__String__copy(
      &(input->polygons), &(output->polygons)))
  {
    return false;
  }
  return true;
}

interfaces__srv__FindPath_Request *
interfaces__srv__FindPath_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Request * msg = (interfaces__srv__FindPath_Request *)allocator.allocate(sizeof(interfaces__srv__FindPath_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__FindPath_Request));
  bool success = interfaces__srv__FindPath_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__FindPath_Request__destroy(interfaces__srv__FindPath_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__srv__FindPath_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__srv__FindPath_Request__Sequence__init(interfaces__srv__FindPath_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Request * data = NULL;

  if (size) {
    data = (interfaces__srv__FindPath_Request *)allocator.zero_allocate(size, sizeof(interfaces__srv__FindPath_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__FindPath_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__FindPath_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__srv__FindPath_Request__Sequence__fini(interfaces__srv__FindPath_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__FindPath_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__srv__FindPath_Request__Sequence *
interfaces__srv__FindPath_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Request__Sequence * array = (interfaces__srv__FindPath_Request__Sequence *)allocator.allocate(sizeof(interfaces__srv__FindPath_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__FindPath_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__srv__FindPath_Request__Sequence__destroy(interfaces__srv__FindPath_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__srv__FindPath_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__srv__FindPath_Request__Sequence__are_equal(const interfaces__srv__FindPath_Request__Sequence * lhs, const interfaces__srv__FindPath_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__FindPath_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__FindPath_Request__Sequence__copy(
  const interfaces__srv__FindPath_Request__Sequence * input,
  interfaces__srv__FindPath_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__FindPath_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__srv__FindPath_Request * data =
      (interfaces__srv__FindPath_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__FindPath_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__srv__FindPath_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__srv__FindPath_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
// Member `path`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
interfaces__srv__FindPath_Response__init(interfaces__srv__FindPath_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    interfaces__srv__FindPath_Response__fini(msg);
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__init(&msg->path)) {
    interfaces__srv__FindPath_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__srv__FindPath_Response__fini(interfaces__srv__FindPath_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
  // path
  rosidl_runtime_c__String__fini(&msg->path);
}

bool
interfaces__srv__FindPath_Response__are_equal(const interfaces__srv__FindPath_Response * lhs, const interfaces__srv__FindPath_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  return true;
}

bool
interfaces__srv__FindPath_Response__copy(
  const interfaces__srv__FindPath_Response * input,
  interfaces__srv__FindPath_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  return true;
}

interfaces__srv__FindPath_Response *
interfaces__srv__FindPath_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Response * msg = (interfaces__srv__FindPath_Response *)allocator.allocate(sizeof(interfaces__srv__FindPath_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__srv__FindPath_Response));
  bool success = interfaces__srv__FindPath_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__srv__FindPath_Response__destroy(interfaces__srv__FindPath_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__srv__FindPath_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__srv__FindPath_Response__Sequence__init(interfaces__srv__FindPath_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Response * data = NULL;

  if (size) {
    data = (interfaces__srv__FindPath_Response *)allocator.zero_allocate(size, sizeof(interfaces__srv__FindPath_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__srv__FindPath_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__srv__FindPath_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__srv__FindPath_Response__Sequence__fini(interfaces__srv__FindPath_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__srv__FindPath_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__srv__FindPath_Response__Sequence *
interfaces__srv__FindPath_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__srv__FindPath_Response__Sequence * array = (interfaces__srv__FindPath_Response__Sequence *)allocator.allocate(sizeof(interfaces__srv__FindPath_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__srv__FindPath_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__srv__FindPath_Response__Sequence__destroy(interfaces__srv__FindPath_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__srv__FindPath_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__srv__FindPath_Response__Sequence__are_equal(const interfaces__srv__FindPath_Response__Sequence * lhs, const interfaces__srv__FindPath_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__srv__FindPath_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__srv__FindPath_Response__Sequence__copy(
  const interfaces__srv__FindPath_Response__Sequence * input,
  interfaces__srv__FindPath_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__srv__FindPath_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__srv__FindPath_Response * data =
      (interfaces__srv__FindPath_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__srv__FindPath_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__srv__FindPath_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__srv__FindPath_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
