cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        os src/kernel/kernel.cpp
        src/kernel/include/ src/kernel/
        src/libc/include/ src/libc/
        src/arch/i386/include/ src/arch/i386/)