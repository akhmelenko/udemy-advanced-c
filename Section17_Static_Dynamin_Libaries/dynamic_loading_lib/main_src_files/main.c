
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void LoadMath(float rad)
{
    void *mathLibHandle = dlopen("/lib/x86_64-linux-gnu/libm.so.6", RTLD_LAZY);
    if (mathLibHandle == NULL)
    {
        fprintf(stderr, "dlopen() error=%s\n", dlerror());
        return;
    }

    double (*cosine)(double) = dlsym(mathLibHandle, "cos");
    if (cosine == NULL)
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return;
    }

    printf("cos(2)=%f\n", cosine(rad));

    if (dlclose(mathLibHandle) != 0)
    {
        fprintf(stderr, "dlclose() error=%s\n", dlerror());
        return;
    }
}

int main(int argc, char *argv[])
{
    printf("Main program\n");
    float rad = atof(argv[1]);
    LoadMath(rad);
}