cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project( mcl )
add_executable(mcl main.cpp)

find_package(PythonLibs 2.7)
target_include_directories(mcl PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(mcl ${PYTHON_LIBRARIES})