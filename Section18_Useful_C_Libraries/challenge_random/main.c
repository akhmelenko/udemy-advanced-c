
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

// make random from -0.5 to 0.5
int main(int argc, char *argv[])
{
    if (argc != 3)
        return -1;
    float min = atof(argv[1]);
    float max = atof(argv[2]);
    srand(time(0));
    for (int i = 0; i < 30; i++)
    {
        float randV = ((float)rand() / RAND_MAX) * (max - min) + min;
        printf("%d : %f\n", i, randV);
    }

    return 0;
}
