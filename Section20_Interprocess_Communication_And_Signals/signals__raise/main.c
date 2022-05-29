#include <stdio.h>
#include <signal.h> //!!!

// Ctrl+C == SIGINT
// Ctrl+Z == SIGTSTP
// fg or bg == SIGCONT
//
// int raise(int sig);
// return 0 if no error
// return non 0 if error

int main()
{
    printf("Main Start\n");
    int ret = raise(SIGSTOP);
    printf("ret=%d\n", ret);

    printf("Main Finished\n");

    return 0;
};
