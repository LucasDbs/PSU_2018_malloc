/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** malloc.c
*/

// export LD_PRELOAD=$PWD/libmy_malloc.so

#include "../include/malloc.h"

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
        split_next(memory, align_chunk(CHUNK_SIZE + size));
    memory->free = 0;
    return (memory->data);
}

void fusion_chunk(struct chunk_s *chunk)
{
    if (chunk->next && chunk->next->free) {
        chunk = chunk;
    } else if (chunk->prev->free) {
        chunk = chunk->prev;
    } else {
        return;
    }
    chunk->size += chunk->next->size + CHUNK_SIZE;
    chunk->next = chunk->next->next;
    if (chunk->next)
        chunk->next->prev = chunk;
}

int is_chunk_empty(void)
{
    struct chunk_s *base = get_base();
    
    while (base) {
        if (base->free == 0)
            return 0;
        base = base->next;
    }
    return (1);
}


void free(void *data_ptr)
{
    struct chunk_s *ptr = (struct chunk_s *) data_ptr - 1;;
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

void *realloc(void *ptr, size_t size)
{
    void *new = malloc(size);
    struct chunk_s *b = NULL;
    size_t length = 0;

    if (new && ptr && ptr >= get_base() && ptr <= sbrk(0)) {
        b = (struct chunk_s*) ptr - 1;
        if (b->data == ptr) {
            length = b->size > size ? size : b->size;
            copy_block(length, new, ptr);
            free(ptr);
        }
    }
    return (new);
}

