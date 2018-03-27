//
// Created by dev on 26/03/18.
//

#ifndef OS_MEMORY_H
#define OS_MEMORY_H

#include "types.h"

typedef struct memory_chunk {
    memory_chunk *next;
    memory_chunk *prev;
    bool allocated;
    size_t size;
} memory_chunk_t;

static size_t heap_start;
static size_t heap_size;

static memory_chunk_t* first;


void* operator new(size_t size);
void* operator new[](size_t size);

void heap_install(size_t start, size_t size);

void* malloc(size_t size);
void free(void* ptr);

#endif //OS_MEMORY_H
