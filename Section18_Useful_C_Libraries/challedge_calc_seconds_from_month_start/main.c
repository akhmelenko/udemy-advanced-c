
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h> // sleep
#include <string.h>

char *DataToWeekday(int day, int month, int year)
{
    struct tm t = {.tm_mday = day, .tm_mon = month, .tm_year = year};
    if (mktime(&t) == -1) // fill tm_wday from tm_mday, tm_mon, tm_year
    {
        fprintf(stderr, "mktime() error=%d (%s)\n", errno, strerror(errno));
        return NULL;
    }
    return asctime(&t);
}

int main(int argc, char *argv[])
{
    // take current time
    time_t calendarTime = time(NULL);
    if (calendarTime == -1)
    {
        fprintf(stderr, "time() error=%d (%s)\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    // get struct tm
    struct tm *tm = localtime(&calendarTime);
    if (tm == NULL)
    {
        fprintf(stderr, "localtime() error=%d (%s)\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    // set struct tm with month start
    tm->tm_mday = 1;
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    // get calendar from struct tm
    time_t calendarTimeMonStart = mktime(tm);
    if (calendarTime == -1)
    {
        fprintf(stderr, "mktime() error=%d (%s)\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    // check diffrance in seconds
    double diff = difftime(calendarTime, calendarTimeMonStart);
    // double diff = difftime(3, 16);
    printf("Seconds from month start=%f\n", diff);

    exit(EXIT_SUCCESS);
}
