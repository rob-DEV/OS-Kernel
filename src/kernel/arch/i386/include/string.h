//
// Created by dev on 20/03/18.
//

#ifndef OS_STRING_H
#define OS_STRING_H

#include "types.h"

uint16_t strlen(const char* c);
char* substring(char* str, uint16_t start, uint16_t end);
char* int_to_string(int32_t input);


#endif //OS_STRING_H
