// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_PATH__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__FIND_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/find_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_FindPath_Request_polygons
{
public:
  explicit Init_FindPath_Request_polygons(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::FindPath_Request polygons(::interfaces::srv::FindPath_Request::_polygons_type arg)
  {
    msg_.polygons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_numpolygons
{
public:
  explicit Init_FindPath_Request_numpolygons(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_polygons numpolygons(::interfaces::srv::FindPath_Request::_numpolygons_type arg)
  {
    msg_.numpolygons = std::move(arg);
    return Init_FindPath_Request_polygons(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_pts
{
public:
  explicit Init_FindPath_Request_pts(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_numpolygons pts(::interfaces::srv::FindPath_Request::_pts_type arg)
  {
    msg_.pts = std::move(arg);
    return Init_FindPath_Request_numpolygons(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_numpts
{
public:
  explicit Init_FindPath_Request_numpts(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_pts numpts(::interfaces::srv::FindPath_Request::_numpts_type arg)
  {
    msg_.numpts = std::move(arg);
    return Init_FindPath_Request_pts(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_scale
{
public:
  explicit Init_FindPath_Request_scale(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_numpts scale(::interfaces::srv::FindPath_Request::_scale_type arg)
  {
    msg_.scale = std::move(arg);
    return Init_FindPath_Request_numpts(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_deltay
{
public:
  explicit Init_FindPath_Request_deltay(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_scale deltay(::interfaces::srv::FindPath_Request::_deltay_type arg)
  {
    msg_.deltay = std::move(arg);
    return Init_FindPath_Request_scale(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_deltax
{
public:
  explicit Init_FindPath_Request_deltax(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_deltay deltax(::interfaces::srv::FindPath_Request::_deltax_type arg)
  {
    msg_.deltax = std::move(arg);
    return Init_FindPath_Request_deltay(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_seed
{
public:
  explicit Init_FindPath_Request_seed(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_deltax seed(::interfaces::srv::FindPath_Request::_seed_type arg)
  {
    msg_.seed = std::move(arg);
    return Init_FindPath_Request_deltax(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_qtype
{
public:
  explicit Init_FindPath_Request_qtype(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_seed qtype(::interfaces::srv::FindPath_Request::_qtype_type arg)
  {
    msg_.qtype = std::move(arg);
    return Init_FindPath_Request_seed(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_r0
{
public:
  explicit Init_FindPath_Request_r0(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_qtype r0(::interfaces::srv::FindPath_Request::_r0_type arg)
  {
    msg_.r0 = std::move(arg);
    return Init_FindPath_Request_qtype(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_boxheight
{
public:
  explicit Init_FindPath_Request_boxheight(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_r0 boxheight(::interfaces::srv::FindPath_Request::_boxheight_type arg)
  {
    msg_.boxheight = std::move(arg);
    return Init_FindPath_Request_r0(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_boxwidth
{
public:
  explicit Init_FindPath_Request_boxwidth(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_boxheight boxwidth(::interfaces::srv::FindPath_Request::_boxwidth_type arg)
  {
    msg_.boxwidth = std::move(arg);
    return Init_FindPath_Request_boxheight(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_epsilon
{
public:
  explicit Init_FindPath_Request_epsilon(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_boxwidth epsilon(::interfaces::srv::FindPath_Request::_epsilon_type arg)
  {
    msg_.epsilon = std::move(arg);
    return Init_FindPath_Request_boxwidth(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_bta
{
public:
  explicit Init_FindPath_Request_bta(::interfaces::srv::FindPath_Request & msg)
  : msg_(msg)
  {}
  Init_FindPath_Request_epsilon bta(::interfaces::srv::FindPath_Request::_bta_type arg)
  {
    msg_.bta = std::move(arg);
    return Init_FindPath_Request_epsilon(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

class Init_FindPath_Request_alpha
{
public:
  Init_FindPath_Request_alpha()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FindPath_Request_bta alpha(::interfaces::srv::FindPath_Request::_alpha_type arg)
  {
    msg_.alpha = std::move(arg);
    return Init_FindPath_Request_bta(msg_);
  }

private:
  ::interfaces::srv::FindPath_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FindPath_Request>()
{
  return interfaces::srv::builder::Init_FindPath_Request_alpha();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_FindPath_Response_response
{
public:
  Init_FindPath_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::FindPath_Response response(::interfaces::srv::FindPath_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::FindPath_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FindPath_Response>()
{
  return interfaces::srv::builder::Init_FindPath_Response_response();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIND_PATH__BUILDER_HPP_
