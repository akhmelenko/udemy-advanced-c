
#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

enum DEBUG_LEVEL_
{
    DEBUG_LEVEL_SILENT = 0,
    DEBUG_LEVEL_MAIN_INFO = 1,
    DEBUG_LEVEL_MORE_DETAILS = 2,
    DEBUG_LEVEL_ALL_DETAILS = 3,
};

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_LEVEL_MAIN_INFO
#endif

// debug printf
#define DPRINT(level, format, ...)                                    \
    if (DEBUG_LEVEL >= level)                                         \
    {                                                                 \
        fprintf(stderr, "%s,%d,%s():", __FILE__, __LINE__, __func__); \
        fprintf(stderr, format, __VA_ARGS__);                         \
    }

#endif //_DEBUG_H_
