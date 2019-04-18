cmake_minimum_required(VERSION 3.10.2) 
project(srg-base)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS alica_engine srg-expressions)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES srg-base
  CATKIN_DEPENDS alica_engine srg-expressions
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  src/Base.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
