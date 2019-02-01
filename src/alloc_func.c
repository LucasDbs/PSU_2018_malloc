/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** alloc_func.c
*/

#include "malloc.h"

block_s find_block(block_s *prev, size_t size)
{
        block_s b = base_heap();

        while (b && !(b->free && b->size >= size )) {
                *prev = b;
                b = b->next;
        }
        return (b);
}

void split_next(block_s block, size_t size)
{
        block_s new = (block_s)((char *) block + size);

        new->next = block->next;
        new->prev = block;
        new->size = block->size - size;
        new->free = 1;
        new->data = new + 1;
        if (block->next)
                block->next->prev = new;
        block->next = new;
        block->size = size - BLOCK_SIZE;
}

void merge_next(block_s b)
{
        b->size +=b->next->size + BLOCK_SIZE;
        b->next = b->next->next;
        if (b->next)
                b->next->prev = b;
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