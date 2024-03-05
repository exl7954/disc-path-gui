cmake_minimum_required(VERSION 3.8)
project(pathserver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(server src/disc.cpp src/Box.cpp src/QuadTree.cpp src/Corner.cpp src/fileProcessor.cpp src/Timer.cpp src/Wall.cpp)
ament_target_dependencies(server rclcpp interfaces)

install(TARGETS
  server
  DESTINATION lib/${PROJECT_NAME})

ament_package()
