
#include "source.h"

int varHeader = 19;

int Sum()
{

    int var = 29;
    int buf[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i >= 0; i++)
    {
        sum += buf[i]; // seg fault
    }
}