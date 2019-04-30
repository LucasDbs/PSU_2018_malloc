#include <stdio.h>
#include "malloc.h"

int main(int argc, char const *argv[])
{
    char *str = malloc(sizeof(char) * 5);

    str[0] = 't';
    str[1] = 'e';
    str[2] = 's';
    str[3] = 't';
    str[4] = '\0';

    printf("%s\n", str);
    return 0;
}
