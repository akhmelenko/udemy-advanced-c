
#include <stdio.h>
#include <stdlib.h>

void Foo()
{
    printf("Foo start\n");
    exit(EXIT_FAILURE); // EXIT_FAILURE, EXIT_SUCCESS
    printf("Foo end\n");
}

int main()
{
    printf("Main start\n");
    Foo();
    printf("Main end\n");
}