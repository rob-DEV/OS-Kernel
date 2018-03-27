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

    printf(".\n");
    timer_wait_seconds(1);
    printf("..\n");
    timer_wait_seconds(1);
    printf("...\n");
    timer_wait_seconds(1);

    printf("--------------------------------------------------------------------------------");
    printf("------------------------- Welcome to Kernel OS ver 1.0 -------------------------");
    printf("--------------------------------------------------------------------------------");

    //FILL HEAP 100%
    int num_ints = 130809;
    int* int_array = (int*)malloc(4 * num_ints);

    for (int i = 0; i < num_ints; ++i) {
        int_array[i] = i;
    }

    printf("Array allocation address: 0x%x\n", int_array);
    printf("Array val: %d\n", int_array[2]);

    printf("Address at high memory: 0x%x\n", &int_array[num_ints - 5]);

    printf("Attempting to free memory...");

    //deallocate the memory and attempt to add some new ptrs i.e. 100%RAM use to <1%
    free(int_array);

    int* fail_test = (int*)malloc(4);
    printf("Allocation fail address: 0x%x\n", fail_test);
    for(;;);
}
