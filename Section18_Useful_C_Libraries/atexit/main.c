
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void AtExitFoo1()
{
    printf("ExitFoo1 start\n");
}

void AtExitFoo2()
{
    printf("ExitFoo2 start\n");
}

void ExitFoo()
{
    printf("ExitFoo start\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    printf("Main start\n");
    if (atexit(AtExitFoo1) != 0)
    {
        fprintf(stderr, "atexit() error=%d (%s)\n", errno, strerror(errno));
    }
    if (atexit(AtExitFoo2) != 0)
    {
        fprintf(stderr, "atexit() error=%d (%s)\n", errno, strerror(errno));
    }
    // ExitFoo();
    printf("Main end\n");
}