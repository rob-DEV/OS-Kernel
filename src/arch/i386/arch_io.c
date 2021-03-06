///* This exists in 'start.asm', and is used to load our IDT */
extern void idt_load();
// Created by dev on 22/03/18.
//

#include "include/arch_io.h"

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}