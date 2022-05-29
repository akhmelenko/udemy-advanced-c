
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG // disable assertion, order is important (before #include <assert.h>)
#include <assert.h>
#include <limits.h>

// static_assetr() - used in C11
static_assert(CHAR_MIN == 0, "Type char is a signed type. Code won't work.");
static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main(int argc, char *argv[])
{
    return 0;
}