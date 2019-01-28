#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/malloc.h"

struct s_block *memory = NULL;
static int initialization = 0;

void init_memory()
{
    printf("test");
    brk(0); 
    memory = sbrk(4096);
    initialization = 1;
}

void allocation(size_t size)
{
    struct s_block new;
    struct s_block *tmp = memory;

    new.free = 0;
    new.size = size;
    new.next = NULL;
    new.data = sbrk(size);
    if (!memory) {
        new.prev = NULL;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = &new;
        tmp = tmp->next;
    }
}

void *t_malloc(size_t size)
{
    if (initialization == 0)
        init_memory();
    allocation(size);
}

void t_free(void *ptr)
{
    struct s_block *tmp = memory;

    memory->prev->next = memory->next;
    brk(memory);
}