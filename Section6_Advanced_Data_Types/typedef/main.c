#include <stdio.h>
#include <conio.h>
#include "double.h"

typedef int myInt_t;
typedef float myFloat_t;

int main()
{
    static myInt_t x = 5;
    myFloat_t y = 3.5;

    if (--x)
    {
        printf("x=%d y=%f\n", x, y / 1.5);
        main();
    }

    return 0;
}