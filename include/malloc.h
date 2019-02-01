/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** malloc.h
*/

#if !defined(BASICS_H_)
#define BASICS_H_

#include <unistd.h>

#define align4(size) (((((size)-1)>>2)<<2)+4)
#define BLOCK_SIZE sizeof(struct block)

typedef struct block * block_s;
struct block {
        block_s next;
        block_s prev;
        size_t size;
        long int free;
        void *data;
};

void *malloc(size_t);
void free(void *);
void *realloc(void *, size_t);

void split_next(block_s, size_t);
void merge_next(block_s);
block_s find_block(block_s *, size_t);
void copy_block(size_t, void *, void *);

void *base_heap(void);
block_s extend_heap(size_t, block_s);
int heap_is_empty(void);

#endif // BASICS_H_
