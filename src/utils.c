/*
** EPITECH PROJECT, 2019
** Sabri Ouaked
** File description:
** utils.c
*/

#include <stdlib.h>
#include "../include/malloc.h"

int align_chunk(size_t size)
{
    return ((((size - 1) >> 2) << 2) + 4);
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

struct chunk_s *initialize(struct chunk_s **previous, size_t size)
{
    struct chunk_s *base = get_base();

    if (!size) {
        exit(84);
    } else if (!base) {
        return (NULL);
    } else {
        while (base && !(base->free && base->size >= size)) {
                *previous = base;
                base = base->next;
        }
        return (base);
    }
}

