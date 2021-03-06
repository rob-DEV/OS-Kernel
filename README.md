A simple OS Kernel written in C/C++ with an assembly bootloader.

![1](https://github.com/rob-DEV/os-kernel/blob/master/res/5.PNG)
![1](https://github.com/rob-DEV/os-kernel/blob/master/res/6.PNG)
![1](https://github.com/rob-DEV/os-kernel/blob/master/res/7.PNG)

What does it do:

    Global Descriptor Table
    Interrupt Descriptor Table
    Simple C library - printf() etc
    Keyboard Input
    Memory allocation (heap)
    Enter VGA mode to a very limited GUI (PutPixel methods and simple desktop window system)

What is it going to do?

    Paging
    A GUI

To build the source run `build.sh` in the os directory
Then run the bin file using qemu
  `qemu -kernel latest.bin`
