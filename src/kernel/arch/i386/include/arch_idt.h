//
// Created by dev on 23/03/18.
//

#ifndef OS_ARCH_IDT_H
#define OS_ARCH_IDT_H

/* Defines an IDT entry */
struct idt_entry
{
    unsigned short base_lo;
    unsigned short sel;        /* Our kernel segment goes here! */
    unsigned char always0;     /* This will ALWAYS be set to 0! */
    unsigned char flags;       /* Set using the above table! */
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

extern "C" void idt_load();

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

/* Installs the IDT */
void idt_install();

uintptr_t get_idt_install_location();


#endif //OS_ARCH_IDT_H