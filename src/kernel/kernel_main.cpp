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

    printf("printf: TEST const char*: %s \n", "STRING SUBSTITUTE!");
    int a = 15;
    printf("printf: TEST INT(15): %d \n", a);
    printf("printf: TEST INT(12586): %d \n", 12586);
    printf("printf: TEST INT(55): %d \n", 55);
    printf("printf: TEST INT(84): %d \n", 84);
    printf("printf: TEST INT(194): %d \n", 194);
    printf("printf: TEST INT(17): %d \n", 17);
    for(;;);


}
