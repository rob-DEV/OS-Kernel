//; In just a few pages in this tutorial, we will add our Interrupt
//; Service Routines (ISRs) right here!
.global isr0
.global isr1
.global isr2
.global isr3
.global isr4
.global isr5
.global isr6
.global isr7
.global isr8
.global isr9
.global isr10

//  0: Divide By Zero Exception
isr0:
    cli
    push $0
    push $0
    jmp isr_common_stub

//  1: Debug Exception
isr1:
    cli
    push $0
    push $1
    jmp isr_common_stub

//  2: Non Maskable Interrupt Exception
isr2:
    cli
    push $0
    push $2
    jmp isr_common_stub

//  3: Int 3 Exception
isr3:
    cli
    push $0
    push $3
    jmp isr_common_stub

//  4: INTO Exception
isr4:
    cli
    push $0
    push $4
    jmp isr_common_stub

//  5: Out of Bounds Exception
isr5:
    cli
    push $0
    push $5
    jmp isr_common_stub

isr6:
    cli
    push $0
    push $6
    jmp isr_common_stub

//  7: Coprocessor Not Available Exception
isr7:
    cli
    push $0
    push $7
    jmp isr_common_stub

//  8: Double Fault Exception (With Error Code!)
isr8:
    cli
    push $8
    jmp isr_common_stub

//  9: Coprocessor Segment Overrun Exception
isr9:
    cli
    push $0
    push $9
    jmp isr_common_stub

// 10: Bad TSS Exception (With Error Code!)
isr10:
    cli
    push $10
    jmp isr_common_stub





//; We call a C function in here. We need to let the assembler know
//; that '_fault_handler' exists in another file
.extern fault_handler
.type fault_handler, @function

//; This is our common ISR stub. It saves the processor state, sets
//; up for kernel mode segments, calls the C-level fault handler,
//; and finally restores the stack frame.
isr_common_stub:
    pushal  # Push registers (edi,esi,ebp,esp.ebx,edx.ecx.eax)
    push %ds # Push data segments
    push %es
    push %fs
    push %gs

    mov $0x10, %ax # Load the kernel data segment descriptor
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    mov %esp, %eax # We save the stack so we can restore it later
    push %eax

    movl $fault_handler, %eax
    call *%eax  # Bran say this preserves the EIP register

    # Undo everything IN REVERSE ORDER
    pop %eax
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popal
    add $8, %esp # Clear the exception number and code
    iret    # Return from executing code before the exception call.
            # Restores CS, EIP, EFLAGS, SS and ESP.
