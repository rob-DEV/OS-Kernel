//
// Created by dev on 25/03/18.
//

#include "include/arch_timer.h"

void timer_handler(registers_t *r)
{
    /* Increment our 'tick count' */
    timer_ticks++;
    /* Every 18 clocks (approximately 1 second), we will
    *  display a message on the screen */
    /*
    if (timer_ticks % 18 == 0)
    {
        puts("One second has passed\n");
    }
    */

}

void timer_install()
{
    /* Installs 'timer_handler' to IRQ0 */
    irq_install_handler(0, timer_handler);
}

void timer_wait_ticks(uint32_t ticks)
{
    unsigned long eticks;

    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}
void timer_wait_seconds(uint32_t seconds)
{
    unsigned long eticks;

    //times 18, this approx for 18.222Hz
    eticks = timer_ticks + (18 * seconds);
    while(timer_ticks < eticks);
}