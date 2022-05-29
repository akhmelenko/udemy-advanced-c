#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

int A[SIZE] = {2, 4, 9, 3, 1};
int B[SIZE] = {3, 4, 7, 9, 6};

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    if (b == 0)
        return -1;
    return a / b;
}

typedef int (*Operation_t)(int, int);
Operation_t operations[4] = {Add, Sub, Mul, Div};

int *PerformOp(int *a, int *b, int size, Operation_t operation)
{
    int *result = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        result[i] = operation(a[i], b[i]);
    return result;
}

void PrintResult(int *a, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %d", a[i]);
    printf(" ]\n");
}

int main()
{
    while (1)
    {
        printf("Enter the operation code:\n");
        printf("1: ADD\n");
        printf("2: SUB\n");
        printf("3: MUL\n");
        printf("4: DIV\n");
        printf("5: Quit\n");

        int code;
        scanf("%d", &code);
        printf("chosen code = %d\n", code);
        if (code == 5)
        {
            printf("Exit");
            return -1;
        }

        int *result = PerformOp(A, B, SIZE, operations[code - 1]);
        PrintResult(result, SIZE);
    }
    return 0;
};
