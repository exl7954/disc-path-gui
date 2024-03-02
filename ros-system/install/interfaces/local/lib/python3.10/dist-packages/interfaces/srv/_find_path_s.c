// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "interfaces/srv/detail/find_path__struct.h"
#include "interfaces/srv/detail/find_path__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool interfaces__srv__find_path__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("interfaces.srv._find_path.FindPath_Request", full_classname_dest, 42) == 0);
  }
  interfaces__srv__FindPath_Request * ros_message = _ros_message;
  {  // alpha
    PyObject * field = PyObject_GetAttrString(_pymsg, "alpha");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 2;
      double * dest = ros_message->alpha;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // bta
    PyObject * field = PyObject_GetAttrString(_pymsg, "bta");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 2;
      double * dest = ros_message->bta;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // epsilon
    PyObject * field = PyObject_GetAttrString(_pymsg, "epsilon");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->epsilon = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // boxwidth
    PyObject * field = PyObject_GetAttrString(_pymsg, "boxwidth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->boxwidth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // boxheight
    PyObject * field = PyObject_GetAttrString(_pymsg, "boxheight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->boxheight = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // r0
    PyObject * field = PyObject_GetAttrString(_pymsg, "r0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->r0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // qtype
    PyObject * field = PyObject_GetAttrString(_pymsg, "qtype");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->qtype = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // seed
    PyObject * field = PyObject_GetAttrString(_pymsg, "seed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seed = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // deltax
    PyObject * field = PyObject_GetAttrString(_pymsg, "deltax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->deltax = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // deltay
    PyObject * field = PyObject_GetAttrString(_pymsg, "deltay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->deltay = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // scale
    PyObject * field = PyObject_GetAttrString(_pymsg, "scale");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->scale = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // numpts
    PyObject * field = PyObject_GetAttrString(_pymsg, "numpts");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->numpts = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // pts
    PyObject * field = PyObject_GetAttrString(_pymsg, "pts");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->pts, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // numpolygons
    PyObject * field = PyObject_GetAttrString(_pymsg, "numpolygons");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->numpolygons = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // polygons
    PyObject * field = PyObject_GetAttrString(_pymsg, "polygons");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->polygons, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interfaces__srv__find_path__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FindPath_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interfaces.srv._find_path");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FindPath_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interfaces__srv__FindPath_Request * ros_message = (interfaces__srv__FindPath_Request *)raw_ros_message;
  {  // alpha
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "alpha");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->alpha[0]);
    memcpy(dst, src, 2 * sizeof(double));
    Py_DECREF(field);
  }
  {  // bta
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "bta");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->bta[0]);
    memcpy(dst, src, 2 * sizeof(double));
    Py_DECREF(field);
  }
  {  // epsilon
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->epsilon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "epsilon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // boxwidth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->boxwidth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "boxwidth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // boxheight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->boxheight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "boxheight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->r0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "r0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // qtype
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->qtype);
    {
      int rc = PyObject_SetAttrString(_pymessage, "qtype", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // seed
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->seed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deltax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->deltax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "deltax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deltay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->deltay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "deltay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scale
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->scale);
    {
      int rc = PyObject_SetAttrString(_pymessage, "scale", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // numpts
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->numpts);
    {
      int rc = PyObject_SetAttrString(_pymessage, "numpts", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pts
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->pts.data,
      strlen(ros_message->pts.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pts", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // numpolygons
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->numpolygons);
    {
      int rc = PyObject_SetAttrString(_pymessage, "numpolygons", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // polygons
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->polygons.data,
      strlen(ros_message->polygons.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "polygons", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "interfaces/srv/detail/find_path__struct.h"
// already included above
// #include "interfaces/srv/detail/find_path__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool interfaces__srv__find_path__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("interfaces.srv._find_path.FindPath_Response", full_classname_dest, 43) == 0);
  }
  interfaces__srv__FindPath_Response * ros_message = _ros_message;
  {  // response
    PyObject * field = PyObject_GetAttrString(_pymsg, "response");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->response, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interfaces__srv__find_path__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FindPath_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interfaces.srv._find_path");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FindPath_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interfaces__srv__FindPath_Response * ros_message = (interfaces__srv__FindPath_Response *)raw_ros_message;
  {  // response
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->response.data,
      strlen(ros_message->response.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "response", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
