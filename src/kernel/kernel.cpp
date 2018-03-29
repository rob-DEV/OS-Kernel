#include <system.h>
#include <drivers/vga.h>
#include <gui/desktop.h>
#include <cstdlib.h>

using namespace OS;
using namespace Drivers;
using namespace GUI;

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

bool VGA = false;

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


    for (int i = 0; i < 1; ++i) {

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

    printf("\n");

    //attemping VGA heap allocation
    VideoGraphicsArray* vga = new VideoGraphicsArray();
    vga->SetMode(320,200,8);
    Desktop* desktop = new Desktop(320,200, RGB_Color(0x00,0x00,0xA8));

    while (1)
    {
        desktop->Draw(vga);
        timer_wait_ticks(18);
    }
}
