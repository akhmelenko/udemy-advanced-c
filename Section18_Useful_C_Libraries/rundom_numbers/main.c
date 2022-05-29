
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SimpleRandom()
{
    printf("\nSimple Random:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("rand=%d\n", rand());
    }
}

void SeedRandom()
{
    printf("\nSeed Random:\n");
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        printf("rand=%d\n", rand());
    }
}

void RandomInRange(float min, float max)
{
    printf("\nSeed Range Random:\n");
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        float rv = ((float)rand() / RAND_MAX) * (max - min) + min;
        printf("rand=%f\n", rv);
    }
}

int main()
{
    printf("RAND_MAX=%d\n", RAND_MAX);
    SimpleRandom();
    SeedRandom();
    RandomInRange(2.5, 7.3);
}