#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf jmpBuf1;
jmp_buf jmpBuf2;
jmp_buf jmpBuf3;

void Jump1()
{
    int i = 0;
    i = setjmp(jmpBuf1);
    printf("i=%d\n", i);
    if (i != 0)
        return;
    longjmp(jmpBuf1, 45);
    printf("No print this\n");
}

void fn2()
{
    printf("fn2 start\n");
    longjmp(jmpBuf2, 2);
    printf("fn2 stop\n");
}

void fn3()
{
    printf("fn3 start\n");
    longjmp(jmpBuf3, 2);
    printf("fn3 stop\n");
}

void fn1(int n)
{
    printf("fn1 start\n");
    if (n == 2)
        fn2();
    else
        fn3();
    printf("fn1 stop\n");
}

void Jump2()
{
    if (setjmp(jmpBuf2)) // setjmp(jmpBuf2) first time return 0
        printf("Back in main\n");
    else
    {
        printf("First pass\n");
        fn1(2);
    }
}

void Jump3()
{
    switch (setjmp(jmpBuf3))
    {
    case 0:
        printf("no exception\n");
        fn1(3);
        break;
    case 1:
        printf("exception#%d\n", 1);
        break;
    case 2:
        printf("exception#%d\n", 2);
        break;
    default:
        printf("unexpected value returned\n");
    }
}

int main()
{
    Jump1();

    Jump2();

    Jump3();

    return 0;
};
