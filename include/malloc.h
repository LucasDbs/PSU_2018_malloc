/*
** EPITECH PROJECT, 2019
** Sabri Ouaked
** File description:
** malloc.h
*/

#if !defined(MALLOC_H)
#define MALLOC_H

#include "struct.h"

int align_chunk(size_t size);
void copy_block(size_t, void *, void *);
void *get_base(void);
struct chunk_s *expand_mem(size_t, struct chunk_s *);
int is_chunk_empty(void);
void fusion_chunk(struct chunk_s *chunk);
void split_chunk(struct chunk_s *chunk, size_t size);

#endif
