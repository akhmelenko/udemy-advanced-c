#include <stdio.h>
#include "source.h"
#include <malloc.h>

void fn1()
{
    printf("fn1() start\n");
    for (volatile int i = 0; i < 0xfffffee; i++)
        ;
    SrcFn1();
    int *v1 = malloc(sizeof(int));
}

void fn2()
{
    printf("fn2() start\n");
    for (volatile int i = 0; i < 0xffff1ee; i++)
        ;
    SrcFn1();
    int *v1 = malloc(sizeof(int));
}

int main()
{
    printf("Start main()\n");
    fn1();
    fn2();

    return 0;
};
