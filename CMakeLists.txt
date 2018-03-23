cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(os src/kernel/kernel_main.cpp src/kernel/arch/i386/include/arch_types.h src/kernel/arch/i386/arch_terminal.c src/kernel/arch/i386/include/arch_terminal.h src/kernel/arch/i386/include/arch_string.h src/kernel/arch/i386/arch_gdt.c src/kernel/arch/i386/include/arch_gdt.h src/kernel/arch/i386/arch_string.c src/kernel/arch/i386/arch_io.cpp src/kernel/arch/i386/include/arch_io.h src/kernel/libc/stdio.c src/kernel/libc/include/stdio.h src/kernel/libc/itoa.c src/kernel/libc/cstdlib.h src/kernel/libc/include/atoi.h src/kernel/libc/atoi.c src/kernel/libc/include/arch.h)