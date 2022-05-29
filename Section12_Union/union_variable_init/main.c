#include <stdio.h>

union Utest
{
    int i;
    float f;
} a, *pA;

int main()
{
    // union Utest a = 33; // compiler error: invalid initializer
    union Utest a = {.i = 30};
    // a.i = 33;
    pA = &a;
    printf("a=%d\n", pA->i);
    printf("f=%f\n", pA->f);

    pA->f = 33.333;
    printf("\na=%d\n", pA->i);
    printf("f=%f\n", pA->f);

    return 0;
};
