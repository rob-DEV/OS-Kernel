cmake_minimum_required(VERSION 2.8.4)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        os src/kernel/kernel.cpp
        src/arch/i386/arch_terminal.c
        src/kernel/include/ src/kernel/
        src/libc/include/ src/libc/
        src/arch/i386/include/ src/arch/i386/ src/kernel/include/drivers/vga.h src/kernel/drivers/vga.cpp src/kernel/include/common/types.h src/kernel/hardwarecommunication/port.cpp src/kernel/include/hardwarecommunication/port.h src/kernel/include/gui/widget.h src/kernel/gui/widget.cpp src/kernel/include/gui/window.h src/kernel/include/gui/desktop.h src/kernel/gui/window.cpp src/kernel/gui/desktop.cpp src/kernel/include/common/graphicscontext.h)

target_include_directories(os PUBLIC src/kernel/include src/arch/i386/include src/libc/include)