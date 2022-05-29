#include <stdio.h>

void Array(int size)
{
    char arr[size];
    // fill
    for (int i = 0; i < size; i++)
        arr[i] = 'A' + i;
    // print
    for (int i = 0; i < size; i++)
        printf("arr[%d]=%c\n", i, arr[i]);
}

void FillArray(int size, int arr[size], int val)
{
    for (int i = 0; i < size; i++)
        arr[i] = val;
}

void PrintArray(int size, int arr[size])
{
    for (int i = 0; i < size; i++)
        printf("arr[%d]=%d\n", i, arr[i]);
}

int main()
{
#ifdef _STDC_NO_VLA_
    printf("_STDC_NO_VLA_= not supported\n");
#endif

    printf("Enter array size: \n");
    int size;
    scanf("%d", &size);
    printf("size=%d\n", size);
    int arr[size];
    // for (int i = 0; i < size; i++)
    //     printf("arr[%d]=%d\n", i, arr[i]);

    // Array(5);
    FillArray(size, arr[size], 3);
    // PrintArray(size, arr[size]);

    return 0;
};
