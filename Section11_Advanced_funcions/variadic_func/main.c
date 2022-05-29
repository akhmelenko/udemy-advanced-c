#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

// #include <stdarg.h>
// At least one fixed parameter
// Variadic parameters are at the end

int SumOfIntArgs(int argNumber, ...)
{
    // 1) create variadic parameters variable (set ap PTR)
    va_list ap;
    // 2) init variadic parameters variable
    va_start(ap, argNumber);
    int sum = 0;
    for (int i = 0; i < argNumber; i++)
    {
        // 3) copy current element from variadic parameters variable
        int arg = va_arg(ap, int);
        sum += arg;
    }
    // 4) clean up the variadic parameters variable (reset ap PTR to NULL)
    va_end(ap);
    return sum;
}

int SumOfIntBeforeZero(int dummy, ...)
{
    // 1) create variadic parameters variable (set ap PTR)
    va_list ap;
    // 2) init variadic parameters variable
    va_start(ap, dummy);
    int sum = 0;
    int arg;
    while ((arg = va_arg(ap, int)) != 0)
    {
        sum += arg;
    }
    // 4) clean up the variadic parameters variable (reset ap PTR to NULL)
    va_end(ap);
    return sum;
}

int SumOfDiffsWith_VA_COPY(int argNumber, ...)
{
    // 1) create variadic parameters variable (set ap PTR)
    va_list ap;
    va_list ap2;
    // 2) init variadic parameters variable
    va_start(ap, argNumber);
    va_copy(ap2, ap);

    // make a 1 element shift
    va_arg(ap, int);
    int sum = 0;
    for (int i = 0; i < argNumber - 1; i++)
    {
        // 3) copy current element from variadic parameters variable
        int arg = va_arg(ap, int);
        int arg2 = va_arg(ap2, int);
        printf("arg=%d arg2=%d\n", arg, arg2);
        sum += abs(arg - arg2);
    }
    // 4) clean up the variadic parameters variable (reset ap PTR to NULL)
    va_end(ap);
    va_end(ap2);

    return sum;
}

char *IntToStr(int n)
{
    // get str length
    int temp = n;
    int size = 0;
    while (temp)
    {
        size++;
        temp /= 10;
    }
    char *res = (char *)malloc(size + 1);
    res[size] = '\0';
    for (int i = size - 1; i >= 0; i--)
    {
        res[i] = n % 10 + '0';
        n /= 10;
    }
    return res;
}

// printf only %d parameters
void MyPrintfForInt(const char *format, ...)
{
    va_list va;
    va_start(va, format);
    printf("len=%ld\n", strlen(format));
    for (char i = 0; i < strlen(format); i++)
    {
        if (format[i] == '%')
        {
            if ((i + 1) < strlen(format) && format[i + 1] == 'd')
            {
                int arg = va_arg(va, int);
                char *str = IntToStr(arg);
                for (int j = 0; j < strlen(str); j++)
                    putchar(str[j]);
                i++;
                free(str);
                continue;
            }
            else
            {
                char *buf = "Format error!\n";
                puts(buf);
            }
        }
        putchar(format[i]);
    }
    va_end(va);
}

void FuncQuiz(int n, ...)
{
    int number, i = 0;
    va_list start;
    va_start(start, n);
    while (i != 4)
    {
        number = va_arg(start, int);
        i++;
    }
    printf("%d\n", number);
}

int main()
{
    printf("Sum of 3 integers=%d\n", SumOfIntArgs(3, 10, 20, 30));
    printf("Sum of 5 integers=%d\n", SumOfIntArgs(5, 10, 20, 30, 40, 50));

    printf("Sum of integers before 0 =%d\n", SumOfIntBeforeZero(777777777, 10, 25, 35, 0, 50));

    printf("Sum of integers differences sum=%d\n", SumOfDiffsWith_VA_COPY(3, 10, 25, 30));

    MyPrintfForInt("Hello %d brothers and %d sisters!\n", 46192, 13);

    FuncQuiz(2, 3, 5, 4, 10, 11);

    return 0;
};
