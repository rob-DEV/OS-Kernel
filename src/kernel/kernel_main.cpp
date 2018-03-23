#include "arch/i386/include/arch_terminal.h"
#include "arch/i386/include/archgdt.h"

#include "libc/include/stdio.h"

extern "C"
void kernel_main(void)
{
    init_terminal();
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    linebreak();
    puts("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    linebreak();
    gdt_install();
    puts("-------------------------- C lib from here on out... ---------------------------");

    int A = 65;

    printf("%c is converting integers to characters lol.", A);
    for(;;);


}
