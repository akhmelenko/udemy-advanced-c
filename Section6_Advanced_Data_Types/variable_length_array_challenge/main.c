#include <stdio.h>

void PrintArray(int arr[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int main()
{
    printf("Enter array size: \n");
    int size;
    scanf("%d", &size);
    printf("size=%d\n", size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        int val;
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        arr[i] = val;
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    PrintArray(arr, size);

    return 0;
};
