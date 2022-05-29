#include <stdio.h>

int main()
{
    char *buf = "My_buf_string";
    *(buf + 1) = 'S';

    return 0;
};
