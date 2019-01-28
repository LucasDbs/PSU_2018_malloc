#include "malloc.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

struct s_block *block;
static int initialization = 0;

void init_memory()
{
    brk(0); 
    block = sbrk(4096);
    initialization = 1;
}

struct s_block *alloc(size_t size)
{
    struct s_block new;

    new.free = 0;
    new.size = size;
    new.prev;
    new.next;
}

void *t_malloc(size_t size)
{
    if (initialization == 0)
        init_memory();
    // find block
    // allocate size in pointer
    // int free  = 1
    // next -> NULL
    // prev NULL || prev_block

}

void t_free(void *ptr)
{
}