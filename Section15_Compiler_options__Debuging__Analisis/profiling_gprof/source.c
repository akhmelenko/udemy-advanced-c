
#include <stdio.h>
#include "source.h"

void SrcFn1()
{
    printf("SrcFn1() start\n");
    for (volatile int i = 0; i < 0xfffff8ee; i++)
        ;
}