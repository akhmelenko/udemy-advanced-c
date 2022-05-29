
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number arguments\n");
        exit(EXIT_FAILURE);
    }

    printf("atoi=%d\n", atoi(argv[1]));
    printf("atol %ld\n", atol(argv[1]));
    printf("atoll %lld\n", atoll(argv[1]));
    printf("atof=%f\n", atof(argv[1]));
    char *endPtr;
    float fDigit = strtof(argv[1], NULL);
    printf("strtof=%f end symbol=%c\n", fDigit, *endPtr);
    double dDigit = strtod(argv[1], NULL);
    printf("strtod=%f end symbol=%c\n", dDigit, *endPtr);

    char a[] = "       365.5          5.5";
    char *end;
    float val = strtod(a, &end);
    float val2 = strtod(end, NULL);
    printf("val = %f:%f\n", val, val2);

    int base = 16;
    long int lDigit = strtol(argv[1], &end, base);
    printf("strtol(base=%d)=%ld end symbol=%c\n", base, lDigit, *endPtr);
    base = 8;
    lDigit = strtol(argv[1], &end, base);
    printf("strtol(base=%d)=%ld end symbol=%c\n", base, lDigit, *endPtr);
    base = 10;
    lDigit = strtol(argv[1], &end, base);
    printf("strtol(base=%d)=%ld end symbol=%c\n", base, lDigit, *endPtr);
    base = 0;
    lDigit = strtol(argv[1], &end, base);
    printf("strtol(base=%d)=%ld end symbol=%c\n", base, lDigit, *endPtr);
}