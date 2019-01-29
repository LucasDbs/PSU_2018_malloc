#if !defined(MALLOC_H)
#define MALLOC_H

#include <unistd.h>


typedef struct s_block *t_block;
struct s_block
{
    size_t size;
    t_block next;
    t_block prev;
    void *data;
    int free;
};

void free(void *ptr);
void *malloc(size_t size);

#define BLOCK_SIZE sizeof(void *);

#endif // MALLOC_H

