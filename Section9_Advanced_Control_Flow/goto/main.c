#include <stdio.h>

extern void PrintA();
int a = 6;

//    *
//   * *
//  *   *
// *     *
//*********

void PrintPiramid(int base)
{
    // other_funk: // error
    int center = base / 2 + 1;
    // lines cycle
    int line = 0;
    int position = 0;
space_cycle:
    // spaces cycle
    printf("-");
    position++;
    if (position != center - line && position != center + line)
        goto space_cycle;
    // star
    printf("*");
    if (position < center)
    {
        position++;
        goto space_cycle;
    }
    printf("\n");
    line++;
    position = 0;
    if (line == base / 2 + 1)
        return;
    goto space_cycle;
}

int main()
{
    int i = 2;

    // goto other_funk; error

    while (1)
    {
        printf("i=%d\n", i);
        if (i > 1000)
            goto label;
        i <<= 1;
    }

label:
    printf("End i=%d\n", i);
    PrintA();
    PrintPiramid(9);

    return 0;
};
