#include <stdio.h>
#include "source.h"

int var = 9;

void fn1()
{
    printf("fn1() start\n");
    for (volatile int i = 0; i < 0xffffffee; i++)
        ;
    SrcFn1();
}

void fn2()
{
    printf("fn2() start\n");
    for (volatile int i = 0; i < 0xfffff1ee; i++)
        ;
    SrcFn1();
}

int main()
{
    printf("Start main()\n");
    fn1();
    fn2();

    return 0;
};
