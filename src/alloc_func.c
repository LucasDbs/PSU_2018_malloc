/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** alloc_func.c
*/

#include "basics.h"

t_block get_block(void *p)
{
        char *tmp;
        tmp = p;
        return (p = tmp -= BLOCK_SIZE);
}

int valid_addr(void *p)
{
        if (base) {
                if (p>base && p<sbrk(0)) {
                        return (p == (get_block(p))->ptr);
                }
        }
        return (0);
}

t_block fusion(t_block b)
{
        if (b->next && b->next->free ) {
                b->size += BLOCK_SIZE + b->next->size;
                b->next = b->next->next;
                if (b->next)
                b->next->prev = b;
        }
        return (b);
}

void split_block(t_block b, size_t s)
{
        t_block new;
        size_t position = b->size - s - BLOCK_SIZE;
        void *move = b->data + s;
        
        new = move;
        new ->size = position;
        new ->next = b->next;
        new ->free = 1;
        b->size = s;
        b->next = new;
}

t_block extend_heap(t_block last, size_t size)
{
        t_block b;
        b = sbrk(0);

        if (sbrk(BLOCK_SIZE + size) == (void*) -1)
                return (NULL);
        b->size = size;
        b->next = NULL;
        if (last)
                last->next = b;
        b->free = 0;
        return (b);
}

t_block find_block(t_block *last, size_t size)
{
        t_block b = base;

        while (b && !(b->free && b->size >= size)) {
                *last = b;
                b = b->next;
        }
        return (b);
}