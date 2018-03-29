#include <system.h>
#include <shell/shell.h>
#include <drivers/vga.h>
#include <gui/desktop.h>

#include <stdio.h>


using namespace OS;
using namespace Drivers;
using namespace GUI;

void dumb_load(int count)
{
    for (int i = 0; i < count; ++i) {

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
}

void enter_VGA() {
    //attempting VGA heap allocation
    VideoGraphicsArray* vga = new VideoGraphicsArray();
    vga->SetMode(320,200,8);
    Desktop* desktop = new Desktop(320,200, RGB_Color(0x00,0x00,0xA8));
    Desktop* desktop1 = new Desktop(10,10, RGB_Color(0xA8,0x00,0x00));
    desktop->AddChild(desktop1);

    while (1)
    {
        desktop->Draw(vga);
        desktop1->Draw(vga);
        timer_wait_ticks(18);
    }
}

void disableShellInput()
{
    Shell::ShellEnabled = false;
}

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
    printf("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    Shell* shell = Shell::GetShell();

    shell->RegisterCommand("vga", "Type \"vga\" to enter VGA mode", enter_VGA);
    shell->RegisterCommand("disable", "Type \"disable\" to disable Shell Input", disableShellInput);


    printf("size of shell: %d\n", sizeof(Shell));
    int* a = (int*)malloc(4);

    *a = 258;

    printf("%d at address: 0x%d\n", *a, a);

    free(a);
    printf("%d at address: 0x%d\n", *a, a);

    while (1);
}
