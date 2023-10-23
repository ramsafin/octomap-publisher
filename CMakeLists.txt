cmake_minimum_required(VERSION 3.10)
project(octomap_publisher VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## packages ##
find_package(OpenCV 4 REQUIRED)

find_package(octomap REQUIRED)

find_package(catkin REQUIRED 
  rospy
  roscpp
  roslib
  cv_bridge
  sensor_msgs
  octomap_msgs
)

## catkin specific configuration ##
catkin_package()

## build ##
add_executable(static_${PROJECT_NAME} nodes/static_octomap_publisher.cpp)

target_include_directories(
  static_${PROJECT_NAME} 
  PRIVATE 
  ${catkin_INCLUDE_DIRS}
  ${octomap_INCLUDE_DIRS}
)

target_link_libraries(
  static_${PROJECT_NAME} 
  PRIVATE
  ${catkin_LIBRARIES} 
  ${OpenCV_LIBS}
  ${octomap_LIBRARIES}                      
)
