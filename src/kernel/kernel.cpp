#include "arch/i386/include/arch.h"
#include "libc/cstdlib.h"

extern "C"
void kernel_main(void)
{
    init_terminal();
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    printf("--------------------------------------------------------------------------------");
    printf("-------------- Welcome to Kernel OS ver 1.0 with Pseudo C library --------------");
    printf("--------------------------------------------------------------------------------");

    printf("Installing GDT!\n");
    gdt_install();
    printf("GDT Installed at Address: 0x%d\n", get_gdt_install_location());

    printf("Installing IDT!\n");
    idt_install();
    printf("GDT Installed at Address: 0x%d\n", get_idt_install_location());

    printf("Installing Interrupt Service!\n");
    isrs_install();
    printf("ISRS Installed!\n");


    int result = 10 / 5;

    printf("Answer: %d", &result);

    for(;;);
}