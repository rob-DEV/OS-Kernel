#include "system.h"


extern "C"
void kernel_init(uint32_t magic, multiboot_info_t* mbi)
{
    init_terminal();
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    printf("Initializing Kernel...\n");

    if(MULTIBOOT_BOOTLOADER_MAGIC != magic)
        printf("Invalid Magic Number!! Attempting Boot...\n");

    printf("Magic Number: 0x%d\n", magic);
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
    printf("GDT Installed at Address: 0x%d\n", get_gdt_install_location());

    printf("Installing IDT!\n");
    idt_install();
    printf("GDT Installed at Address: 0x%d\n", get_idt_install_location());

    printf("Installing Interrupt Service!\n");
    isrs_install();
    printf("ISRS Installed!\n");

    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    printf("Scroll Test 1\n");
    for(;;);
}
