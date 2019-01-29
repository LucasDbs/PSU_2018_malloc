#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
}
