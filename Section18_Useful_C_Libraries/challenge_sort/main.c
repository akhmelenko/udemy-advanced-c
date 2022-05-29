
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define SIZE 20

void FillArray(double arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (float)rand() / RAND_MAX;
    }
}

void PrintArray(double arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf(" %lf", arr[i]);
    }
    printf(" ]\n");
}

int Compare(const void *a0, const void *a1)
{
    return *(double *)a0 - *(double *)a1 > 0 ? 1 : -1;
}

void SortArray(double arr[], int size)
{
    qsort(arr, size, sizeof(double), Compare);
}

int main()
{
    double arr[SIZE];
    FillArray(arr, SIZE);
    PrintArray(arr, SIZE);
    SortArray(arr, SIZE);
    PrintArray(arr, SIZE);
    return 0;
}
