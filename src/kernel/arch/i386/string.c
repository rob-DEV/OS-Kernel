//
// Created by dev on 22/03/18.
//
#include "include/types.h"

uint16_t strlen(const char* c){
    char i;
    uint16_t length = 0;
    while((i = c[length]) != 0){
        length++;
    }
    return length;
}
