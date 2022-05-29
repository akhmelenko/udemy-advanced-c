#include "double.h"

int Double(int a)
{
    extern int x;
    return a + a + x;
}