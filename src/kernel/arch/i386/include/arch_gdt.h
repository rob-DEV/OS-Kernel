//
// Created by dev on 22/03/18.
//

#ifndef OS_ARCH_GDT_H
#define OS_ARCH_GDT_H

#include "arch_types.h"

/* Should be called by main. This will setup the special GDT
*  pointer, set up the first 3 entries in our GDT, and then
*  finally call gdt_flush() in our assembler file in order
*  to tell the processor where the new GDT is and update the
*  new segment registers */

void gdt_install();

/* Setup a descriptor in the Global Descriptor Table */
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

/* This will be a function in start.asm. We use this to properly
*  reload the new segment registers */
extern "C" void gdt_flush();

#endif //OS_ARCH_GDT_H