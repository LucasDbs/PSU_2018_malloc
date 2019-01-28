#if !defined(MALLOC_H)
#define MALLOC_H

#include <unistd.h>

struct s_block
{
    size_t size;
    struct s_block *next;
    struct s_block *prev;
    int	free;
    void *data;
} block_t;

#endif // MALLOC_H

