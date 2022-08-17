# SET(CMAKE_CXX_FLAGS "-std=c++11")
set (CMAKE_CXX_STANDARD 11) # same as above
set (CMAKE_BUILD_TYPE Debug) # debug mode
cmake_minimum_required(VERSION 3.0)
project(soliderShortGun)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(soliderShortGun.out main.cpp src/shotGun.cpp src/solider.cpp )