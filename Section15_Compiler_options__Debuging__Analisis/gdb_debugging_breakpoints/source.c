
#include <stdio.h>
#include "source.h"
#include <malloc.h>

int varHeader = 19;

int Sum(int startSum)
{
    int *val = (int *)malloc(sizeof(int) * 5);
    val[2] = 22;
    int var = 29;
    int buf[5] = {1, 2, 3, 4, 5};
    int sum = startSum;
    for (int i = 0; i >= 0; i++)
    {
        sum += buf[i]; // seg fault
        printf("i=%d sum=%d\n", i, sum);
    }
}