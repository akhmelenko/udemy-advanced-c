#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

//_Noreturn == noreturn (#include <stdnoreturn.h>)

_Noreturn void Foo1(int a)
{
    if (a < 10)
        exit(1);
    // !!! undefined behavior !!!
}

_Noreturn void Foo2()
{
    return;
    // !!! compile error !!!
}

noreturn void MyExit()
{
    printf("MyExit() body\n");
    exit(1);
    // !!! CORRECT !!!
}

int main()
{
    // Foo1(11);
    // Foo2();
    MyExit();
    printf("Must never reach this line\n");
    return 0;
};
