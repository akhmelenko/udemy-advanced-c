#include <stdio.h>
#include <conio.h>

void Test(int size, int arr[size])
{
}

int main()
{
    int size = 0;
    printf("Enter array size: ");
    scanf("%zd", &size);
    printf("size=%d\n", size);
    int arr[5];
    for (int i = 0; i < size; i++)
        printf("arr=%d\n", arr[i]);

    return 0;
}