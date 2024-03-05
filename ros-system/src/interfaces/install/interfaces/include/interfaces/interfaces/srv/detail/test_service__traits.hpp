// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/TestService.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/test_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TestService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TestService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TestService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::TestService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::TestService_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::TestService_Request>()
{
  return "interfaces::srv::TestService_Request";
}

template<>
inline const char * name<interfaces::srv::TestService_Request>()
{
  return "interfaces/srv/TestService_Request";
}

template<>
struct has_fixed_size<interfaces::srv::TestService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::TestService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::TestService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TestService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sum
  {
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TestService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TestService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::TestService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::TestService_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::TestService_Response>()
{
  return "interfaces::srv::TestService_Response";
}

template<>
inline const char * name<interfaces::srv::TestService_Response>()
{
  return "interfaces/srv/TestService_Response";
}

template<>
struct has_fixed_size<interfaces::srv::TestService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::TestService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::TestService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::TestService>()
{
  return "interfaces::srv::TestService";
}

template<>
inline const char * name<interfaces::srv::TestService>()
{
  return "interfaces/srv/TestService";
}

template<>
struct has_fixed_size<interfaces::srv::TestService>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::TestService_Request>::value &&
    has_fixed_size<interfaces::srv::TestService_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::TestService>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::TestService_Request>::value &&
    has_bounded_size<interfaces::srv::TestService_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::TestService>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::TestService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::TestService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_
