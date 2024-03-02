// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_PATH__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__FIND_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/find_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindPath_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: alpha
  {
    if (msg.alpha.size() == 0) {
      out << "alpha: []";
    } else {
      out << "alpha: [";
      size_t pending_items = msg.alpha.size();
      for (auto item : msg.alpha) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bta
  {
    if (msg.bta.size() == 0) {
      out << "bta: []";
    } else {
      out << "bta: [";
      size_t pending_items = msg.bta.size();
      for (auto item : msg.bta) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: epsilon
  {
    out << "epsilon: ";
    rosidl_generator_traits::value_to_yaml(msg.epsilon, out);
    out << ", ";
  }

  // member: boxwidth
  {
    out << "boxwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.boxwidth, out);
    out << ", ";
  }

  // member: boxheight
  {
    out << "boxheight: ";
    rosidl_generator_traits::value_to_yaml(msg.boxheight, out);
    out << ", ";
  }

  // member: r0
  {
    out << "r0: ";
    rosidl_generator_traits::value_to_yaml(msg.r0, out);
    out << ", ";
  }

  // member: qtype
  {
    out << "qtype: ";
    rosidl_generator_traits::value_to_yaml(msg.qtype, out);
    out << ", ";
  }

  // member: seed
  {
    out << "seed: ";
    rosidl_generator_traits::value_to_yaml(msg.seed, out);
    out << ", ";
  }

  // member: deltax
  {
    out << "deltax: ";
    rosidl_generator_traits::value_to_yaml(msg.deltax, out);
    out << ", ";
  }

  // member: deltay
  {
    out << "deltay: ";
    rosidl_generator_traits::value_to_yaml(msg.deltay, out);
    out << ", ";
  }

  // member: scale
  {
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << ", ";
  }

  // member: numpts
  {
    out << "numpts: ";
    rosidl_generator_traits::value_to_yaml(msg.numpts, out);
    out << ", ";
  }

  // member: pts
  {
    out << "pts: ";
    rosidl_generator_traits::value_to_yaml(msg.pts, out);
    out << ", ";
  }

  // member: numpolygons
  {
    out << "numpolygons: ";
    rosidl_generator_traits::value_to_yaml(msg.numpolygons, out);
    out << ", ";
  }

  // member: polygons
  {
    out << "polygons: ";
    rosidl_generator_traits::value_to_yaml(msg.polygons, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindPath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.alpha.size() == 0) {
      out << "alpha: []\n";
    } else {
      out << "alpha:\n";
      for (auto item : msg.alpha) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bta.size() == 0) {
      out << "bta: []\n";
    } else {
      out << "bta:\n";
      for (auto item : msg.bta) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: epsilon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "epsilon: ";
    rosidl_generator_traits::value_to_yaml(msg.epsilon, out);
    out << "\n";
  }

  // member: boxwidth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "boxwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.boxwidth, out);
    out << "\n";
  }

  // member: boxheight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "boxheight: ";
    rosidl_generator_traits::value_to_yaml(msg.boxheight, out);
    out << "\n";
  }

  // member: r0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r0: ";
    rosidl_generator_traits::value_to_yaml(msg.r0, out);
    out << "\n";
  }

  // member: qtype
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "qtype: ";
    rosidl_generator_traits::value_to_yaml(msg.qtype, out);
    out << "\n";
  }

  // member: seed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seed: ";
    rosidl_generator_traits::value_to_yaml(msg.seed, out);
    out << "\n";
  }

  // member: deltax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deltax: ";
    rosidl_generator_traits::value_to_yaml(msg.deltax, out);
    out << "\n";
  }

  // member: deltay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deltay: ";
    rosidl_generator_traits::value_to_yaml(msg.deltay, out);
    out << "\n";
  }

  // member: scale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scale: ";
    rosidl_generator_traits::value_to_yaml(msg.scale, out);
    out << "\n";
  }

  // member: numpts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "numpts: ";
    rosidl_generator_traits::value_to_yaml(msg.numpts, out);
    out << "\n";
  }

  // member: pts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pts: ";
    rosidl_generator_traits::value_to_yaml(msg.pts, out);
    out << "\n";
  }

  // member: numpolygons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "numpolygons: ";
    rosidl_generator_traits::value_to_yaml(msg.numpolygons, out);
    out << "\n";
  }

  // member: polygons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polygons: ";
    rosidl_generator_traits::value_to_yaml(msg.polygons, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindPath_Request & msg, bool use_flow_style = false)
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
  const interfaces::srv::FindPath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::FindPath_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::FindPath_Request>()
{
  return "interfaces::srv::FindPath_Request";
}

template<>
inline const char * name<interfaces::srv::FindPath_Request>()
{
  return "interfaces/srv/FindPath_Request";
}

template<>
struct has_fixed_size<interfaces::srv::FindPath_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::FindPath_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::FindPath_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindPath_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindPath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindPath_Response & msg, bool use_flow_style = false)
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
  const interfaces::srv::FindPath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::FindPath_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::FindPath_Response>()
{
  return "interfaces::srv::FindPath_Response";
}

template<>
inline const char * name<interfaces::srv::FindPath_Response>()
{
  return "interfaces/srv/FindPath_Response";
}

template<>
struct has_fixed_size<interfaces::srv::FindPath_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::FindPath_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::FindPath_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::FindPath>()
{
  return "interfaces::srv::FindPath";
}

template<>
inline const char * name<interfaces::srv::FindPath>()
{
  return "interfaces/srv/FindPath";
}

template<>
struct has_fixed_size<interfaces::srv::FindPath>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::FindPath_Request>::value &&
    has_fixed_size<interfaces::srv::FindPath_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::FindPath>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::FindPath_Request>::value &&
    has_bounded_size<interfaces::srv::FindPath_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::FindPath>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::FindPath_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::FindPath_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__FIND_PATH__TRAITS_HPP_
