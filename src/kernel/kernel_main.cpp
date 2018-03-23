#include "arch/i386/include/arch.h"

#include "libc/include/stdio.h"

extern "C"
void kernel_main(void)
{
    init_terminal();
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    linebreak();
    puts("-------------- Welcome to Kernel OS ver 1.0 with Pseudo C library --------------");
    linebreak();
    printf("Installing GDT!\n");
    gdt_install();
    printf("GDT Installed!\n");
    printf("Installing IDT!\n");
    idt_install();
    printf("IDT Installed!\n");


    for(;;);
}
