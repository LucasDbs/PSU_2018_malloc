/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** basics.h
*/

#if !defined(MALLOC_H)
#define MALLOC_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>

extern void *base;

typedef struct s_block * t_block;
struct s_block {
        size_t size;
        t_block next;
        t_block prev;
        int free;
        void *ptr;
        char data[1];
};

#define BLOCK_SIZE sizeof(struct s_block)
#define align4(x) (((((x)-1)>>2)<<2)+4)

void myputchar(char c);
void my_putstr(const char *);
int my_strlen(const char *);
void *malloc(size_t);
void free(void *);
void *realloc(void *, size_t);

t_block find_block(t_block *last, size_t size);
t_block extend_heap(t_block last, size_t size);
void split_block(t_block b, size_t s);
t_block fusion(t_block b);
int valid_addr(void *p);
t_block get_block(void *p);

#endif // MALLOC_H
