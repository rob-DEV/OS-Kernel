//
// Created by dev on 26/03/18.
//
#include "include/memory.h"
#include <cstdlib.h>

void heap_install(size_t start, size_t size){

    if(size < sizeof(memory_chunk_t)){
        first = NULL;
    }
    else
    {
        first = (memory_chunk_t*)start;
        first->allocated = false;
        first->prev = NULL;
        first->next = NULL;
        first->size = size - sizeof(memory_chunk_t);
    }

}

void* malloc(size_t size) {

    memory_chunk_t* allocation_result = NULL;

    for(memory_chunk_t* chunk = first; chunk != NULL && allocation_result == NULL; chunk = chunk->next)
        if(chunk->size > size && !chunk->allocated)
            allocation_result = chunk;

    //no free heap memory / bug (more likely a bug)
    if(allocation_result == NULL)
        return NULL;

    if(allocation_result->size >= size + sizeof(memory_chunk_t) + 1)
    {
        memory_chunk_t* temp_chunk = (memory_chunk_t*)((size_t)allocation_result + sizeof(memory_chunk_t) + size);
        temp_chunk->allocated = false;
        temp_chunk->size = allocation_result->size - size - sizeof(memory_chunk_t);
        temp_chunk->prev = allocation_result;
        temp_chunk->next = allocation_result->next;

        if(temp_chunk->next != NULL)
            temp_chunk->next->prev=temp_chunk;

        allocation_result->size = size;
        allocation_result->next = temp_chunk;
    }

    allocation_result->allocated = true;

    //return a pointer to the data alloc start address
    //to do this get the result - memory header (memory_chunk_t)
    return (void*)(((size_t)(allocation_result) + sizeof(memory_chunk_t)));
}

void free(void* ptr){
    //this is the reverse of malloc()

    //find the memory chunk -> address of data - sizeof(memory_chunk_t) == chunk start address
    memory_chunk_t* chunk = (memory_chunk_t*)((size_t)ptr - sizeof(memory_chunk_t));
    //deallocate the memory
    chunk->allocated = false;

    uint32_t* chunk_data_ptr = (uint32_t*)chunk + sizeof(memory_chunk_t);


    printf("Chunk Address: 0x%x\n", chunk);
    printf("Space between struct and data (16): Actually: %d\n", ((uint32_t)ptr - (uint32_t)chunk));
    printf("Freeing Data at: 0x%x\n", (uint32_t)ptr);

    uint32_t* data_address = (uint32_t*)ptr;
    //TEST NULLIFY ALL MEMORY
    for (int i = 0; i < chunk->size; ++i) {
        *data_address = 0;
        data_address++;
    }

    if(chunk->prev != NULL && !chunk->prev->allocated)
    {
        chunk->prev->next = chunk->next;
        chunk->prev->size += chunk->size + sizeof(memory_chunk_t);

        if(chunk->next != NULL)
            chunk->next->prev = chunk->prev;

        chunk = chunk->prev;
    }

    if(chunk->next != NULL && !chunk->next->allocated){
        chunk->size += chunk->next->size + sizeof(memory_chunk_t);
        chunk->next = chunk->next->next;
        if(chunk->next != NULL)
            chunk->next->prev = chunk;
    }
}

void* operator new(size_t size) {

    void* allocation_result = malloc(size);
    if(allocation_result == NULL)
        return NULL;
    return allocation_result;
}
void* operator new[](size_t size) {
    void* allocation_result = malloc(size);
    if(allocation_result == NULL)
        return NULL;
    return allocation_result;
}

void operator delete(void* ptr)
{
    free(ptr);
}

void operator delete[](void* ptr)
{
    free(ptr);
}

void operator delete(void* ptr, unsigned long size)
{
    free(ptr);
}