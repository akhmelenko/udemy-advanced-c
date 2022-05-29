#include <stdio.h>
#include <malloc.h>

struct Flex
{
    // int arr0[]; // can not be a first or single member of struct
    int size;
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
    int desiredArraySize;

    printf("Enter the array size: ");
    scanf("%d", &desiredArraySize);

    // Can only use struct with flexible array member  *** ONLY WITH DYNAMIC MEMORY ALLOCATOIN ***
    struct Flex *pFlex = (struct Flex *)malloc(sizeof(struct Flex) + desiredArraySize * sizeof(int));
    struct Other other;

    other.b = 1;
    other.c = 2;
    // other.fl[0] = 3; // can be only pointer
    pFlex->size = desiredArraySize;
    // fill
    for (int i = 0; i < pFlex->size; i++)
        pFlex->arr[i] = (i + 1) * 10;
    // print
    for (int i = 0; i < pFlex->size; i++)
        printf("arr[%d]=%d\n", i, pFlex->arr[i]);

    free(pFlex);

    return 0;
};
