#include <stdio.h>

// 3 cases: // volatile avoid optimization of variable
// 1) variable can be changed by peripheral
volatile int reg;
// 1.1) repetitions assignments to out;ut buff of peripheral
volatile int *pOutBuf;
*pOutBuf = 3;
*pOutBuf = 4;
// 2) variable can be changed in interrupt
volatile int val;
// 3) variable can be changed in multithreading
volatile int val2;




// if variable can be changed ONLY by peripheral:
const volatile int reg;

int main()
{

    return 0;
}