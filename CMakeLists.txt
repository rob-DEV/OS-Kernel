cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(os src/kernel/kernel_main.cpp src/kernel/arch/i386/include/types.h src/kernel/arch/i386/arch_terminal.c src/kernel/arch/i386/include/arch_terminal.h src/kernel/arch/i386/include/string.h src/kernel/arch/i386/archgdt.c src/kernel/arch/i386/include/archgdt.h src/kernel/arch/i386/string.c src/kernel/arch/i386/arch_io.cpp src/kernel/arch/i386/include/arch_io.h src/kernel/stdio.cpp src/kernel/libc/include/stdio.h)