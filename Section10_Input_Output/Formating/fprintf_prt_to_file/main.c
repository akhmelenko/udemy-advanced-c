#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//// File access
// mode | Meaning       | Explanation                  | Action if file already exists   | Action if file  does not exist
// "r"	| read	        | Open a file for reading      | read from start                 | failure to open
// "w"	| write	        | Create a file for writing	   | destroy contents	             | create new
// "a"	| append        | Append to a file	           | write to end	                 | create new
// "r+"	| read extended	| Open a file for read/write   | read from start	             | error
// "w+"	| write extended| Create a file for read/write | destroy contents	             | create new
// "a+"	|append extended| Open a file for read/write   | write to end#pragma region      | create new

// !!! "int sprintf(FILE * pFile, const char *format, ...)" print data to file and automatically add '\0'

int main()
{
    // print ot file
    FILE *pFile = fopen("test.txt", "w");
    if (!pFile)
    {
        printf("fopen() error!\n");
        exit(-1);
    }

    for (int i = 0; i < 4; i++)
    {
        int size = fprintf(pFile, "hello cnt=%d\n", i);
        printf("size=%d\n", size);
    }
    pclose(pFile);

    // print to stdout
    fprintf(stdout, "Print to STDOUT %d", 99);

    // printf to stderr (printing before STDOUT if no '\n' used!)
    fprintf(stderr, "Check STDERR %d\n", 77);

    return 0;
}