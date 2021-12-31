cmake_minimum_required(VERSION 3.20)

project("sandbox")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wno-switch")

add_executable(sand sand.cc)


