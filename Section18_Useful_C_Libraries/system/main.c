
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // char *cmd = "ls -all";
    // cmd fill
    char cmd[50] = {0};
    for (int i = 1; i < argc; i++)
    {
        printf("argv[%d]=%s\n", i, argv[i]);
        strcat(cmd, argv[i]);
        strcat(cmd, " ");
    }
    printf("cmd=%s\n", cmd);
    int ret;
    if ((ret = system(cmd)) == -1)
    {
        fprintf(stderr, "system() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
    printf("system() return=%d\n", ret);

    return 0;
}
