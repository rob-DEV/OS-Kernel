//
// Created by dev on 23/03/18.
//

#ifndef OS_ARCH_ISRS_H
#define OS_ARCH_ISRS_H

#include "arch_types.h"

/* These are function prototypes for all of the exception
*  handlers: The first 32 entries in the IDT are reserved
*  by Intel, and are designed to service exceptions! */
extern "C" void isr0();
extern "C" void isr1();
extern "C" void isr2();
extern "C" void isr3();
extern "C" void isr4();
extern "C" void isr5();
extern "C" void isr6();
extern "C" void isr7();
extern "C" void isr8();
extern "C" void isr9();
extern "C" void isr10();
extern "C" void isr11();
extern "C" void isr12();
extern "C" void isr13();
extern "C" void isr14();
extern "C" void isr15();
extern "C" void isr16();
extern "C" void isr17();
extern "C" void isr18();
extern "C" void isr19();
extern "C" void isr20();
extern "C" void isr21();
extern "C" void isr22();
extern "C" void isr23();
extern "C" void isr24();
extern "C" void isr25();
extern "C" void isr26();
extern "C" void isr27();
extern "C" void isr28();
extern "C" void isr29();
extern "C" void isr30();
extern "C" void isr31();

/* This is a very repetitive function... it's not hard, it's
*  just annoying. As you can see, we set the first 32 entries
*  in the IDT to the first 32 ISRs. We can't use a for loop
*  for this, because there is no way to get the function names
*  that correspond to that given entry. We set the access
*  flags to 0x8E. This means that the entry is present, is
*  running in ring 0 (kernel level), and has the lower 5 bits
*  set to the required '14', which is represented by 'E' in
*  hex. */
/* This defines what the stack looks like after an ISR was running */
typedef struct regs
{

    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;

} registers_t;

extern "C" void fault_handler(registers_t* r);

/* This is a simple string array. It contains the message that
*  corresponds to each and every exception. We get the correct
*  message by accessing like:
*  exception_message[interrupt_number] */
static const char *exception_messages[32] =
        {
                "Division By Zero",
                "Debug",
                "Non Maskable Interrupt",
                "Breakpoint",
                "Into Detected Overflow",
                "Out of Bounds",
                "Invalid Opcode",
                "No Coprocessor",

                "Double Fault",
                "Coprocessor Segment Overrun",
                "Bad TSS",
                "Segment Not Present",
                "Stack Fault",
                "General Protection Fault",
                "Page Fault",
                "Unknown Interrupt",

                "Coprocessor Fault",
                "Alignment Check",
                "Machine Check",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",

                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved",
                "Reserved"
        };

void isrs_install();

#endif //OS_ARCH_ISRS_H
