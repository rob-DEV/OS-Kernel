A simple OS Kernel written in C++ with an assembly bootloader.

![1](https://github.com/rob-DEV/os-kernel/blob/master/res/1.PNG)

What does it does:

    Prints some text to the screen from a C++ Kernel and hangs.

What is it going to do?

    Keyboard Input
    Proper terminal
    Global Descriptor Table
    Paging
    Memory allocation (heap)
    A GUI

To build the source run make in the os directory
Then run the bin file using qemu
  `qemu -kernel latest.bin`
