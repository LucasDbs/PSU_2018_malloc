// #include "basics.h"
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// #include <stdlib.h>

int main(int argc, char const *argv[])
{
        // // my_putstr("Hello World!!!\n");
        // void *handle;
        // void *(*functionLib)();
        // char *error;

        // handle = dlopen("libBasics.so", RTLD_LAZY);
        // if (!handle) {
        //         fprintf(stderr, "%s\n", dlerror());
        //         return(-1);
        // }
        // dlerror();
        // *(void **)(&functionLib) = dlsym(handle, "malloc");
        // if ((error = dlerror()) != NULL)  {
        //         fprintf(stderr, "%s\n", error);
        //         return(-1);
        // }
        // // printf("%s\n", (*cosine)("Je fais un test"));
        // (void) functionLib();
        // dlclose(handle);
        // return(0);
        void *old_break;
        char *str;
        int *test;

        old_break = sbrk(0);
        str = sbrk(6);
        strcpy(str, "Hello");
        printf("%s\n", str);
        test = sbrk(4);
        *test = 32;
        printf("%d\n", *test);
        brk(old_break);

        return 0;
}
