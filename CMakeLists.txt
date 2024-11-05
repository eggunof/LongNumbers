cmake_minimum_required(VERSION 3.28)
project(LongNumbers)

set(CMAKE_CXX_STANDARD 20)

add_executable(LongNumbers src/main.cc
        src/modules/natural.h
        src/modules/natural.cc
        src/modules/integer.hc
        src/modules/integer.cc)
