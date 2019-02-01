/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** heap_func.c
*/

#include "malloc.h"

void *base_heap(void)
{
        static block_s base = NULL;

        if (!base) {
                base = sbrk(align4(BLOCK_SIZE));
                if (base == (void *)-1)
                        _exit(1);
                base->next = NULL;
                base->prev = NULL;
                base->size = 0;
                base->free = 1;
                base->data = NULL;
        }
        return (base);
}

block_s extend_heap(size_t lenght, block_s prev)
{
        block_s new = NULL;
        size_t nb_page = 0;

        nb_page = (lenght / getpagesize()) + 1;
        new = sbrk(nb_page * getpagesize());
        if (new == (void *)-1)
                return (NULL);
        new->next = NULL;
        new->prev = prev;
        new->size = nb_page * getpagesize() - BLOCK_SIZE;
        new->data = new + 1;
        prev->next = new;
        return (new);
}

int heap_is_empty(void)
{
        block_s base = base_heap();

        while (base) {
                if (base->free == 0)
                        return (0);
                base = base->next;
        }
        return (1);
}