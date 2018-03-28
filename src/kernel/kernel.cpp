#include <system.h>
#include <drivers/vga.h>

#include <cstdlib.h>

extern "C"
void kernel_init(multiboot_info_t* mbi, uint32_t magic)
{
    set_video_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printf("Initializing Kernel...\n");

    if(MULTIBOOT_BOOTLOADER_MAGIC != magic)
        printf("Invalid Magic Number!! Attempting Boot...\n");

    printf("Magic Number: 0x%x\n", magic);

    //parse_multiboot_info(magic, mbi);

    gdt_install();
    idt_install();
    heap_install(mbi->mem_lower, mbi->mem_upper);
}

extern "C"
void kernel_main(void)
{
    isrs_install();
    irq_install();
    timer_install();
    keyboard_install();

    printf("--------------------------------------------------------------------------------");
    printf("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    printf("--------------------------------------------------------------------------------");

    printf("Switching to VGA Mode!\n");

    for (int i = 0; i < 3; ++i) {

        if(i != 0)
            printf("\b\\");
        else
            printf("\\");
        timer_wait_ticks(5);
        printf("\b|");
        timer_wait_ticks(5);
        printf("\b/");
        timer_wait_ticks(5);
        printf("\b-");
        timer_wait_ticks(5);
    }


    OS::Drivers::VideoGraphicsArray vga;

    vga.SetMode(320, 200, 8);

    for(uint8_t y = 0; y < 200; y++)
        for(uint32_t x = 0; x < 320; x++)
            vga.PutPixel(x,y, 0x00,0x00, 0xA8);

    for(;;);
}
