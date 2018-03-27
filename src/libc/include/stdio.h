//
// Created by dev on 23/03/18.
//

#ifndef OS_STDIO_H
#define OS_STDIO_H
#define EOF -1

#include "types.h"
#include "arch.h"

bool print(const char* data, size_t length);
int printf(const char* __restrict format, ...);

#endif //OS_STDIO_H
