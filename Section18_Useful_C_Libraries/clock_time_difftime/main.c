
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h> // sleep
#include <string.h>

void TestProcessTime()
{
    time_t start = (long int)clock();
    printf("start clock()=%ld\n", start);
    // some delay
    for (volatile int i = 0; i < 1000000000; i++)
        ;
    time_t end = (long int)clock();
    printf("end clock()=%ld\n", end);
    double period = (double)(end - start) / CLOCKS_PER_SEC;
    printf("process work time = %ld ticks = %f seconds\n", end - start, period);
}

void TestTimeDifftime()
{
    time_t startCalendarTime = time(NULL);
    printf("start abs time=%ld in sec. from 01.01.1970\n", startCalendarTime);
    sleep(2);
    time_t endCalendarTime;
    if (time(&endCalendarTime) == -1)
    {
        fprintf(stderr, "time() error=%d (%s)\n", errno, strerror(errno));
        return;
    }
    printf("end abs time=%ld in sec. from 01.01.1970\n", endCalendarTime);
    printf("difftime=%f\n", difftime(endCalendarTime, startCalendarTime));
}

int main(int argc, char *argv[])
{
    TestProcessTime();
    // TestTimeDifftime();

    return 0;
}
