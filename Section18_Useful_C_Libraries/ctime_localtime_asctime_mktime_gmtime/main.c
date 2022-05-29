
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
    time_t calendarTime = time(NULL);
    char *timeStr = ctime(&calendarTime);
    printf("\nctime() str=%s : calendar=%ld\n", timeStr, calendarTime);

    struct tm *tmStruct = localtime(&calendarTime);
    printf("\nlocaltime():\n");
    printf("tm_gmtoff=%ld\n", tmStruct->tm_gmtoff);
    printf("tm_hour=%d\n", tmStruct->tm_hour);
    printf("tm_isdst=%d\n", tmStruct->tm_isdst);
    printf("tm_mday=%d\n", tmStruct->tm_mday);
    printf("tm_min=%d\n", tmStruct->tm_min);
    printf("tm_mon=%d\n", tmStruct->tm_mon);
    printf("tm_sec=%d\n", tmStruct->tm_sec);
    printf("tm_wday=%d\n", tmStruct->tm_wday);
    printf("tm_yday=%d\n", tmStruct->tm_yday);
    printf("tm_year=%d\n", tmStruct->tm_year);
    printf("tm_zone=%s\n", tmStruct->tm_zone);

    struct tm *gmTmStruct = gmtime(&calendarTime);
    printf("\ngmtime():\n");
    printf("tm_gmtoff=%ld\n", gmTmStruct->tm_gmtoff);
    printf("tm_hour=%d\n", gmTmStruct->tm_hour);
    printf("tm_isdst=%d\n", gmTmStruct->tm_isdst);
    printf("tm_mday=%d\n", gmTmStruct->tm_mday);
    printf("tm_min=%d\n", gmTmStruct->tm_min);
    printf("tm_mon=%d\n", gmTmStruct->tm_mon);
    printf("tm_sec=%d\n", gmTmStruct->tm_sec);
    printf("tm_wday=%d\n", gmTmStruct->tm_wday);
    printf("tm_yday=%d\n", gmTmStruct->tm_yday);
    printf("tm_year=%d\n", gmTmStruct->tm_year);
    printf("tm_zone=%s\n", gmTmStruct->tm_zone);

    printf("\nasctime(): %s\n", asctime(tmStruct));

    printf("\nmktime()=%ld\n", mktime(tmStruct));

    printf("\nEnter your birthday: day, month, year\n");
    int day;
    int month;
    int year;
    scanf("%d %d %d", &day, &month, &year);
    printf("data to weekday:%s\n", DataToWeekday(day, month - 1, year - 1900));

    return 0;
}
