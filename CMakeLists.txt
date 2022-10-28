cmake_minimum_required(VERSION 3.14)

project(constexpr_cmath CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(constexpr_cmath INTERFACE)
target_include_directories(constexpr_cmath INTERFACE src)

enable_testing()
include(GoogleTest)
add_subdirectory(test)
