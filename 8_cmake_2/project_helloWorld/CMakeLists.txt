# if speceificy the compiler, must ahead of everything
# set(CMAKE_CPP_COMPILER /opt/homebrew/bin/g++-11)
set(CMAKE_CXX_COMPILER g++-11)

# set minimum version requirment
cmake_minimum_required(VERSION 3.0) # cmake --version >> cmake version 3.21.3
# set project name
project(HelloWorld)


# g++ helloWorld.cpp -O helloWorld.out, translated in cmake
add_executable(helloWorld.out helloWorld.cpp)

# inner source make:
# cmake .

# outer source make:
# mkdir build
# cd build
# cmake ../