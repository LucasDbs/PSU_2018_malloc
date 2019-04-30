#include "../include/malloc.h"

void *get_base(void)
{
    static struct chunk_s *base = NULL;

    if (!base) {
        base = sbrk(align_chunk(CHUNK_SIZE));
        base->next = NULL;
        base->prev = NULL;
        base->size = 0;
        base->free = 1;
        base->data = NULL;
    }
    return (base);
}

struct chunk_s *expand_mem(size_t lenght, struct chunk_s *prev)
{
    struct chunk_s *new = NULL;
    size_t nb_page = 0;

    nb_page = (lenght / getpagesize()) + 1;
    new = sbrk(nb_page * getpagesize());
    if (new == (void *)-1)
            return (NULL);
    new->next = NULL;
    new->prev = prev;
    new->size = nb_page * getpagesize() - CHUNK_SIZE;
    new->data = new + 1;
    prev->next = new;
    return (new);
}