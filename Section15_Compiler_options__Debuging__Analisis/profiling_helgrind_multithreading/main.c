#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t m0 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;

// DEADLOCK PROBLEM
void *Worker(void *arg)
{
    if (*(int *)arg == 0)
    {
        // thread 0 execution
        pthread_mutex_lock(&m0);
        pthread_mutex_lock(&m1);
    }
    else
    {
        // thread 1 execution
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m0);
    }
    pthread_mutex_unlock(&m0);
    pthread_mutex_unlock(&m1);
    return NULL;
}

int main()
{
    pthread_t tid0;
    pthread_t tid1;
    int arg0 = 0;
    int arg1 = 1;
    pthread_create(&tid0, NULL, Worker, (void *)&arg0);
    pthread_create(&tid1, NULL, Worker, (void *)&arg1);
    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    return 0;
};
