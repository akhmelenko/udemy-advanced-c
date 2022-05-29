#include <stdio.h>
#include <signal.h> // for signals
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>

// Ctrl+C == SIGINT
// Ctrl+Z == SIGTSTP
// fg or bg == SIGCONT
//
// int sigaction(int __sig,
//                  const struct sigaction *__restrict__ new_action,
//                  struct sigaction *__restrict__ old_action)

void TerminationHandler(int signo)
{
    switch (signo)
    {
    case SIGINT:
        printf("Received SIGINT\n");
        break;
    case SIGHUP:
        printf("Received SIGHUP\n");
        break;
    case SIGTERM:
        printf("Received SIGTERM\n");
        break;
    case SIGTSTP:
        printf("Received SIGTERM\n");
        exit(0);
        break;
    default:
        printf("Wrong if reach this line\n");
    }
}

void Test1()
{
    struct sigaction action, old_action;

    // set up structure
    action.sa_handler = TerminationHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    // check current settings for ignore
    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
        // set signal action (handler)
        sigaction(SIGINT, &action, NULL);

    // check current settings for ignore
    sigaction(SIGHUP, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
        // set signal action (handler)
        sigaction(SIGHUP, &action, NULL);

    // check current settings for ignore
    sigaction(SIGTERM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
        // set signal action (handler)
        sigaction(SIGTERM, &action, NULL);

    // check current settings for ignore
    sigaction(SIGTSTP, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN)
        // set signal action (handler)
        sigaction(SIGTSTP, &action, NULL);

    while (1)
        ;
}

// handler with more detailed info about signal
static void HandlerSigaction(int signo,
                             siginfo_t *siginfo,
                             void *context)
{
    printf("Sending signo=%d PID: %d, UID: %d\n",
           signo,
           siginfo->si_pid,
           siginfo->si_uid);
}

void Test2()
{
    struct sigaction act;

    // clear action
    memset(&act, 0, sizeof(act));

    // set handler
    act.sa_sigaction = &HandlerSigaction;

    // set flag to use sa_sigaction for handler
    act.sa_flags = SA_SIGINFO;

    // set sigaction
    if (sigaction(SIGINT, &act, NULL))
    {
        fprintf(stderr, "sigaction() error=%d (%s)\n", errno, strerror(errno));
        return;
    }

    while (1)
        ;
}

int main()
{
    // Test1();
    Test2();
    return 0;
};
