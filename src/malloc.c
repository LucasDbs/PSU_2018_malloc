/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** malloc.c
*/

#include "malloc.h"

void *malloc(size_t size)
{
        size_t length = 0;
        block_s prev = NULL;
        block_s block = NULL;

        if (!size)
                return (NULL);
        block = find_block(&prev, size);
        length = align4(BLOCK_SIZE + size);
        if (!block) {
                block = extend_heap(length, prev);
                if (!block)
                        return (NULL);
        }
        if (length + sizeof(size_t) < block->size)
                split_next(block, length);
        block->free = 0;
        return (block->data);
}

void free(void *ptr)
{
        block_s b = NULL;

        if (!ptr || ptr < base_heap() || ptr > sbrk(0))
                return;
        b = (block_s) ptr - 1;
        if (b->data != ptr)
                return;
        b->free = 1;
        if (b->next && b->next->free)
                merge_next(b);
        if (b->prev->free)
                merge_next(b = b->prev);
        if (heap_is_empty()) {
                block_s base = base_heap();
                brk(base->next);
                base->next = NULL;
        }
}

void *realloc(void *ptr, size_t size)
{
        void *new = malloc(size);
        block_s b = NULL;
        size_t length = 0;

        if (new && ptr && ptr >= base_heap() && ptr <= sbrk(0)) {
                b = (block_s) ptr - 1;
                if (b->data == ptr) {
                        length = b->size > size ? size : b->size;
                        copy_block(length, new, ptr);
                        free(ptr);
                }
        }
        return (new);
}
