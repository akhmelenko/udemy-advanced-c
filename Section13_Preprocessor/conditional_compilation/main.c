#include <stdio.h>

void Test1()
{
#define MY_DEF 5
#define OTHER_DEF 2

#if MY_DEF == 5 && OTHER_DEF == 2
    printf("5\n");
#else
    printf("not5\n");
#endif

#undef MY_DEF // undefined to zero
#if MY_DEF == 0 && OTHER_DEF == 2
    printf("0\n");
#else
    printf("not5\n");
#endif
}

void Test2()
{
#define UK 1
#define France 2
#define Gemany 3
#define Country Germany

#if Country == UK
#define Greeting "Hello"
#elif Country == France
#define Greeting "Bonjour"
#elif Country == Germany
#define Greeting "Guten Tag"
#endif

    printf(Greeting);
}

int main()
{
    Test1();
    Test2();
    return 0;
};
