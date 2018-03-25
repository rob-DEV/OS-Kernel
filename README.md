A simple OS Kernel written in C++ with an assembly bootloader.

![1](https://github.com/rob-DEV/os-kernel/blob/master/res/4.PNG)

What does it does:

    Global Descriptor Table
    Interrupt Descriptor Table
    Simple C library - printf() etc

What is it going to do?

    Keyboard Input
    Paging
    Memory allocation (heap)
    A GUI

To build the source run make in the os directory
Then run the bin file using qemu
  `qemu -kernel latest.bin`
