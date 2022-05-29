#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>   // need for fork()
#include <signal.h>   // need for signal()
#include <stdlib.h>   // need for exit()
#include <sys/wait.h> // need for wait()

int received = 0;
int ack_received = 0;

void ChildHandler(int signo)
{
    printf("Child signal %d received\n", signo);
    received = 1;
}

void ParentHandler(int signo)
{
    printf("Parent signal %d received\n", signo);
    ack_received = 1;
}

int main()
{
    int pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork() error=%d (%s)\n", errno, strerror(errno));
        return -1;
    }
    else if (pid == 0)
    {
        // child process
        if (signal(SIGUSR1, ChildHandler) == SIG_ERR)
        {
            fprintf(stderr, "signal() error=%d (%s)\n", errno, strerror(errno));
            return -1;
        }
        printf("Hello from child! (child pid=%d my pid=%d) \n", pid, getpid());
        for (int i = 0; i < 4; i++)
        {
            printf("parent i=%d\n", i);
            sleep(1);
        }
        while (!received)
            ;
        pid_t ppid = getppid();
        printf("Parent pid=%d\n", ppid);
        printf("Sending signal to parent\n");
        kill(ppid, SIGUSR2);
        while (1)
            ;
    }
    else
    {
        // parent process
        if (signal(SIGUSR2, ParentHandler) == SIG_ERR)
        {
            fprintf(stderr, "signal() error=%d (%s)\n", errno, strerror(errno));
            return -1;
        }
        printf("Hello from parent! (child pid=%d my pid=%d)\n", pid, getpid());
        for (int i = 0; i < 4; i++)
        {
            printf("child i=%d\n", i);
            sleep(1);
        }
        sleep(3);
        printf("Sending signal to child\n");
        kill(pid, SIGUSR1);
        while (!ack_received)
            ;
        int wstatus;
        if (waitpid(pid, &wstatus, WUNTRACED | WCONTINUED) == -1)
        {
            fprintf(stderr, "waitpid() error=%d (%s)\n", errno, strerror(errno));
            return -1;
        }
        printf("Parent: Child process finished\n");
    }
    return 0;
};
