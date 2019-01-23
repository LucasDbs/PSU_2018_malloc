#include "basics.h"
#include <dlfcn.h>
#include <stdio.h>
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

        malloc();
        return 0;
}
