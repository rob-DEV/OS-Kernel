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

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80) {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
    } else {
        /* Here, a key was just pressed. Please note that if you
        *  hold a key down, you will get repeated key press
        *  interrupts. */

        /* Just to show you how this works, we simply translate
        *  the keyboard scancode into an ASCII value, and then
        *  display it to the screen. You can get creative and
        *  use some flags to see if a shift is pressed and use a
        *  different layout, or you can add another 128 entries
        *  to the above layout to correspond to 'shift' being
        *  held. If shift is held using the larger lookup table,
        *  you would add 128 to the scancode when you look for it */
        putch(standard_keymap[scancode]);
    }
}

void keyboard_install()
{
    irq_install_handler(0, keyboard_handler);
}