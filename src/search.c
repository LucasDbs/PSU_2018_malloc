/*
** EPITECH PROJECT, 2019
** Sabri Ouaked
** File description:
** search.c
*/

#include "../include/malloc.h"

void split_next(struct chunk_s *chunk, size_t size)
{
    char *precision = (char *)chunk + size;
    struct chunk_s *new = (struct chunk_s*)precision;

    new->next = chunk->next;
    new->prev = chunk;
    new->size = chunk->size - size;
    new->free = 1;
    new->data = new + 1;
    if (chunk->next)
        chunk->next->prev = new;
    chunk->next = new;
    chunk->size = size - CHUNK_SIZE;
}

void copy_block(size_t length, void *new, void *ptr)
{
    char *dst = new;
    char *src = ptr;
    size_t i = 0;

    while (i < length) {
        *dst = *src;
        dst++;
        src++;
        i++;
    }
}