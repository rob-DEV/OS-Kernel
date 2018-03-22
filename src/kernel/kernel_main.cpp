#include "arch/i386/include/terminal.h"
#include "arch/i386/include/gdt.h"

extern "C"
void kernel_main(void)
{
    //First off
    init_terminal();

    linebreak();
    puts("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    linebreak();
    gdt_install();

    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    puts("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");

    for(;;);


}
