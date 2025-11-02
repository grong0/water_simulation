cmake_minimum_required(VERSION 3.20)
project(water_simulation LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS src/*.cpp)
add_executable(water_simulation ${SRCS})
target_include_directories(water_simulation PRIVATE include)