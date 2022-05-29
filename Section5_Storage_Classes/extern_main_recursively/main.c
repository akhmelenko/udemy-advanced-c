#include <stdio.h>
#include <conio.h>
#include "double.h"

int x = 5;
float y = 2.0;

int main()
{
    extern int x;

    if (--x)
    {
        printf("x=%d y=%f\n", x, y / 1.5);
        main();
    }

    return 0;
}