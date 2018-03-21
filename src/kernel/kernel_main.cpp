#include "arch/i386/include/terminal.h"

extern "C"
void kernel_main(void)
{

    Terminal TERMINAL;
    TERMINAL.cls();
    TERMINAL.linebreak();
    TERMINAL.print("                       Welcome to OS Kernel Version 1.0                         ");
    TERMINAL.linebreak();
    TERMINAL.print("\nLoading...");

}
