#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>

// int car = 5;

void Foo(int *arr)
{
    for (volatile int i = 0; i < 0xffffffff; i++)
    {
        arr[i] = i;
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}

int main()
{
    int arr[5];

    printf("Start main\n");
    Foo(arr);

    return 0;
};
