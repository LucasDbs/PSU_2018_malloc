/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** basics.c
*/

#include <unistd.h>
#include <string.h>

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

void malloc(void)
{
        char *str = "Flying cats are the best!!!\n";

        write(2, str, strlen(str));
}
