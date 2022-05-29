#include <stdio.h>
#include <malloc.h>
#include <complex.h>
#include <math.h>

int main()
{

#ifdef _STDC_NO_COMPLEX_
    printf("_STDC_NO_COMPLEX_ is defined");
#else
    printf("_STDC_NO_COMPLEX_ is supported\n");
#endif

    double _Complex z1 = 2.0 / 3.0 + 3.5 * I;
    // double _Imaginary i1;
    double complex z2 = 3.77 - 2 * I;
    // double imaginary i2 *I;
    double complex res;

    printf("creal(z1) = %f\n", creal(z1));
    printf("cimag(z1) = %f cimag(conj(z1))=%f\n", cimag(z1), cimag(conj(z1)));
    printf("creal(z2) = %f\n", creal(z2));
    printf("cimag(z2) = %f\n", cimag(z2));

    printf("crealf(z1) = %e\n", crealf(z1));
    printf("cimagf(z1)=%f cimagf(conjf(z1))=%f\n", cimagf(z1), cimagf(conjf(z1)));
    printf("crealf(z2) = %f\n", crealf(z2));
    printf("cimagf(z2) = %f\n", cimagf(z2));

    printf("creall(z1) = %Le\n", creall(z1));
    printf("cimagl(z1)=%Le cimagl(conjl(z1))=%Lf\n", cimagl(z1), cimagl(conjl(z1)));
    printf("creall(z2) = %Le\n", creall(z2));
    printf("cimagl(z2) = %Lf\n", cimagl(z2));

    res = z1 + z2;
    printf("\nres = z1 + z2: creal(res)=%f cimag(res)=%f\n", creal(res), cimag(res));
    res = z1 - z2;
    printf("res = z1 - z2: creal(res)=%f cimag(res)=%f\n", creal(res), cimag(res));
    res = z1 * z2;
    printf("res = z1 * z2: creal(res)=%f cimag(res)=%f\n", creal(res), cimag(res));
    res = z1 / z2;
    printf("res = z1 / z2: creal(res)=%f cimag(res)=%f\n", creal(res), cimag(res));
    // res = cpow(z1, z2);
    // printf("res = cpow(z1, z2): creal(res)=%f cimag(res)=%f\n", creal(res), cimag(res));

    res++;
    printf("res++: creal(res)=%.2f cimag(res)=%.2f\n", creal(res), cimag(res));
    res++;
    printf("res++: creal(res)=%.2f cimag(res)=%.2f\n", creal(res), cimag(res));
    res = !res;
    printf("!res: creal(res)=%.2f cimag(res)=%.2f\n", creal(res), cimag(res));

    res = cexp(3.14 * I);
    printf("cexp(acos(-1) * I): creal(res)=%.2f cimag(res)=%.2f\n", creal(res), cimag(res));
    return 0;
};
