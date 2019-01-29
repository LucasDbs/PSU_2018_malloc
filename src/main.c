/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/basics.h"

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


int main(int argc, char const *argv[])
{
        char *test = malloc(sizeof(char) * 10);
        char *str = malloc(sizeof(char) * 12);
        // int *a = malloc(sizeof(int));

        test = "HelLO WO\n";
        str = "CA ME LES CASS\n";
        // *a = 12;
        my_putstr(test);
        my_putstr(str);
        free(test);
        return 0;
}
