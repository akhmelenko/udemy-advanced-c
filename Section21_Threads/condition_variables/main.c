#include <stdio.h>
#include <stdlib.h> // for exit()
#include <errno.h>
#include <string.h>
#include <pthread.h> // all pthread functions
#include <unistd.h>  // sleep

pthread_mutex_t cvMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void *ThreadWaitCV(void *arg)
{
    printf("waiting thread started\n");
    pthread_mutex_lock(&cvMutex);
    pthread_cond_wait(&cv, &cvMutex);
    pthread_mutex_unlock(&cvMutex);
    printf("condition occur!\n");
}

void *ThreadSendCV(void *arg)
{
    printf("sending thread started\n");
    sleep(3);
    pthread_mutex_lock(&cvMutex);
    printf("sending condition\n");
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&cvMutex);
}

void Test1SingleCondition()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadWaitCV, NULL);
    pthread_create(&tid2, NULL, ThreadSendCV, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

void *ThreadDoubleWaitCV(void *arg)
{
    printf("waiting thread started\n");
    pthread_mutex_lock(&cvMutex);
    pthread_cond_wait(&cv, &cvMutex);
    pthread_mutex_unlock(&cvMutex);
    printf("condition1 occur!\n");
    pthread_mutex_lock(&cvMutex);
    pthread_cond_wait(&cv, &cvMutex);
    pthread_mutex_unlock(&cvMutex);
    printf("condition2 occur!\n");
}

void *ThreadDoubleSendCV(void *arg)
{
    printf("sending thread started\n");
    sleep(3);
    pthread_mutex_lock(&cvMutex);
    printf("sending condition1\n");
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&cvMutex);
    sleep(3);
    pthread_mutex_lock(&cvMutex);
    printf("sending condition2\n");
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&cvMutex);
}

void Test2DoubleCondition()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadDoubleWaitCV, NULL);
    pthread_create(&tid2, NULL, ThreadDoubleSendCV, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

void *Thread1CV(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("t1: sending condition1\n");
        pthread_cond_signal(&cv);
        printf("t1: waiting thread started\n");
        pthread_mutex_lock(&cvMutex);
        pthread_cond_wait(&cv, &cvMutex);
        pthread_mutex_unlock(&cvMutex);
        printf("t1: condition occur!\n");
    }
}

void *Thread2CV(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("t2: sending condition1\n");
        pthread_cond_signal(&cv);
        printf("t2: waiting thread started\n");
        pthread_mutex_lock(&cvMutex);
        pthread_cond_wait(&cv, &cvMutex);
        pthread_mutex_unlock(&cvMutex);
        printf("t2: condition occur!\n");
    }
}

void Test2PingPong()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, Thread1CV, NULL);
    pthread_create(&tid2, NULL, Thread2CV, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

#define HALT1 3
#define HALT2 6
#define MAX 10

int cnt = 0;

void *ThreadOneCV_Out3_6(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("t1: sending condition\n");
        pthread_cond_signal(&cv);
        while (cnt >= 3 && cnt <= 6)
        {
            printf("t1: waiting thread started\n");
            pthread_mutex_lock(&cvMutex);
            pthread_cond_wait(&cv, &cvMutex);
            pthread_mutex_unlock(&cvMutex);
            printf("t1: condition occur!\n");
            if (cnt >= MAX)
                return NULL;
        }
        printf("t_out36: cnt=%d\n", cnt);
        cnt++;
        if (cnt >= MAX)
            return NULL;
    }
}

void *ThreadOneCV_In3_6(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("t2: sending condition\n");
        pthread_cond_signal(&cv);
        while (cnt < 3 || cnt > 6)
        {
            printf("t2: waiting thread started\n");
            pthread_mutex_lock(&cvMutex);
            pthread_cond_wait(&cv, &cvMutex);
            pthread_mutex_unlock(&cvMutex);
            printf("t2: condition occur!\n");
            if (cnt >= MAX)
                return NULL;
        }
        printf("t_in36: cnt=%d\n", cnt);
        cnt++;
        if (cnt >= MAX)
            return NULL;
    }
}

void Test3SeparateCountOneCV()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadOneCV_Out3_6, NULL);
    pthread_create(&tid2, NULL, ThreadOneCV_In3_6, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

pthread_cond_t cv1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cv2 = PTHREAD_COND_INITIALIZER;

void *ThreadTwoCV_Out3_6(void *arg)
{
    // start with out3_6 thread
    sleep(1);
    while (1)
    {
        sleep(1);
        if (cnt >= 3 && cnt <= 6)
        {
            printf("t1: sending condition\n");
            pthread_cond_signal(&cv2);
            printf("t1: waiting thread started\n");
            pthread_mutex_lock(&cvMutex);
            pthread_cond_wait(&cv1, &cvMutex);
            pthread_mutex_unlock(&cvMutex);
            printf("t1: condition occur!\n");
            if (cnt >= MAX)
            {
                pthread_cond_signal(&cv2);
                return NULL;
            }
        }
        printf("t_out36: cnt=%d\n", cnt);
        cnt++;
        if (cnt >= MAX)
        {
            pthread_cond_signal(&cv2);
            return NULL;
        }
    }
}

void *ThreadTwoCV_In3_6(void *arg)
{
    while (1)
    {
        sleep(1);
        if (cnt < 3 || cnt > 6)
        {
            printf("t2: sending condition\n");
            pthread_cond_signal(&cv1);
            printf("t2: waiting thread started\n");
            pthread_mutex_lock(&cvMutex);
            pthread_cond_wait(&cv2, &cvMutex);
            pthread_mutex_unlock(&cvMutex);
            printf("t2: condition occur!\n");
            if (cnt >= MAX)
            {
                pthread_cond_signal(&cv1);
                return NULL;
            }
        }
        printf("t_in36: cnt=%d\n", cnt);
        cnt++;
        if (cnt >= MAX)
        {
            pthread_cond_signal(&cv1);
            return NULL;
        }
    }
}

void Test4SeparateCountTwoCV()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, ThreadTwoCV_Out3_6, NULL);
    pthread_create(&tid2, NULL, ThreadTwoCV_In3_6, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

int main()
{
    // Test1SingleCondition();
    // Test2DoubleCondition();
    // Test2PingPong();
    // Test3SeparateCountOneCV();
    Test4SeparateCountTwoCV();
    return 0;
};
