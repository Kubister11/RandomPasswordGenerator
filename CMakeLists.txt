cmake_minimum_required(VERSION 3.27)
project(RandomPasswordGenerator)

set(CMAKE_CXX_STANDARD 20)

add_executable(RandomPasswordGenerator main.cpp
        utils/utils.cpp
        utils/utils.h)
