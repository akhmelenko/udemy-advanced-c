#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *str = (char *)malloc(20);
    memset(str, 0, 10);
    char *ret = strncpy(str, "linux", strlen("linux") + 1);
    if (ret == NULL)
    {
        fprintf(stderr, "strncpy() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
    printf("%s\n", str);
    free(str);
    str[0] = 'l'; // ! 1) problem!

    char *ptr;
    char c = *ptr; // ! 2) problem!
    printf("c=%c\n", c);

    return 0;
};
