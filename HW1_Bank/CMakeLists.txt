cmake_minimum_required(VERSION 3.8)
project(HW1_Bank)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Account.cpp
        Account.h
        main.cpp)

add_executable(HW1_Bank ${SOURCE_FILES})