//
// Created by dev on 25/03/18.
//

#ifndef OS_ARCH_TIMER_H
#define OS_ARCH_TIMER_H

#include "arch_terminal.h"
#include "arch_isrs.h"
#include "arch_irq.h"

/* This will keep track of how many ticks that the system
*  has been running for */
static int timer_ticks = 0;

/* Handles the timer. In this case, it's very simple: We
*  increment the 'timer_ticks' variable every time the
*  timer fires. By default, the timer fires 18.222 times
*  per second. Why 18.222Hz? Some engineer at IBM must've
*  been smoking something funky */
void timer_handler(registers_t *r);

/* Sets up the system clock by installing the timer handler
*  into IRQ0 */
void timer_install();

//Sleep test ticks
void timer_wait_ticks(uint32_t ticks);
//Sleep test seconds (soon to be in cstdlib)
void timer_wait_seconds(uint32_t seconds);

#endif //OS_ARCH_TIMER_H
