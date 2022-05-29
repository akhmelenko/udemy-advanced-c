#include <stdio.h>

// __FILE__ - current file name
// __LINE__ - current line number
// __func__ - current function name
// __DATE__ - date of source file compilation
// __TIME__ - time of source file compilation
// __STDC_ - compiler supports standard C (return 1 if yes)

int main()
{
    printf("file name=%s, line number=%d, func name=%s\n", __FILE__, __LINE__, __func__);
    printf("compilation date=%s, time=%s\n", __DATE__, __TIME__);
    printf("Is compiler supports C standard=%d\n", __STDC__);
    return 0;
};
