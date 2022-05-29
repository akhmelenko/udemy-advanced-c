#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <pthread.h> // all pthread functions
#include <unistd.h>  // sleep

void *ThreadDetached(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Started thread=%ld\n", tid);
    //!!! works only with "pthread_exit(NULL)" in main thread!!!
    pthread_detach(tid); // detaching from main thread !!! works only with "pthread_exit(NULL)" in main thread!!!
    sleep(3);
    printf("Tread %ld: finished\n", tid);
    return NULL;
}

void TestDetach()
{
    printf("Main started\n");
    pthread_t t;
    if (pthread_create(&t, NULL, ThreadDetached, NULL) != 0)
    {
        fprintf(stderr, "pthread_creare() error=%d (%s)\n", errno, strerror(errno));
        exit(-1);
    }
    sleep(1);
    printf("Main finished\n");
    // pthread_exit() - this needs to pthread_detach() work in child thead
    pthread_exit(NULL);
}

void *TreadStackSize()
{
    size_t stacksize;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    if (pthread_attr_getstacksize(&attr, &stacksize) != 0)
    {
        fprintf(stderr, "child: pthread_attr_getstacksize() ");
        exit(-1);
    }
    printf("child: stack size=%ld\n", stacksize);
    printf("child: change stack size to 16Mb\n");
    stacksize = 16 * 1024 * 1024;
    if (pthread_attr_setstacksize(&attr, stacksize) != 0)
    {
        fprintf(stderr, "child: pthread_attr_setstacksize() ");
        exit(-1);
    }
    if (pthread_attr_getstacksize(&attr, &stacksize) != 0)
    {
        fprintf(stderr, "child: pthread_attr_getstacksize() ");
        exit(-1);
    }
    printf("child: new stack size=%ld\n", stacksize);
}

void TestStackSize()
{
    printf("Main started\n");
    pthread_t t;
    pthread_attr_t attr;
    size_t stacksize;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("parent: stack size=%ld attr.size=%d\n", stacksize, attr.__size[1]);
    pthread_attr_setstacksize(&attr, 12 * 1024 * 1024);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("parent: new stack size=%ld attr.size=%d\n", stacksize, attr.__size[1]);
    // create with definite stack size
    if (pthread_create(&t, &attr, TreadStackSize, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        exit(-1);
    }
    sleep(1);
}

void *ThreadForEqual(void *arg)
{
    while (1)
        ;
    return NULL;
}

void TestCheckEqualTid()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadForEqual, NULL);
    printf("parent: parent thread#=%ld, child thread#=%ld\n", tid, pthread_self());
    // compare tids
    if (pthread_equal(tid, pthread_self()) == 0)
    {
        printf("tids are not equal\n");
    }
    else
    {
        printf("tids are equal\n");
    }
}

pthread_once_t onceControl = PTHREAD_ONCE_INIT;
void OnceFunc()
{
    printf("in OnceFunc\n");
}

void *ThreadWithOnce(void *arg)
{
    printf("child: tid=%ld\n", pthread_self());
    if (pthread_once(&onceControl, OnceFunc) != 0)
    {
        fprintf(stderr, "pthread_once() error=%d (%s)\n", errno, strerror(errno));
    }
    return NULL;
}

void TestOnce()
{
    pthread_t tid;
    pthread_create(&tid, NULL, ThreadWithOnce, NULL);
    printf("parent: parent thread#=%ld, started child thread#=%ld\n", pthread_self(), tid);
    pthread_create(&tid, NULL, ThreadWithOnce, NULL);
    printf("parent: parent thread#=%ld, started child thread#=%ld\n", pthread_self(), tid);
    sleep(1);
}

void *CancelingThread()
{
    while (1)
    {
        printf("canceling thread cycle\n");
        sleep(1);
    }
}

void TestCancel()
{
    pthread_t tid;
    pthread_create(&tid, NULL, CancelingThread, NULL);
    printf("parent: parent thread#=%ld, started child thread#=%ld\n", pthread_self(), tid);
    sleep(2);
    printf("parent: sending cancel\n");
    pthread_cancel(tid);
    sleep(1);
}

int main()
{
    // TestDetach();
    // TestStackSize();
    // TestCheckEqualTid();
    TestOnce();
    // TestCancel();
    return 0;
};
