
#include <stdio.h>
#include <stdlib.h>

void Foo()
{
    printf("Foo start\n");
    abort();
    printf("Foo end\n");
}

void WaitAbortSignal()
{
    printf("WaitAbortSignal start\n");
    while (1)
        ;
    printf("WaitAbortSignal end\n");
}

int main()
{
    printf("Main start\n");
    // Foo();
    WaitAbortSignal();
    printf("Main end\n");
}