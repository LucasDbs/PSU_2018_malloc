#if !defined(MALLOC_H)
#define MALLOC_H

#include <unistd.h>

<<<<<<< HEAD
// typedef struct s_block * t_block;

// struct s_block {
//         size_t size;
//         t_block next;
//         t_block prev;
//         int free;
//         void *ptr;
//         char data[1];
// };
=======

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
>>>>>>> e1ecb1f2777656e5c7da6a275796ae02270948b9

#endif // MALLOC_H

