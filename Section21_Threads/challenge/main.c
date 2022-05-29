#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <pthread.h> // all pthread functions
#include <unistd.h>  // sleep

#define THREADS_NUMBER 10

int out[THREADS_NUMBER];
int cnt = 0;

void *Ch1Thread(void *arg)
{
    printf("t#%ld start with arg=%d cnt=%d\n", pthread_self(), *(int *)arg, cnt);
    cnt++;
    out[*(int *)arg] = cnt;
    printf("t#%ld final cnt=%d\n", pthread_self(), cnt);
    return &out[*(int *)arg];
}

void Challenge1()
{
    pthread_t tid[THREADS_NUMBER];
    int inArg[THREADS_NUMBER];
    int *outArg[THREADS_NUMBER];
    // create threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        inArg[i] = i;
        if (pthread_create(&tid[i], NULL, Ch1Thread, &inArg[i]) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // join threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        if (pthread_join(tid[i], (void **)&outArg[i]) != 0)
        {
            fprintf(stderr, "pthread_join() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // print out args
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        printf("thread%d out arg=%d\n", i, *outArg[i]);
    }
}

pthread_mutex_t cntMutex = PTHREAD_MUTEX_INITIALIZER;

void *Ch2Thread(void *arg)
{
    pthread_mutex_lock(&cntMutex);
    printf("t#%ld start with arg=%d cnt=%d\n", pthread_self(), *(int *)arg, cnt);
    cnt++;
    out[*(int *)arg] = cnt;
    printf("t#%ld final cnt=%d\n", pthread_self(), cnt);
    pthread_mutex_unlock(&cntMutex);
    return &out[*(int *)arg];
}

void Challenge2Mutex()
{
    pthread_t tid[THREADS_NUMBER];
    int inArg[THREADS_NUMBER];
    int *outArg[THREADS_NUMBER];
    // create threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        inArg[i] = i;
        if (pthread_create(&tid[i], NULL, Ch2Thread, &inArg[i]) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // join threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        if (pthread_join(tid[i], (void **)&outArg[i]) != 0)
        {
            fprintf(stderr, "pthread_join() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // print out args
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        printf("thread%d out arg=%d\n", i, *outArg[i]);
    }
    // desroy mutex
    pthread_mutex_destroy(&cntMutex);
}

pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t cvMutex = PTHREAD_MUTEX_INITIALIZER;
int gatherCnt;

void *Ch3ThreadOrder(void *arg)
{
    // start wait if wrong order
    while (cnt != *(int *)arg)
    {
        pthread_mutex_lock(&cvMutex);
        printf("t#%ld wait=%d current=%d before wait\n", pthread_self(), *(int *)arg, cnt);
        gatherCnt++;
        pthread_cond_wait(&cv, &cvMutex);
        printf("t#%ld wait=%d current=%d after wake up\n", pthread_self(), *(int *)arg, cnt);
        pthread_mutex_unlock(&cvMutex);
    }
    pthread_mutex_lock(&cntMutex);
    printf("t#%ld start with arg=%d cnt=%d\n", pthread_self(), *(int *)arg, cnt);
    // gethering all threads in wait
    gatherCnt = 0;
    pthread_mutex_unlock(&cntMutex);
    pthread_cond_broadcast(&cv);
    int temp;
    while (temp != (THREADS_NUMBER - cnt - 1))
    {
        // pthread_mutex_lock(&cvMutex);
        temp = gatherCnt;
        // pthread_mutex_unlock(&cvMutex);
    }
    // printf("gatherCnt=%d\n", gatherCnt);
    cnt++;
    out[*(int *)arg] = cnt;
    printf("t#%ld final cnt=%d\n", pthread_self(), cnt);
    // send wake up for all
    pthread_cond_broadcast(&cv);
    return &out[*(int *)arg];
}

void Challenge3StrictOrder()
{
    pthread_t tid[THREADS_NUMBER];
    int inArg[THREADS_NUMBER];
    int *outArg[THREADS_NUMBER];
    cnt = -1;
    // create threads
    for (int i = THREADS_NUMBER - 1; i >= 0; i--)
    {
        inArg[i] = i;
        if (pthread_create(&tid[i], NULL, Ch3ThreadOrder, &inArg[i]) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // synchronize threads
    cnt = 0;
    gatherCnt = 0;
    pthread_cond_broadcast(&cv);
    // join threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        if (pthread_join(tid[i], (void **)&outArg[i]) != 0)
        {
            fprintf(stderr, "pthread_join() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
        printf("join cycle i=%d\n", i);
    }
    // print out args
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        printf("thread%d out arg=%d\n", i, *outArg[i]);
    }
    // desroy mutex
    pthread_mutex_destroy(&cvMutex);
    pthread_mutex_destroy(&cntMutex);
}

pthread_barrier_t barrier;

void *ThreadBarier(void *arg)
{
    printf("tid:%ld start\n", pthread_self());
    pthread_barrier_wait(&barrier);
    printf("tid:%ld finished\n", pthread_self());
}

void Challenge4Barier()
{
    pthread_t tid[THREADS_NUMBER];
    pthread_barrier_init(&barrier, NULL, THREADS_NUMBER);
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        pthread_create(&tid[i], NULL, ThreadBarier, NULL);
    }
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_barrier_destroy(&barrier);
}

pthread_mutex_t barrierMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_once_t onceControl = PTHREAD_ONCE_INIT;

void ClearCnt()
{
    printf("clear CNT only after first barrier reach\n");
    cnt = 0;
}

void *Ch5ThreadOrderBarrier(void *arg)
{
    printf("t#:%ld start\n", pthread_self());
    // start wait if wrong order
    int safeCnt = -1;
    while (cnt != THREADS_NUMBER)
    {
        printf("t#%ld wait=%d current=%d before wait\n", pthread_self(), *(int *)arg, cnt);
        if (safeCnt != THREADS_NUMBER)
            pthread_barrier_wait(&barrier);
        printf("t#%ld wait=%d current=%d after wake up\n", pthread_self(), *(int *)arg, cnt);
        if (cnt == *(int *)arg)
        {
            // ordered section
            printf("t#%ld start with arg=%d cnt=%d\n", pthread_self(), *(int *)arg, cnt);
            // pthread_mutex_lock(&cntMutex);
            cnt++;
            // out[*(int *)arg] = cnt;
            pthread_mutex_unlock(&cntMutex);
            printf("t#%ld final cnt=%d\n", pthread_self(), cnt);
        }
        // pthread_mutex_lock(&cntMutex);
        // safeCnt = cnt;
        // pthread_mutex_unlock(&cntMutex);
    }
    return &out[*(int *)arg];
}

void Challenge5StrictOrderBarrier()
{
    pthread_t tid[THREADS_NUMBER];
    int inArg[THREADS_NUMBER];
    int *outArg[THREADS_NUMBER];
    cnt = 0;
    pthread_barrier_init(&barrier, NULL, THREADS_NUMBER);
    // create threads
    // for (int i = THREADS_NUMBER - 1; i >= 0; i--)
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        inArg[i] = i;
        if (pthread_create(&tid[i], NULL, Ch5ThreadOrderBarrier, &inArg[i]) != 0)
        {
            fprintf(stderr, "pthread_create() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
    }
    // join threads
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        if (pthread_join(tid[i], (void **)&outArg[i]) != 0)
        {
            fprintf(stderr, "pthread_join() error=%d (%s)\n", errno, strerror(errno));
            return;
        }
        printf("join cycle i=%d\n", i);
    }
    // print out args
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        printf("thread%d out arg=%d\n", i, *outArg[i]);
    }
    // desroy mutex
    pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&barrierMutex);
}

int main()
{
    // Challenge1();
    // Challenge2Mutex();
    // Challenge3StrictOrder();
    // Challenge4Barier();
    Challenge5StrictOrderBarrier();

    return 0;
};
