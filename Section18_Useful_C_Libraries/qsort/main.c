
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareInt(const void *elem0, const void *elem1)
{
    return *(int *)elem0 - *(int *)elem1;
}

void SortInt(int argc, char *argv[])
{
    int size = argc - 1;
    int arr[size];
    printf("Initial order:");
    for (int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 1]);
        printf(" %d", arr[i]);
    }
    printf("\n");

    // sort
    qsort(arr, size, sizeof(int), CompareInt);

    printf("Final order:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int CompareString(const void *str0, const void *str1) // mean double pointers to char
{
    int res = strcmp(*(char **)str0, *(char **)str1);
    // printf("%s %s %d\n", *(char **)str0, *(char **)str1, res);
    return res;
}

void SortString(int argc, char *argv[])
{
    // sort
    qsort(&argv[1], argc - 1, sizeof(char *), CompareString);

    printf("Final order:");
    for (int i = 1; i < argc; i++)
    {
        printf(" %s", argv[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Enter more arguments\n");
        exit(EXIT_FAILURE);
    }

    // SortInt(argc, argv);
    SortString(argc, argv);
}