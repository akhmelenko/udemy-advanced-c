#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <pthread.h> // all pthread functions
#include <unistd.h>  // sleep

struct PassArg
{
    int t_number;
    int data;
};

int retVal;

void *Thread(void *arg)
{
    printf("Started thread=%ld with arg.t_number=%d arg.data=%d\n",
           pthread_self(),
           ((struct PassArg *)arg)->t_number,
           ((struct PassArg *)arg)->data);
    sleep(3);
    printf("Tread %ld: finished\n", pthread_self());
    // return NULL;
    retVal = 33;
    pthread_exit(&retVal);
}

void TestMainExitFirst()
{
    pthread_t t1;
    pthread_t t2;
    if (pthread_create(&t1, NULL, Thread, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    if (pthread_create(&t2, NULL, Thread, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    sleep(1);
    printf("main finished\n");
}

void TestMainWaitAll()
{
    pthread_t t1;
    pthread_t t2;
    if (pthread_create(&t1, NULL, Thread, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    sleep(1);
    if (pthread_create(&t2, NULL, Thread, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("main finished\n");
}

void *ThreadOneArgReturn(void *arg)
{
    printf("Started thread=%ld with arg.t_number=%d arg.data=%d\n",
           pthread_self(),
           ((struct PassArg *)arg)->t_number,
           ((struct PassArg *)arg)->data);
    sleep(3);
    printf("Tread %ld: finished\n", pthread_self());
    // allocate ret val memory
    int *retVal = (int *)malloc(sizeof(int));
    *retVal = 77;
    return (void *)retVal;
}

void TestMainReceiveOneArg()
{
    pthread_t t1;
    struct PassArg arg = {1, 22};
    if (pthread_create(&t1, NULL, ThreadOneArgReturn, (void *)&arg) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    int *retVal;
    pthread_join(t1, (void *)&retVal);
    printf("thread exited with retval=%d\n", *retVal);
    free(retVal);
    printf("main finished\n");
}

void TestMainSendReceiveArg()
{
    pthread_t t1;
    struct PassArg arg = {1, 22};
    if (pthread_create(&t1, NULL, Thread, (void *)&arg) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    int *retVal;
    pthread_join(t1, (void *)&retVal);
    printf("thread exited with retval=%d\n", *retVal);
    printf("main finished\n");
}

int main()
{
    // TestMainExitFirst();
    // TestMainWaitAll();
    // TestMainReceiveOneArg();
    TestMainSendReceiveArg();

    return 0;
};
