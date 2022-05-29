#include <stdio.h>

// array

// initialize with constants only
// int arr[6] = {[2] = 2, [4] = 4}; // or
// int arr[6] = {[2] 2, [4] 4}; // or
// int arr[6] = {[4] 4, [1 ... 3] 13}; // or
int arr[] = {[4] 4, [1 ... 3] 13, [5] 5, 8, 8, [10] 10}; // or !!! size of array calculated by highest index (size=10+1) !!!

// struct

struct point
{
    int x, y;
};

int main()
{
    // array
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    // struct
    struct point pt1 = {.y = 3, .x = 2};
    struct point pt2 = {x : 3, y : 4};
    struct point pt3 = {4}; // if not specify field name - must be in order

    printf("\npt3.x=%d pt3.y=%d \n", pt3.x, pt3.y);

    struct point arrP[] = {[7].x = 17, [10].y = 20, [15].x = 15, [15].y = 25};
    for (int i = 0; i < sizeof(arrP) / sizeof(arrP[0]); i++)
        printf("arrP[%d].x=%d arrP[%d].y=%d\n", i, arrP[i].x, i, arrP[i].y);

    return 0;
};
