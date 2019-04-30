/*
** EPITECH PROJECT, 2019
** Sabri Ouaked && Sensei
** File description:
** chunk.c
*/

#include "malloc.h"

void *get_base(void)
{
    static struct chunk_s *base = NULL;

    if (base)
        return (base);
    base = sbrk(align_chunk(CHUNK_SIZE));
    base->next = NULL;
    base->prev = NULL;
    base->size = 0;
    base->free = 1;
    base->data = NULL;
    return (base);
}

struct chunk_s *expand_mem(size_t lenght, struct chunk_s *prev)
{
    struct chunk_s *new = NULL;
    size_t nb_page = 0;

    nb_page = (lenght / getpagesize()) + 1;
    new = sbrk(nb_page * getpagesize());
    if (new == (void *)-1)
            return (NULL);
    new->next = NULL;
    new->prev = prev;
    new->size = nb_page * getpagesize() - CHUNK_SIZE;
    new->data = new + 1;
    prev->next = new;
    return (new);
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

void split_chunk(struct chunk_s *chunk, size_t size)
{
    char *precision = (char *)chunk + size;
    struct chunk_s *new = (struct chunk_s*)precision;

    new->prev = chunk;
    new->next = chunk->next;
    new->free = 1;
    new->size = chunk->size - size;
    new->data = new + 1;
    if (chunk->next)
        chunk->next->prev = new;
    chunk->next = new;
    chunk->size = size - CHUNK_SIZE;
}