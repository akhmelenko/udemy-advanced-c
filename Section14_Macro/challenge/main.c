#include <stdio.h>

// __FILE__ - current file name
// __LINE__ - current line number
// __func__ - current function name
// __DATE__ - date of source file compilation
// __TIME__ - time of source file compilation
// __STDC_ - compiler supports standard C (return 1 if yes)

void PredefMacro()
{
    printf("file name=%s, line number=%d, func name=%s\n", __FILE__, __LINE__, __func__);
    printf("compilation date=%s, time=%s\n", __DATE__, __TIME__);
    printf("Is compiler supports C standard=%d\n", __STDC__);
}

#define SUM(x, y) (x + y)
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define IS_ALPHA(a)                                       \
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) \
        printf("%c is alpha\n", a);                       \
    else                                                  \
        printf("%c is not alpha\n", a);

#define IS_UPPER(a)                 \
    if (a >= 'A' && a <= 'Z')       \
        printf("%c is upper\n", a); \
    else                            \
        printf("%c is not upper\n", a);

#define IS_LOW(a)                 \
    if (a >= 'a' && a <= 'z')     \
        printf("%c is low\n", a); \
    else                          \
        printf("%c is not low\n", a);

#define IS_DIGIT(a)                 \
    if (a >= '0' && a <= '9')       \
        printf("%c is digit\n", a); \
    else                            \
        printf("%c is not digit\n", a);

int main()
{
    PredefMacro();
    int sum = SUM(3, -9);
    int square = SQUARE(-3);
    int cube = CUBE(-3);
    printf("sum=%d square=%d cube=%d\n", sum, square, cube);

    IS_ALPHA('r')
    IS_ALPHA('4')

    IS_UPPER('r')
    IS_UPPER('R')

    IS_LOW('s')
    IS_LOW('S')

    IS_DIGIT('8')
    IS_DIGIT('Z')

    return 0;
};
