#include <stdio.h>
#include <signal.h> //!!!
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Ctrl+C == SIGINT
// Ctrl+Z == SIGTSTP
// fg or bg == SIGCONT
//
// extern unsigned int alarm (unsigned int __seconds) __THROW;
// extern unsigned int sleep (unsigned int __seconds);
// extern __sighandler_t signal (int __sig, __sighandler_t __handler)

int ret;

void HandlerAlarm(int signum)
{
    printf("Handler signal=%d\n", signum);
    ret = 1;
}

void Test1()
{
    // set alarm
    int res = alarm(3);
    printf("res=%d\n", res);
    // set handler fot alarm
    __sighandler_t res_ = signal(SIGALRM, HandlerAlarm);
    if (res_ == SIG_ERR)
    {
        fprintf(stderr, "signal() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("res_=%p\n", res_);

    while (!ret)
    {
        sleep(1);
        printf("tick\n");
    }
}

void Test2Ignoring()
{
    // set alarm
    int res = alarm(3);
    printf("res=%d\n", res);
    // set handler fot alarm (inoring)
    __sighandler_t res_ = signal(SIGALRM, SIG_IGN);
    if (res_ == SIG_ERR)
    {
        fprintf(stderr, "signal() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("res_=%p\n", res_);

    while (!ret)
    {
        sleep(1);
        printf("tick\n");
    }
}

void Test3Default()
{
    // set alarm
    int res = alarm(3);
    printf("res=%d\n", res);
    // set handler fot alarm (inoring)
    __sighandler_t res_ = signal(SIGALRM, SIG_DFL);
    if (res_ == SIG_ERR)
    {
        fprintf(stderr, "signal() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("res_=%p\n", res_);

    while (!ret)
    {
        sleep(1);
        printf("tick\n");
    }
}

void HandlerDivZero(int signum)
{
    printf("HandlerDivZero signal=%d\n", signum);
    exit(0);
}

void Test4DivZero()
{
    int x = 4;
    int y = 0;
    void (*sigHandRet)(int);
    sigHandRet = signal(SIGFPE, HandlerDivZero);
    int res = x / y; // exception
}

void HandlerWithCommand(int sigNum)
{
    printf("signal=%d received\n", sigNum);
enter_cmd:
    printf("Enter the command: 1 - new signal, 2 - exit\n");
    int cmd;
    scanf("%d", &cmd);
    if (cmd != 1 && cmd != 2)
    {
        printf("Wrong cmd!\n");
        goto enter_cmd;
    }
    if (cmd == 1)
    {
        printf("sending a new signal\n");
        raise(SIGINT);
    }
    if (cmd == 2)
    {
        printf("Exiting\n");
        exit(0);
    }
}

void Test5UserCommandBySignal()
{
    alarm(3);
    signal(SIGINT, HandlerWithCommand);
    signal(SIGALRM, HandlerWithCommand);
    while (1)
        ;
}

int main()
{
    // Test1();
    // Test2Ignoring();
    // Test3Default();
    // Test4DivZero();
    Test5UserCommandBySignal();

    return 0;
};