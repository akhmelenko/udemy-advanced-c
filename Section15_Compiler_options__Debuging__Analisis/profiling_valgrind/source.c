
#include <stdio.h>
#include "source.h"
#include <malloc.h>

void SrcFn1()
{
    printf("SrcFn1() start\n");
    for (volatile int i = 0; i < 0xffff8ee; i++)
        ;
    int *v1 = malloc(sizeof(int));
}