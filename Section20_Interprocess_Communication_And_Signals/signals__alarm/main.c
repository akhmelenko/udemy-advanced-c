#include <stdio.h>
#include <signal.h> //!!!
#include <unistd.h>

// Ctrl+C == SIGINT
// Ctrl+Z == SIGTSTP
// fg or bg == SIGCONT
//
// extern unsigned int alarm (unsigned int __seconds) __THROW;
// extern unsigned int sleep (unsigned int __seconds);

int main()
{
    int ret = alarm(5);
    printf("ret=%d\n", ret);

    for (int i = 0; i < 5; i++)
    {
        // printf("to alarm remain is %d seconds\n", alarm(5 - i));
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
};
