#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    printf("Add 6 + 8 = %d\n", Add(6, 8));
    printf("Add 3 + 5 = %d\n", Add(3, 5));
    return 0;
};
