cmake_minimum_required(VERSION 3.28)
project(LongNumbers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(libraries)

add_executable(LongNumbers src/main.cc)
