/*
** EPITECH PROJECT, 2019
** Leta && Sensei
** File description:
** malloc.c
*/

#include "malloc.h"

void *malloc(size_t size)
{
    struct chunk_s *previous = NULL;
    struct chunk_s *memory = initialize(&previous, size);
    size_t memory_lenght = 0;

    if (!memory) {
        memory = expand_mem(align_chunk(CHUNK_SIZE + size), previous);
        if (!memory)
            return (NULL);
    }
    memory_lenght = align_chunk(CHUNK_SIZE + size) + sizeof(size_t);
    if (memory_lenght < memory->size)
        split_chunk(memory, align_chunk(CHUNK_SIZE + size));
    memory->free = 0;
    return (memory->data);
}

void free(void *data_ptr)
{
    struct chunk_s *ptr = (struct chunk_s *) data_ptr - 1;
    struct chunk_s * base = get_base();
    
    if (!ptr || ptr < base || ptr > sbrk(0) || ptr->data != data_ptr) {
        return;
    } else {
        ptr->free = 1;
        fusion_chunk(ptr);
    }
    if (is_chunk_empty()) {
        brk(base->next);
        base->next = NULL;
    }
}

void *realloc(void *data_ptr, size_t size)
{
    struct chunk_s *ptr = (struct chunk_s*) data_ptr - 1;
    void *new = malloc(size);
    char *dest = new;
    char *to_cpy = data_ptr;
    size_t len = 0;

    if (!data_ptr || !new || data_ptr > sbrk(0) || data_ptr < get_base()) {
        return (new);
    } else if (ptr->data != data_ptr) {
        return (new);
    } else {
        len = ptr->size > size ? size : ptr->size;
        for (size_t i = 0; i < len; i++, dest++, to_cpy++) {
            *dest = *to_cpy;
        }
        free(data_ptr);
        return (new);
    }
}

