//
// Created by dev on 19/03/18.
//

#ifndef OS_MEMORY_H
#define OS_MEMORY_H

#include "types.h"


void memcpy(void* src, void* dest, size_t size);
void memset(void* dst, uint32_t size, uint8_t fill);
void* kalloc(size_t size);
void *memmove(void *dst_void, const void *src_void, size_t length);

#endif //OS_MEMORY_H
