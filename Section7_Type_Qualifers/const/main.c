#include <stdio.h>

void Foo(const int arr[], const int size){ // use const to avoid changes of input data
    ;
}

int main()
{
    const int *ptr; // pointer to the constant value

    int * const ptr; // constant pointer to the value

    const int * const ptr; // constant pointer to the constant value

    int const *ptr; //== const int *ptr;

    return 0;
}