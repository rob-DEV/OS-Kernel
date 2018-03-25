//
// Created by dev on 23/03/18.
//
#include "include/arch_string.h"
#include "include/arch_idt.h"

/* Declare an IDT of 256 entries. Although we will only use the
*  first 32 entries in this tutorial, the rest exists as a bit
*  of a trap. If any undefined IDT entry is hit, it normally
*  will cause an "Unhandled Interrupt" exception. Any descriptor
*  for which the 'presence' bit is cleared (0) will generate an
*  "Unhandled Interrupt" exception */
struct idt_entry idt[256];
struct idt_ptr idtp;

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{

    //The interrupt routine's base address
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;

    //The segment or 'selector' that this IDT entry will use
    //is set here, along with any access flags
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;

}

void idt_install()
{

    //Sets the special IDT pointer up, just like in 'gdt.c'
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = (uintptr_t)&idt;

    //Clear out the entire IDT, initializing it to zeros
    memset(&idt, sizeof(struct idt_entry) * 256, 0);

    //Points the processor's internal register to the new IDT
    idt_load();

}

uintptr_t get_idt_install_location() {
    return (uintptr_t)(&idt[0]);
}