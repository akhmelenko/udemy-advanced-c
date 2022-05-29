
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG // disable assertion, order is important (before #include <assert.h>)
#include <assert.h>

int main(int argc, char *argv[])
{
    int cnt = 0;
    while (++cnt)
    {
        assert(cnt < 200);
        // main: main.c:11: main: Assertion `cnt < 200' failed.
        // Aborted (core dumped)
    }
}