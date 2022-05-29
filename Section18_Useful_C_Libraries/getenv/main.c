
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    char *value = NULL;
    char *names[] = {"SHELL", "TERM_PROGRAM_VERSION", "WSL_DISTRO_NAME", "NAME", "HOME", "PATH", "LOGNAME", "TOXIC"};

    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        assert(value = getenv(names[i]));
        printf("Value of \"%s Environment Variable\" : %s\n", names[i], value);
    }

    return 0;
}
