cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(os src/kernel/kernel.cpp src/kernel/include/types.h src/kernel/terminal.cpp src/kernel/include/terminal.h src/kernel/memory.cpp src/kernel/include/memory.h src/kernel/include/string.h src/kernel/string.cpp)