<<<<<<< HEAD
/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** main.c
*/

=======
#include <dlfcn.h>
>>>>>>> e1ecb1f2777656e5c7da6a275796ae02270948b9
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

<<<<<<< HEAD

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
=======
int main()
{
        printf("inside malloc test\n");
        char *str = malloc(sizeof(char) * 4);

        str[0] = '1';
        str[1] = '2';
        str[2] = '3';
        str[3] = '\0';

        char *str2 = malloc(sizeof(char) * 4);

        str2[0] = '4';
        str2[1] = '5';
        str2[2] = '6';
        str2[3] = '\0';

        printf("str = %s\n", str);

        printf("str = %s\n", str2);
    return 0;
>>>>>>> e1ecb1f2777656e5c7da6a275796ae02270948b9
}
