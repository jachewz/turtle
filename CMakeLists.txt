cmake_minimum_required(VERSION 2.8.3)
project(turtle)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Quality.msg
 )

# Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs

)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_subscriber src/turtle_subscriber.cpp)
target_link_libraries(turtle_subscriber ${catkin_LIBRARIES})
