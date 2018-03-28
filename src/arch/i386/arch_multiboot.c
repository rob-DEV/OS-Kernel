//
// Created by dev on 25/03/18.
//

#include "../../kernel/include/system.h"

// Check if the bit BIT in FLAGS is set.
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

void parse_multiboot_info(uint32_t magic, multiboot_info_t* mbi)
{
    /*
    printf("Processing Multiboot Information\n");

    //multiboot_info_t* mbi;

    // Am I booted by a Multiboot-compliant boot loader?
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
    {
        printf("Invalid magic number: %x\n", (unsigned)magic);
        return;
    }

    // Set MBI to the address of the Multiboot information structure.
    //mbi = (multiboot_info_t *)addr;

    // Print out the flags.
    printf("Flags = 0x%d\n", (unsigned)mbi->flags);

    // Are mem_* valid?
    if (CHECK_FLAG(mbi->flags, 0))
    {
        printf("mem_lower = %d KB, mem_upper = %d KB\n",
                   (unsigned)mbi->mem_lower, (unsigned)mbi->mem_upper);
    }

    // Bits 4 and 5 are mutually exclusive!
    if (CHECK_FLAG(mbi->flags, 4) && CHECK_FLAG(mbi->flags, 5))
    {
        printf("Both bits 4 and 5 are set.\n");
        return;
    }

    // Is the symbol table of a.out valid?
    if (CHECK_FLAG(mbi->flags, 4))
    {
        multiboot_aout_symbol_table_t *multiboot_aout_sym = &(mbi->u.aout_sym);

        printf("multiboot_aout_symbol_table: tabsize = 0x%0x, strsize = 0x%x, addr = 0x%x\n",
                   (unsigned)multiboot_aout_sym->tabsize,
                   (unsigned)multiboot_aout_sym->strsize,
                   (unsigned)multiboot_aout_sym->addr);
    }

    // Is the section header table of ELF valid?
    if (CHECK_FLAG(mbi->flags, 5))
    {
        multiboot_elf_section_header_table_t *multiboot_elf_sec = &(mbi->u.elf_sec);

        printf("multiboot_elf_sec: num = %u, size = 0x%x, addr = 0x%x, shndx = 0x%x\n",
                   (unsigned)multiboot_elf_sec->num, (unsigned)multiboot_elf_sec->size,
                   (unsigned)multiboot_elf_sec->addr, (unsigned)multiboot_elf_sec->shndx);
    }

    // Are mmap_* valid?
    if (CHECK_FLAG(mbi->flags, 6))
    {
        multiboot_memory_map_t *mmap;

        printf("mmap_addr = 0x%x, mmap_length = 0x%x\n",
                   (unsigned)mbi->mmap_addr, (unsigned)mbi->mmap_length);

        for (mmap = (multiboot_memory_map_t *)mbi->mmap_addr;
             (unsigned long)mmap < mbi->mmap_addr + mbi->mmap_length;
             mmap = (multiboot_memory_map_t *)((unsigned long)mmap + mmap->size + sizeof(mmap->size)))
            printf(" size = 0x%x, base_addr = 0x%x%x, length = 0x%x%x, type = 0x%x\n",
                       (unsigned)mmap->size,
                       (unsigned)(mmap->addr >> 32),
                       (unsigned)(mmap->addr & 0xffffffff),
                       (unsigned)(mmap->len >> 32),
                       (unsigned)(mmap->len & 0xffffffff),
                       (unsigned)mmap->type);

    }
    */
}