#include <stdio.h>

int main()
{

    int a0[] = {[0] 6, [1 ... 5] 8, [6] 0};
    int b0[10];

    int *a = a0;
    int *b = b0;

    //!!!!!
    while ((*b++ = *a++) != '\0')
        ;
    //!!!

    for (int i = 0; i < 10; i++)
    {
        printf("b0[%d]=%d\n", i, b0[i]);
    }

    //!!! find index of the first "d"
    char c[20] = "hello and welcome!";
    int i = 0;
    for (; c[i] != 'd'; i++)
        ;
    printf("index of 'd' = %d\n", i);

    return 0;
};
