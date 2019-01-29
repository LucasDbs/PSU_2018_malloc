#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/malloc.h"

struct s_block *memory = NULL;

void init_mem()
{
    memory = sbrk(0);
    sbrk(4096);
    memory->next = NULL;
    memory->prev = NULL;
    memory->free = 0;
    memory->size = 4096;
}

t_block split_block(t_block block, size_t size)
{
    t_block new;

    size_t position = memory->size - size - BLOCK_SIZE;
    new->data = memory->data + (void *)size;
    new->size = position;
    memory->data = brk(position);
}

void add_in_memory(t_block block)
{
    t_block tmp = memory;
    if (!memory) {
        init_mem();
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = block;
        block->prev = tmp;
    }
}

void *malloc(size_t size)
{
    t_block block = sbrk(0);



    add_in_memory(block);
    return block->data;
}

void free(void *ptr)
{
    t_block tmp = memory;
    t_block save;

    while (tmp->next != ptr && tmp->next != NULL)
        tmp = tmp->next;
    if (!tmp)
        return;

    save = tmp->next;    
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    if (brk(save) == -1)
        printf("error");
}
