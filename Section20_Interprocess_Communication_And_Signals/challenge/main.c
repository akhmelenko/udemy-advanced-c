#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>  // need for fork()
#include <signal.h>  // need for signal()
#include <time.h>    // for time()
#include <stdlib.h>  // srand() rand()
#include <pthread.h> // for mutex

int ret = 0;
int score = 0;
int total = 0;

void AlarmHandler(int signo)
{
    printf("Time is up, %d wrong answers of %d total\n", score, total);
    ret = 1;
    exit(0);
}

void Task1()
{
    signal(SIGALRM, AlarmHandler);
    srand(time(0));

    while (!ret)
    {
        int a = rand() % 10;
        int b = rand() % 10;

        char txt[4];
        total++;
        printf("Calculate result of %d * %d =\n", a, b);
        alarm(5);
        fgets(txt, 4, stdin);

        int input = atoi(txt);

        if (a * b != input)
            printf("Wrong answer! Score = %d\n", ++score);
        else
            printf("Correct!\n");
    }
}

void ChildProcess(int i)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    switch (i)
    {
    case 1:
        printf("First child pid=%d ppid=%d\n", pid, ppid);
        break;
    case 2:
        printf("Second child pid=%d ppid=%d\n", pid, ppid);
        break;
    case 3:
        printf("Third child pid=%d ppid=%d\n", pid, ppid);
        break;
    }
    exit(0);
}

void Task2()
{
    printf("Start main\n");

    pid_t pid[3];
    for (int i = 0; i < 3; i++)
    {
        printf("fork%d\n", i);
        pid[i] = fork();
        if (pid[i] < 0)
        {
            fprintf(stderr, "fork() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
        else if (pid[i] == 0)
            ChildProcess(i + 1);
    }
}

int main()
{
    // Task1();
    Task2();
    return 0;
};
