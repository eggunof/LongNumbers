cmake_minimum_required(VERSION 3.28)
project(LongNumbers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)
if (GTest_FOUND)
    enable_testing()
    include(GoogleTest)
else ()
    message(STATUS "GTest not found")
endif ()

add_subdirectory(libraries)

add_executable(LongNumbers src/main.cc)
target_link_libraries(LongNumbers numbers)