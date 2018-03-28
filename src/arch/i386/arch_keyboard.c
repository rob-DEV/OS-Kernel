//
// Created by dev on 26/03/18.
//
#include "include/arch_keyboard.h"
#include "include/arch_timer.h"

/* Handles the keyboard interrupt */
void keyboard_handler(registers_t *r) {
    unsigned char scancode;

    /* Read from the keyboard's data buffer */
    scancode = inportb(0x60);

    if (scancode & 0x80) {

    } else {

        putch(standard_keymap[scancode]);
    }
}

void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}