cmake_minimum_required (VERSION 2.8)

# Set C++ compiler to clang.
#set (CMAKE_C_COMPILER "clang")
#set (CMAKE_CXX_COMPILER "clang++")
set (CMAKE_CXX_FLAGS "-std=c++11") 
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -g") 
# set (CMAKE_CXX_FLAGS "-g") 
set (CMAKE_CXX_STANDARD 11)
#set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_BUILD_TYPE Debug)
# Set project name and version.
project (schuelar)
set (schuelar VERSION 0.2)

# Add the executable.
include_directories(/home/uri/cyber/schedular)
#include_directories(json jsonreader)
#include_directories(json)
#add_executable(osr netsec.cpp interface.cpp detector.cpp cyberlog.cpp utils.cpp)
#add_executable(CAN_bus_Logger CAN_bus_Logger.cpp)
#TARGET_LINK_LIBRARIES(Logger json)
#TARGET_LINK_LIBRARIES(Logger)
add_executable(schuelar main.cpp schular.cpp tasker.cpp )
TARGET_LINK_LIBRARIES(schuelar pthread)
