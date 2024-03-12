// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/FindPath.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FindPath_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FindPath_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindPath_Request_
{
  using Type = FindPath_Request_<ContainerAllocator>;

  explicit FindPath_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->alpha[0] = 10.0;
      this->alpha[1] = 360.0;
      this->bta[0] = 500.0;
      this->bta[1] = 20.0;
      this->epsilon = 1.0;
      this->boxwidth = 512.0;
      this->boxheight = 512.0;
      this->r0 = 30.0;
      this->qtype = 0ll;
      this->seed = 111ll;
      this->deltax = 0.0;
      this->deltay = 0.0;
      this->scale = 1.0;
      this->numpts = 12ll;
      this->pts = "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92";
      this->numpolygons = 3ll;
      this->polygons = "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      std::fill<typename std::array<double, 2>::iterator, double>(this->alpha.begin(), this->alpha.end(), 0.0);
      std::fill<typename std::array<double, 2>::iterator, double>(this->bta.begin(), this->bta.end(), 0.0);
      this->epsilon = 0.0;
      this->boxwidth = 0.0;
      this->boxheight = 0.0;
      this->r0 = 0.0;
      this->qtype = 0ll;
      this->seed = 0ll;
      this->deltax = 0.0;
      this->deltay = 0.0;
      this->scale = 0.0;
      this->numpts = 0ll;
      this->pts = "";
      this->numpolygons = 0ll;
      this->polygons = "";
    }
  }

  explicit FindPath_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : alpha(_alloc),
    bta(_alloc),
    pts(_alloc),
    polygons(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->alpha[0] = 10.0;
      this->alpha[1] = 360.0;
      this->bta[0] = 500.0;
      this->bta[1] = 20.0;
      this->epsilon = 1.0;
      this->boxwidth = 512.0;
      this->boxheight = 512.0;
      this->r0 = 30.0;
      this->qtype = 0ll;
      this->seed = 111ll;
      this->deltax = 0.0;
      this->deltay = 0.0;
      this->scale = 1.0;
      this->numpts = 12ll;
      this->pts = "10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92";
      this->numpolygons = 3ll;
      this->polygons = "1,4,3,2,1|5,9,8,7,6,5|10,12,11,10";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      std::fill<typename std::array<double, 2>::iterator, double>(this->alpha.begin(), this->alpha.end(), 0.0);
      std::fill<typename std::array<double, 2>::iterator, double>(this->bta.begin(), this->bta.end(), 0.0);
      this->epsilon = 0.0;
      this->boxwidth = 0.0;
      this->boxheight = 0.0;
      this->r0 = 0.0;
      this->qtype = 0ll;
      this->seed = 0ll;
      this->deltax = 0.0;
      this->deltay = 0.0;
      this->scale = 0.0;
      this->numpts = 0ll;
      this->pts = "";
      this->numpolygons = 0ll;
      this->polygons = "";
    }
  }

  // field types and members
  using _alpha_type =
    std::array<double, 2>;
  _alpha_type alpha;
  using _bta_type =
    std::array<double, 2>;
  _bta_type bta;
  using _epsilon_type =
    double;
  _epsilon_type epsilon;
  using _boxwidth_type =
    double;
  _boxwidth_type boxwidth;
  using _boxheight_type =
    double;
  _boxheight_type boxheight;
  using _r0_type =
    double;
  _r0_type r0;
  using _qtype_type =
    int64_t;
  _qtype_type qtype;
  using _seed_type =
    int64_t;
  _seed_type seed;
  using _deltax_type =
    double;
  _deltax_type deltax;
  using _deltay_type =
    double;
  _deltay_type deltay;
  using _scale_type =
    double;
  _scale_type scale;
  using _numpts_type =
    int64_t;
  _numpts_type numpts;
  using _pts_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pts_type pts;
  using _numpolygons_type =
    int64_t;
  _numpolygons_type numpolygons;
  using _polygons_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _polygons_type polygons;

  // setters for named parameter idiom
  Type & set__alpha(
    const std::array<double, 2> & _arg)
  {
    this->alpha = _arg;
    return *this;
  }
  Type & set__bta(
    const std::array<double, 2> & _arg)
  {
    this->bta = _arg;
    return *this;
  }
  Type & set__epsilon(
    const double & _arg)
  {
    this->epsilon = _arg;
    return *this;
  }
  Type & set__boxwidth(
    const double & _arg)
  {
    this->boxwidth = _arg;
    return *this;
  }
  Type & set__boxheight(
    const double & _arg)
  {
    this->boxheight = _arg;
    return *this;
  }
  Type & set__r0(
    const double & _arg)
  {
    this->r0 = _arg;
    return *this;
  }
  Type & set__qtype(
    const int64_t & _arg)
  {
    this->qtype = _arg;
    return *this;
  }
  Type & set__seed(
    const int64_t & _arg)
  {
    this->seed = _arg;
    return *this;
  }
  Type & set__deltax(
    const double & _arg)
  {
    this->deltax = _arg;
    return *this;
  }
  Type & set__deltay(
    const double & _arg)
  {
    this->deltay = _arg;
    return *this;
  }
  Type & set__scale(
    const double & _arg)
  {
    this->scale = _arg;
    return *this;
  }
  Type & set__numpts(
    const int64_t & _arg)
  {
    this->numpts = _arg;
    return *this;
  }
  Type & set__pts(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pts = _arg;
    return *this;
  }
  Type & set__numpolygons(
    const int64_t & _arg)
  {
    this->numpolygons = _arg;
    return *this;
  }
  Type & set__polygons(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->polygons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FindPath_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FindPath_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindPath_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindPath_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FindPath_Request
    std::shared_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FindPath_Request
    std::shared_ptr<interfaces::srv::FindPath_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_Request_ & other) const
  {
    if (this->alpha != other.alpha) {
      return false;
    }
    if (this->bta != other.bta) {
      return false;
    }
    if (this->epsilon != other.epsilon) {
      return false;
    }
    if (this->boxwidth != other.boxwidth) {
      return false;
    }
    if (this->boxheight != other.boxheight) {
      return false;
    }
    if (this->r0 != other.r0) {
      return false;
    }
    if (this->qtype != other.qtype) {
      return false;
    }
    if (this->seed != other.seed) {
      return false;
    }
    if (this->deltax != other.deltax) {
      return false;
    }
    if (this->deltay != other.deltay) {
      return false;
    }
    if (this->scale != other.scale) {
      return false;
    }
    if (this->numpts != other.numpts) {
      return false;
    }
    if (this->pts != other.pts) {
      return false;
    }
    if (this->numpolygons != other.numpolygons) {
      return false;
    }
    if (this->polygons != other.polygons) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_Request_

// alias to use template instance with default allocator
using FindPath_Request =
  interfaces::srv::FindPath_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FindPath_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FindPath_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindPath_Response_
{
  using Type = FindPath_Response_<ContainerAllocator>;

  explicit FindPath_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
      this->path = "";
      this->boxes = "";
    }
  }

  explicit FindPath_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc),
    path(_alloc),
    boxes(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
      this->path = "";
      this->boxes = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;
  using _path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _path_type path;
  using _boxes_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _boxes_type boxes;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }
  Type & set__path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->path = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FindPath_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FindPath_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindPath_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindPath_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FindPath_Response
    std::shared_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FindPath_Response
    std::shared_ptr<interfaces::srv::FindPath_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindPath_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    if (this->path != other.path) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindPath_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindPath_Response_

// alias to use template instance with default allocator
using FindPath_Response =
  interfaces::srv::FindPath_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct FindPath
{
  using Request = interfaces::srv::FindPath_Request;
  using Response = interfaces::srv::FindPath_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIND_PATH__STRUCT_HPP_
