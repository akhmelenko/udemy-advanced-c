#include <stdio.h>
#include <stdbool.h>

struct bits
{
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int : 2; // 2 bits padding
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int : 2; // 2 bits padding
    bool bl : 1;
};

int main()
{
    struct bits b = {.bit1 = 1, .bit2 = 0, .bit3 = 0, .bit4 = 1, .bl = 1};

    printf("struct size=%d b1=%d b2=%d b3=%d b4=%d bl=%d\n", sizeof(struct bits), b.bit1, b.bit2, b.bit3, b.bit4, b.bl);

    unsigned long a = 10;
    a = ~a;
    printf("~a=%x\n", a);
    return 0;
}