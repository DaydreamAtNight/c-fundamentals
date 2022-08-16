cmake_minimum_required(VERSION 3.0)
project(SWAPTEST)

include_directories(include)   # -Iinclude
add_executable(SwapTest.out main.cpp src/swap.cpp)
