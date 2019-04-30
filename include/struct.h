/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** struct.h
*/

#if !defined(STRUCT_H)
#define STRUCT_H

#include <unistd.h>

#define CHUNK_SIZE sizeof(struct chunk_s)

struct chunk_s
{
    struct chunk_s *next;
    struct chunk_s *prev;
    size_t size;
    int free;
    void *data;
};

void *malloc(size_t);
void free(void *);
void *realloc(void *, size_t);
struct chunk_s *initialize(struct chunk_s **prev, size_t size);

#endif
