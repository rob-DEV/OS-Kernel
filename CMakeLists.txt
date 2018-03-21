cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(os src/kernel/kernel_main.cpp src/kernel/arch/i386/include/types.h src/kernel/terminal.cpp src/kernel/arch/i386/include/terminal.h src/kernel/include/memory.cpp src/kernel/arch/i386/include/memory.h src/kernel/arch/i386/include/string.h src/kernel/string.cpp)