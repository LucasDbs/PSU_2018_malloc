/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** basics.c
*/

#include "malloc.h"

void *base=NULL;

void myputchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(const char *str)
{
        write(1, str, strlen(str));
}

int my_strlen(const char *str)
{
        int i = 0;

        while (str[i])
                i++;
        return (i);
}

void *malloc(size_t size)
{
        t_block b, last;
        size_t s = align4(size);

        if (base) {
        /* First find a block */
                last = base;
                b = find_block(&last, s);
                if (b) {
                /* can we split */
                        if ((b->size - s) >= ( BLOCK_SIZE + 4))
                                split_block(b, s);
                        b->free =0;
                } else {
                /* No fitting block , extend the heap */
                        b = extend_heap(last, s);
                        if (!b)
                                return(NULL);
                }
        } else {
        /* first time */
                b = extend_heap(NULL ,s);
                if (!b)
                        return(NULL);
                base = b;
        }
        return(b->data);
}

void free(void *p)
{
        t_block b;

        if (valid_addr(p)) {
                b = get_block(p);
                b->free = 1;
                /* fusion with previous if possible */
                if (b->prev && b->prev->free)
                        b = fusion(b->prev );
                /* then fusion with next */
                if (b->next && b->next->free)
                        fusion(b);
                else {
                /* free the end of the heap */
                        if (b->prev)
                                b->prev->next = NULL;
                        else
                /* No more block !*/
                                base = NULL;
                        brk(b);
                }
        }
 }

void copy_block(t_block src, t_block dst)
{
        int *sdata, *ddata;
        size_t i;

        sdata = src->ptr;
        ddata = dst->ptr;
        for (i=0; i*4<src ->size && i*4<dst ->size; i++)
                ddata[i] = sdata[i];
}

void *realloc(void *p, size_t size)
{
        size_t s;
        t_block b, new;
        void *newp;

        if (!p)
                return (malloc(size));
        if ( valid_addr(p)) {
                s = align4(size);
                b = get_block(p);
                if (b->size >= s) {
                        if (b->size - s >= ( BLOCK_SIZE + 4))
                                split_block (b,s);
                } else {
                /* Try fusion with next if possible */
                        if (b->next && b->next ->free && (b->size + BLOCK_SIZE + b->next ->size) >= s) {
                                fusion(b);
                                if (b->size - s >= ( BLOCK_SIZE + 4))
                                        split_block (b,s);
                        } else {
                        /* good old realloc with a new block */
                                newp = malloc(s);
                                if (!newp)
                                /* we’re doomed ! */
                                        return (NULL );
                                /* I assume this work ! */
                                new = get_block(newp);
                                /* Copy data */
                                copy_block(b,new);
                                /* free the old one */
                                free(p);
                                return (newp);
                        }
                }
                return (p);
        }
        return (NULL);
}