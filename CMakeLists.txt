cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(os src/kernel/kernel_main.cpp src/kernel/arch/i386/include/types.h src/kernel/arch/i386/terminal.c src/kernel/arch/i386/include/terminal.h src/kernel/arch/i386/mem_util.c src/kernel/arch/i386/include/mem_util.h src/kernel/arch/i386/include/string.h src/kernel/arch/i386/gdt.c src/kernel/arch/i386/include/gdt.h src/kernel/arch/i386/string.c src/kernel/arch/i386/io.cpp src/kernel/arch/i386/include/io.h)