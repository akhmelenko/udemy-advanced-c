#include <stdio.h>

void Test1()
{
#define PRINT(x, y)      \
    printf("x=%d\n", x); \
    printf("y=%d\n", y);

    PRINT(3, 5);
}

void Test2()
{
#define SQR(x) \
    (x) * (x)

    printf("sqr(5+2)=%d\n", SQR(5 + 2));
}

void Test3_VariadicMacro()
{
    // variant 1
#define WARNING1(...) printf(__VA_ARGS__)
    WARNING1("WARNING MESSAGE1: %s", "Test message1");

    // variant 2
#define WARNING2(format, ...) printf(format, __VA_ARGS__)
    WARNING2("WARNING MESSAGE2: %s", "Test message2");

#define SUMM_ALL(...)
}

void TestDefined()
{
#define MY_DEF 0

#if defined(MY_DEF) // == #ifdef MY_DEF
    printf("\nMY_DEF IS DEFINED\n");
#else
    printf("\nMY_DEF IS not DEFINED\n");
#endif
}

void TestConstantString()
{
#define CON_STR(x) #x // now CON_STR(some text) == "some text"
    printf("string=%s\n", CON_STR(Created string));

#define ADD_TO_PRINTF_STR(x) printf("Hello " #x "\n");
    ADD_TO_PRINTF_STR(Karina)

#define PRINT_VAR_NAME_AND_VALUE(var) printf(#var "=%d\n", var);
    int cnt = 7;
    PRINT_VAR_NAME_AND_VALUE(cnt)
}

void TestCodeConcat()
{
#define CONCAT(x, y) x##y
    int ab = 28;
    printf("CONCAT of a and b =%d\n", CONCAT(a, b));
}

#define MAKE_FUNC(fname)                                   \
    int My_##fname(int arg)                                \
    {                                                      \
        printf("test printf make function arg=%d\n", arg); \
    }
MAKE_FUNC(func)

int main()
{
    Test1();
    Test2();
    Test3_VariadicMacro();
    TestDefined();
    TestConstantString();
    TestCodeConcat();
    My_func(3);

    return 0;
};
