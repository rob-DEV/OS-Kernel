#include "include/system.h"

extern "C"
void kernel_init(uint32_t magic, multiboot_info_t* mbi)
{
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printf("Initializing Kernel...\n");

    if(MULTIBOOT_BOOTLOADER_MAGIC != magic)
        printf("Invalid Magic Number!! Attempting Boot...\n");

    printf("Magic Number: 0x%x\n", magic);

    parse_multiboot_info(magic, mbi);

    gdt_install();
    printf("GDT Installed at Address: 0x%x\n", ((unsigned int)get_gdt_install_location()));

    idt_install();
    printf("GDT Installed at Address: 0x%x\n", ((unsigned int)get_idt_install_location()));

    isrs_install();
    printf("ISRS Installed!\n");

    irq_install();
    printf("IRQs Installed!\n");

    timer_install();
    printf("PIT Installed!\n");

    keyboard_install();
    printf("Keyboard Installed!\n");
}

extern "C"
void kernel_main(void)
{
    printf("--------------------------------------------------------------------------------");
    printf("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    printf("--------------------------------------------------------------------------------");

    int* high_mem = (int*)0x25000000000;

    printf("At address: %x == %d\n", high_mem, *high_mem);

    *high_mem = 25;

    printf("At address: %x == %d\n", high_mem, *high_mem);

    for(;;);
}
