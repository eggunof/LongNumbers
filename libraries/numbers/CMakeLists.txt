cmake_minimum_required(VERSION 3.28)

add_library(numbers)
file(GLOB_RECURSE SRC_FILES "*.cc")
target_sources(numbers PRIVATE ${SRC_FILES})
target_include_directories(numbers PUBLIC include PRIVATE src)

add_subdirectory(tests)