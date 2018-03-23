//
// Created by dev on 20/03/18.
//

#ifndef OS_ARCH_STRING_H
#define OS_ARCH_STRING_H

#include "arch_types.h"

uint16_t strlen(const char* c);
void memcpy(void* src, void* dst , size_t size);
void memset(void* dst, uint32_t size, uint8_t fill);
void *memmove(void *dst_void, const void *src_void, size_t length);


#endif //OS_ARCH_STRING_H
