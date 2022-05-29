#include <stdio.h>
#include <malloc.h>

struct Flex
{
    // int arr0[]; // can not be a first or single member of struct
    int a;
    // int arr0[]; // can not be more then 1 flex member in struct

    // *** USE ONLY WITH DYNAMIC MEMORY ALLOCATOIN ***
    int arr[]; // can be only last member of struct
};

struct Other
{
    int b;
    struct Flex fl; // restricted use struct with flexible array member as member of other struct
    int c;
};

// struct Flex fl = {0}; // restricted static initialization

int main()
{
    int desiredArraySize = 5;
    // Can only use struct with flexible array member  *** ONLY WITH DYNAMIC MEMORY ALLOCATOIN ***
    struct Flex *pFlex = (struct Flex *)malloc(sizeof(struct Flex) + desiredArraySize * sizeof(int));
    struct Other other;

    other.b = 1;
    other.c = 2;
    // other.fl[0] = 3; // can be only pointer
    pFlex->a = 1;
    pFlex->arr[0] = 10;
    pFlex->arr[1] = 20;
    pFlex->arr[2] = 30;
    pFlex->arr[3] = 40;
    pFlex->arr[4] = 50;

    free(pFlex);

    return 0;
};
