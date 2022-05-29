#include <stdio.h>

// "restrict" use only with pointers, to compyler optimization if memory not overlapse with any variable or pointer in scope

int arr[10] = {0}; // overlaps with pArr
int *pArr = arr; // overlaps with arr[]

// example
void* memcpy(void restrict *dest, void restrict *src, int cnt);
void* memmove(void *dest, void *src, int cnt);

int main()
{

    int restrict *r = (int*)malloc(3 * sizeof(int));

    arr[0] = 15;
    *pArr++;

    r[0] = 5; // can be optimized to r[0] = 7;

    arr[0] += 7;

    r[0] += 2; // can be optimized to r[0] = 7;

    return 0;
}