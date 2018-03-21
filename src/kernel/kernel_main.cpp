#include "arch/i386/include/terminal.h"

extern "C"
void kernel_main(void)
{

    terminal_initialize();
    terminal_clearscreen();
    terminal_linkbreak();
    terminal_write("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    terminal_linkbreak();
    terminal_writeline("Now with a new C-Style terminal! -- The nice C++ class is gone :(");
    terminal_writeline("Next Steps:");
    terminal_writeline("Memory Allocation Heap, new delete & GDT");
    terminal_writeline("C/C++ std library!");


}
