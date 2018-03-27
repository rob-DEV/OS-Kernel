//
// Created by dev on 26/03/18.
//

#include "include/time.h"

void sleep(uint32_t seconds)
{
    timer_wait_seconds(seconds);
}