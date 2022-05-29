
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void InitArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = i;
}

void PrintArray(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %2d", arr[i]);
    printf(" ]\n");
}

int main()
{
    // init
    int arr[SIZE];
    InitArray(arr, SIZE);
    PrintArray(arr, SIZE);

    printf("No overlap:\n");
    // init
    arr[SIZE];
    InitArray(arr, SIZE);
    memcpy(&arr[SIZE / 4], arr, (SIZE / 2) * sizeof(arr[0]));
    printf("memcpy:\n");
    PrintArray(arr, SIZE);
    // init
    InitArray(arr, SIZE);
    memmove(&arr[SIZE / 4], arr, (SIZE / 2) * sizeof(arr[0]));
    printf("memmove:\n");
    PrintArray(arr, SIZE);

    printf("Overlap:\n");
    // init
    InitArray(arr, SIZE);
    memcpy(&arr[3], arr, (SIZE / 2) * sizeof(arr[0]));
    printf("memcpy:\n");
    PrintArray(arr, SIZE);
    // init
    InitArray(arr, SIZE);
    memmove(&arr[3], arr, (SIZE / 2) * sizeof(arr[0]));
    printf("memmove:\n");
    PrintArray(arr, SIZE);
    return 0;
}
