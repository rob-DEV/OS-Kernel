#include "system.h"

extern "C"
void kernel_init(uint32_t magic, multiboot_info_t* mbi)
{
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    printf("Initializing Kernel...\n");

    if(MULTIBOOT_BOOTLOADER_MAGIC != magic)
        printf("Invalid Magic Number!! Attempting Boot...\n");

    printf("Magic Number: 0x%x\n", magic);
    parse_multiboot_info(magic, mbi);
}

extern "C"
void kernel_main(void)
{
    printf("--------------------------------------------------------------------------------");
    printf("-------------- Welcome to Kernel OS ver 1.0 with Pseudo C library --------------");
    printf("--------------------------------------------------------------------------------");

    printf("Installing GDT!\n");
    gdt_install();
    printf("GDT Installed at Address: 0x%x\n", ((unsigned int)get_gdt_install_location()));

    printf("Installing IDT!\n");
    idt_install();
    printf("GDT Installed at Address: 0x%x\n", ((unsigned int)get_idt_install_location()));

    printf("Installing Interrupt Service!\n");
    isrs_install();
    printf("ISRS Installed!\n");

    printf("Installing Interrupt Requests!\n");
    irq_install();
    printf("IRQs Installed!\n");

    printf("Installing Time*!\n");
    timer_install();
    printf("Time* Installed!\n");

    printf("Waiting 50 ticks!\n");
    timer_wait_ticks(50);
    printf("End Wait!\n");

    printf("Waiting 3 seconds!\n");
    sleep(3);
    printf("End Wait!\n");

    for(;;);
}
