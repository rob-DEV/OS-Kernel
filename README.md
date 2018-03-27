A simple OS Kernel written in C++ with an assembly bootloader.

![1](https://github.com/rob-DEV/os-kernel/blob/master/res/5.PNG)

What does it does:

    Global Descriptor Table
    Interrupt Descriptor Table
    Simple C library - printf() etc
    Keyboard Input
    Memory allocation (heap)

What is it going to do?

    Paging
    A GUI

To build the source run `build.sh` in the os directory
Then run the bin file using qemu
  `qemu -kernel latest.bin`
