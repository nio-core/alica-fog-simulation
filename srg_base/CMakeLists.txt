cmake_minimum_required(VERSION 3.10.2) 
project(srg_base)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

find_package(catkin REQUIRED COMPONENTS alica_engine srg_expressions alica_dummy_proxy)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES srg-base
  CATKIN_DEPENDS alica_engine srg_expressions alica_dummy_proxy
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
