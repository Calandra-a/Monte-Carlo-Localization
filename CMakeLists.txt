cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11 ${GAZEBO_CXX_FLAGS}) 
project( mcl )

add_library(robotMove SHARED robotMove.cc)
target_link_libraries(robotMove ${GAZEBO_LIBRARIES})

find_package(PythonLibs 2.7)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(robotMove ${PYTHON_LIBRARIES})

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")





