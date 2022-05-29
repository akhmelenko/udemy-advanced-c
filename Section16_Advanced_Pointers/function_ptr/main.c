#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int (*funcPtr)(int);

int MyFunc(int x)
{
    return x + x;
}

void Test1()
{
    printf("\nfunc ptrs \n");
    funcPtr = MyFunc;
    printf("res=%d\n", funcPtr(2));
    funcPtr = &MyFunc; // the same as funcPtr = MyFunc;
    printf("res=%d\n", funcPtr(2));
    printf("the same: res=%d\n", (*funcPtr)(2)); // the same as before
    printf("funcPtr addr=%p\n", funcPtr);
}

typedef int (*FuncPtr_t)(int);

int MySquare(int a)
{
    return a * a;
}

int MyCube(int a)
{
    return a * a * a;
}

void Test2()
{
    printf("\ntypedef for func\n");
    FuncPtr_t cube = MyCube;
    printf("cube(5)=%d\n", cube(5));
    FuncPtr_t square = MySquare;
    printf("square(5)=%d\n", square(5));
}

void Test3()
{
    printf("\nsizeof func ptr \n");
    printf("sizeof(FuncPtr_t)=%ld\n", sizeof(FuncPtr_t));
    printf("sizeof(funcPtr)=%ld\n", sizeof(funcPtr));
}

void *OperationFactory(char *operation)
{
    if (!strcmp(operation, "square"))
        return MySquare;
    else if (!strcmp(operation, "cube"))
        return MyCube;
    else
        return NULL;
}

void Test4()
{
    printf("\nfunc factory\n");
    FuncPtr_t pFunc;
    // get a square function
    pFunc = OperationFactory("square");
    if (pFunc == NULL)
    {
        fprintf(stderr, "pFunc() error!\n");
        return;
    }
    printf("square: pFunc(3)=%d\n", pFunc(3));

    // get a cube function
    pFunc = OperationFactory("cube");
    if (pFunc == NULL)
    {
        fprintf(stderr, "pFunc() error!\n");
        return;
    }
    printf("cube: pFunc(3)=%d\n", pFunc(3));

    // try wrong operation
    pFunc = OperationFactory("ttt");
    if (pFunc == NULL)
    {
        fprintf(stderr, "pFunc() error!\n");
        return;
    }
    printf("ttt: pFunc(3)=%d\n", pFunc(3));
}

struct MyData
{
    int key;
    int data;
};

int Compare(const void *a, const void *b)
{
    return ((struct MyData *)a)->key - ((struct MyData *)b)->key;
}

void Test5()
{
    printf("\nuse private compare function for qsort\n");
    struct MyData A[3] = {{5, 55}, {2, 22}, {4, 44}};
    printf("before: A[0]=%d, A[1]=%d, A[2]=%d\n", A[0].data, A[1].data, A[2].data);
    qsort(A, 3, sizeof(struct MyData), Compare);
    printf("after: A[0]=%d, A[1]=%d, A[2]=%d\n", A[0].data, A[1].data, A[2].data);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
};
