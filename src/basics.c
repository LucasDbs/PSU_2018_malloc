/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** basics.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

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

// void malloc(void)
// {
//         // my_putstr("TEST\n");
//         // void *ptr;

//         // brk(ptr);
//         // my_putstr("adresse renvoyé par brk: %p\n", ptr);
//         // sbrk(10);
//         // printf("adresse renvoyé par brk +10: %p\n", ptr);
//         // sbrk(-10);
//         // printf("adresse renvoyé par brk -10: %p\n", ptr);
// }
