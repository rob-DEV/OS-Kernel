//
// Created by dev on 22/03/18.
//
#include "include/arch_types.h"

uint16_t strlen(const char* c){
    char i;
    uint16_t length = 0;
    while((i = c[length]) != 0){
        length++;/* This exists in 'start.asm', and is used to load our IDT */
extern void idt_load();
    }
    return length;
}

void memcpy(void* src, void* dst , size_t size){
    uint8_t* bsrc = (uint8_t*)src;
    uint8_t* bdst = (uint8_t*)dst;
    for(size_t i = 0; i < size; i++){
        bdst[i] = bsrc[i];
    }
}

void memset(void* dst, uint32_t size, uint8_t fill){
    for(uint32_t i = 0; i < size; i++){
        ((uint8_t*)dst)[i] = fill;
    }
}
void *memmove(void *dst_void, const void *src_void, size_t length) {
    char *dst = (char*)dst_void;
    const char *src = (const char*)src_void;

    if (src < dst && dst < src + length)
    {
        /* Have to copy backwards */
        src += length;
        dst += length;
        while (length--)
        {
            *--dst = *--src;
        }
    }
    else
    {
        while (length--)
        {
            *dst++ = *src++;
        }
    }

    return dst_void;
}