//const
// Created by dev on 20/03/18.
//

#include "../include/string.h"
uint16_t strlen(const char* c){
    char i;
    uint16_t length = 0;
    while((i = c[length]) != 0){
        length++;
    }
    return length;
}