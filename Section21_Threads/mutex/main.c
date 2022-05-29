#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <pthread.h> // all pthread functions
#include <unistd.h>  // sleep

#define THREAD_NUMBER 10
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockD;
int sharedCnt = 0;

void *Thread(void *agr)
{
    printf("try to lock mutex (tid=%ld)\n", pthread_self());
    pthread_mutex_lock(&lock);
    sharedCnt++;
    sleep(1);
    pthread_mutex_unlock(&lock);
    printf("mutex unlocked (tid=%ld) sharedCnt=%d\n", pthread_self(), sharedCnt);
}

void TestStaticInitMutex()
{
    pthread_t t[THREAD_NUMBER];
    for (int i = 0; i < THREAD_NUMBER; i++)
    {
        if (pthread_create(&t[i], NULL, Thread, NULL) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    for (int i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_join(t[i], NULL);
    }
    printf("sharedCnt=%d\n", sharedCnt);
    pthread_mutex_destroy(&lock);
}

void *ThreadD(void *agr)
{
    printf("try to lock mutex (tid=%ld)\n", pthread_self());
    pthread_mutex_lock(&lockD);
    sharedCnt++;
    sleep(1);
    pthread_mutex_unlock(&lockD);
    printf("mutex unlocked (tid=%ld) sharedCnt=%d\n", pthread_self(), sharedCnt);
}

void TestDynamicInitMutex()
{
    pthread_t t[THREAD_NUMBER];
    pthread_mutex_init(&lockD, NULL); // init with default attribute
    for (int i = 0; i < THREAD_NUMBER; i++)
    {
        if (pthread_create(&t[i], NULL, ThreadD, NULL) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    for (int i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_join(t[i], NULL);
    }
    printf("sharedCnt=%d\n", sharedCnt);
    pthread_mutex_destroy(&lockD);
}

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void *ThreadDeadlock1(void *arg)
{
    printf("thread#%ld, try to lock1\n", pthread_self());
    pthread_mutex_lock(&lock1);
    sleep(1);
    printf("thread#%ld, try to lock2\n", pthread_self());
    pthread_mutex_lock(&lock2);
    sleep(1);
    printf("thread#%ld inside double critical section\n", pthread_self());
    sleep(1);
    printf("thread#%ld,  ulock2\n", pthread_self());
    pthread_mutex_unlock(&lock2);
    sleep(1);
    printf("thread#%ld,  ulock1\n", pthread_self());
    pthread_mutex_unlock(&lock1);
}

void *ThreadDeadlock2(void *arg)
{
    printf("thread#%ld, try to lock2\n", pthread_self());
    pthread_mutex_lock(&lock2);
    sleep(1);
    printf("thread#%ld, try to lock1\n", pthread_self());
    pthread_mutex_lock(&lock1);
    printf("thread#%ld inside double critical section\n", pthread_self());
    sleep(1);
    printf("thread#%ld,  ulock1\n", pthread_self());
    pthread_mutex_unlock(&lock1);
    sleep(1);
    printf("thread#%ld,  ulock2\n", pthread_self());
    pthread_mutex_unlock(&lock2);
}

void TestDeadlock()
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, ThreadDeadlock1, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    if (pthread_create(&t2, NULL, ThreadDeadlock2, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    printf("finished main\n");
}

void *ThreadDeadlock1Safe(void *arg)
{
    printf("thread#%ld, locking lock1\n", pthread_self());
    pthread_mutex_lock(&lock1);
    printf("thread#%ld, lock1 locked\n", pthread_self());
    sleep(1);
    printf("thread#%ld, try to lock2\n", pthread_self());
    while (pthread_mutex_trylock(&lock2))
    {
        pthread_mutex_unlock(&lock1);
        printf("thread#%ld, in while\n", pthread_self());
        sleep(1);
        pthread_mutex_lock(&lock1);
    }
    printf("thread#%ld, lock2 locked\n", pthread_self());
    printf("thread#%ld start double critical section\n", pthread_self());
    sleep(2);
    printf("thread#%ld stop double critical section\n", pthread_self());
    printf("thread#%ld,  ulock2\n", pthread_self());
    pthread_mutex_unlock(&lock2);
    sleep(1);
    printf("thread#%ld,  ulock1\n", pthread_self());
    pthread_mutex_unlock(&lock1);
}

void *ThreadDeadlock2Safe(void *arg)
{
    printf("thread#%ld, locking lock2\n", pthread_self());
    pthread_mutex_lock(&lock2);
    printf("thread#%ld, lock2 locked\n", pthread_self());
    sleep(1);
    printf("thread#%ld, try to lock1\n", pthread_self());
    while (pthread_mutex_trylock(&lock1))
    {
        pthread_mutex_unlock(&lock2);
        printf("thread#%ld, in while\n", pthread_self());
        sleep(1);
        pthread_mutex_lock(&lock2);
    }
    printf("thread#%ld, lock1 locked\n", pthread_self());
    printf("thread#%ld start double critical section\n", pthread_self());
    sleep(2);
    printf("thread#%ld stop double critical section\n", pthread_self());
    printf("thread#%ld,  ulock1\n", pthread_self());
    pthread_mutex_unlock(&lock1);
    sleep(1);
    printf("thread#%ld,  ulock2\n", pthread_self());
    pthread_mutex_unlock(&lock2);
}

void TestDeadlockSafe()
{
    srand(time(0));
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, ThreadDeadlock1Safe, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    if (pthread_create(&t2, NULL, ThreadDeadlock2Safe, NULL) != 0)
    {
        fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    printf("finished main\n");
}

int main()
{
    // TestStaticInitMutex();
    // TestDynamicInitMutex();
    // TestDeadlock();
    TestDeadlockSafe();
    return 0;
};
