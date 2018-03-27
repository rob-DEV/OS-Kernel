#include "include/system.h"

extern "C"
void kernel_init(multiboot_info_t* mbi, uint32_t magic)
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
    printf("IDT Installed at Address: 0x%x\n", ((unsigned int)get_idt_install_location()));

    heap_install(mbi->mem_lower, mbi->mem_upper);
    printf("Heap Initalized!\n");
}

extern "C"
void kernel_main(void)
{
    isrs_install();
    printf("ISRS Installed!\n");

    irq_install();
    printf("IRQs Installed!\n");

    timer_install();
    printf("PIT Installed!\n");
    timer_wait_seconds(1);

    keyboard_install();
    printf("Keyboard Installed!\n");
    timer_wait_seconds(1);

    printf("--------------------------------------------------------------------------------");
    printf("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    printf("--------------------------------------------------------------------------------");


    for(;;);
}
