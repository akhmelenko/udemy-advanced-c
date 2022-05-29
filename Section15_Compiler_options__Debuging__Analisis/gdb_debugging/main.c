#include <stdio.h>
#include "source.h"

int var = 9;

struct person
{
    char name[50];
    int age;
} me = {"Anton", 40};

int main()
{
    int sum = 0;
    sum = Sum();
    printf("sum=%d\n", sum);

    return 0;
};
