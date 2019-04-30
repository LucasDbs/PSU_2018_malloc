/*
** EPITECH PROJECT, 2019
** Sabri Ouaked
** File description:
** search.c
*/
#include <stdlib.h>
#include "../include/malloc.h"

int align_chunk(size_t size)
{
    return ((((size - 1) >> 2) << 2) + 4);
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

