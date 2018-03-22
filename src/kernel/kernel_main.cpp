#include "arch/i386/include/terminal.h"

extern "C"

void kernel_main(void)
{
    //First off
    terminal_initialize();


    linebreak();
    terminal_write("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    linebreak();

    for(;;);

}
