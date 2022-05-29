#include <stdio.h>
#include "header.h"
#include <limits.h>
#include <assert.h>

void TestPragma1()
{
#pragma GCC poison printf
    // printf("Hello\n"); // error: attempt to use poisoned "printf"
}

void TestPragma2()
{
#pragma GCC warning "Warning message!"
#pragma GCC error "Error message!"
#pragma message "Simple message!"
}

void TestError1_ConditionalCompiledCode()
{
#ifdef OPT1
// Do option
#elif defined OPT2
// Do option
#else
#error *** You must define some option ***
#endif
}

void TestError2_CompilerDependentCode()
{
#if INT_MAX != 0x7fffffff
#error *** This file only works with 16-bit int. Do not use this compiler * **
#endif
}

void TestWarning()
{
#warning My warning message!
}

void TestLineInfo()
{
#line 10 // change line number
    df;  // just error
}

void TestFilename()
{
#define FNAME "test.c"

#line 777 FNAME
    dd; // just error
}

int main()
{
    TestLineInfo();
    TestFilename();
    TestPragma1();
    TestPragma2();
    TestError1_ConditionalCompiledCode();
    TestError2_CompilerDependentCode();
    TestWarning();
    return 0;
};
