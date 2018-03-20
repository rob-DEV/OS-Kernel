#include "include/terminal.h"


extern "C"
void kernel_main(void)
{
    Terminal terminal;
    terminal.cls();
    terminal.linebreak();
    terminal.println("Welcome to OS Kernel ver 1.0");
    terminal.linebreak();



    for(;;);
}
