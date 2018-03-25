.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15

//32: IRQ0
irq0:
    cli
    push 0    //Note that these don't push an error code on the stack:
                   //We need to push a dummy error code
    push 32
    jmp irq_common_stub

irq1:
    cli
    push 0
    push 33
    jmp irq_common_stub

irq2:
    cli
    push 0
    push 34
    jmp irq_common_stub

irq3:
    cli
    push 0
    push 35
    jmp irq_common_stub

irq4:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq5:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq6:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq7:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq8:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq9:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq10:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq11:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq12:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq13:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq14:
    cli
    push 0
    push 47
    jmp irq_common_stub

irq15:
    cli
    push 0
    push 47
    jmp irq_common_stub