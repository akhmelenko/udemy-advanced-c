#include <stdio.h>
#include <malloc.h>
#include <string.h>

void Test1()
{
    int a = 10;
    int *pA = &a;
    int **ppA = &pA;
    printf("a address=%ld, a value=%d\n", (size_t)&a, a);
    printf("pA address=%ld, pA value=%ld, value at the pointing address=%d\n", (size_t)&pA, (size_t)pA, *pA);
    printf("ppA address=%ld, ppA value=%ld, value at the pointing address=%ld, value at the double pointing address=%d\n", (size_t)&ppA, (size_t)ppA, (size_t)*ppA, **ppA);
}

void Set5(int *pInt)
{
    *pInt = 5;
}

void Test2()
{
    printf("\n");
    int *p = (int *)malloc(sizeof(int));
    *p = 3;
    printf("before *p=%d\n", *p);
    Set5(p);
    printf("after *p=%d\n", *p);
}

void AllocArray(int **pp, int size)
{
    *pp = (int *)malloc(sizeof(int) * size);
    (*pp)[3] = 33;
}

void Test3()
{
    printf("\n");
    int *p = NULL;
    AllocArray(&p, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("p[%d]=%d\n", i, p[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        p[i] = i + 1;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("p[%d]=%d\n", i, p[i]);
    }
    free(p);
}

void SetHello(char **pChar)
{
    *pChar = (char *)malloc(255);
    strcpy(*pChar, "Hello");
}

void SetHello2(char **pChar)
{
    *pChar = "Hello2";
}

void SetHello3(char **pChar)
{
    *pChar = strdup("Hello3");
}

void SetHello4(char **pChar)
{
    int size = strlen("Hello4");
    *pChar = strndup("Hello4", size + 1);
}

void Test4()
{
    printf("\n");
    char *pC = NULL;
    SetHello(&pC);
    printf("%s\n", pC);
    free(pC);
    SetHello2(&pC);
    printf("%s\n", pC);
    SetHello3(&pC);
    printf("%s\n", pC);
    free(pC);
    SetHello4(&pC);
    printf("%s\n", pC);
    free(pC);
}

void Test5()
{
#define ROWS 2
#define COLUMNS 3
    printf("\n");
    // create **array
    int **A = (int **)malloc(ROWS * sizeof(int *)); // matrix initial from double pointer at dynamic memory
    for (int i = 0; i < ROWS; i++)
    {
        A[i] = (int *)malloc(COLUMNS);
    }
    // create *pointers array
    int *B[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        B[i] = (int *)malloc(COLUMNS * sizeof(int));
    }
    // create usual array
    int D[ROWS][COLUMNS];                       // matrix initial as matrix on stack
    printf("sizeof(A[0])=%ld\n", sizeof(A[0])); // size of ptr to int
    printf("A=%ld, (A[0])=%ld, (A[1])=%ld, &(A[0][0])=%ld, &(A[0][1])=%ld, &(A[0][2])=%ld, &(A[1][0])=%ld, &(A[1][1])=%ld, &(A[1][2])=%ld\n",
           A, (A[0]), (A[1]), &(A[0][0]), &(A[0][1]), &(A[0][2]), &(A[1][0]), &(A[1][1]), &(A[1][2]));
    printf("sizeof(B[0])=%ld\n", sizeof(B[0])); // size of ptr to int
    printf("sizeof(D[0])=%ld\n", sizeof(D[0])); // size of matrix column
    printf("sizeof(A)=%ld\n", sizeof(A));       // size of double prt
    printf("sizeof(B)=%ld\n", sizeof(B));       // size of array of ptrs
    printf("sizeof(D)=%ld\n", sizeof(D));       // size of 2D array
    A[1][2] = 12;
    printf("A[1][2]=%d\n", A[1][2]);
    B[1][2] = 12;
    printf("B[1][2]=%d\n", B[1][2]);
    D[1][2] = 12;
    printf("D[1][2]=%d\n", D[1][2]);
    for (int i = 0; i < ROWS; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < ROWS; i++)
    {
        free(B[i]);
    }
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
