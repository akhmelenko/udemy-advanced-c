#include <stdio.h>

int f1()
{
    printf("I f1()\n");
    return 1;
}

int f2()
{
    printf("I f2()\n");
    return 2;
}

int main()
{
    int i = 0;
    int sum = 0;
    int data[] = {[0] 5, [4] 8};
    while (i < 5)
        sum += data[i], i++; //!!!!
    printf("sum=%d\n", sum);

    int b = (1, 4); // b=4
    printf("b=%d\n", b);

    int x = (f1(), f2());
    printf("x=%d\n", x);

    for (int j = 0, k = 10; j < 3; j++, k--)
    {
        printf("j=%d k=%d\n", j, k);
    }

    printf("One"),
        printf("Two"),
        printf("Stop");

    // int price = 25, 40; // equal int price = 25; 40;

    return 0;
};
