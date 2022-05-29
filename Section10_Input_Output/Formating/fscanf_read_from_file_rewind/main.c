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

// !!! "int fscanf(FILE * pFile, const char *format, ...)" read data from file and save to the pointed variable (add '\0' at the end)
// !!! return number of receiving arguments

int main()
{
    // print ot file
    FILE *pFile = fopen("test.txt", "r");
    if (!pFile)
    {
        fprintf(stderr, "fopen() error!\n");
        exit(-1);
    }

    // read by characters
    char ch;
    int ret = fscanf(pFile, "%c", &ch);
    putchar(ch);
    printf("\nret=%d\n", ret);
    char ch2;
    ret = fscanf(pFile, "%c%c", &ch, &ch2);
    putchar(ch);
    putchar(ch2);
    printf("\nret=%d\n", ret);

    // read by words (until the space)
    rewind(pFile);
    char buf[] = {[0 ... 32] 1};
    while ((ret = fscanf(pFile, "%s", buf)) != EOF) // read by lines !!! ONLY 1 LINE BY 1 %s
    {
        printf("new str:\n");
        puts(buf);
    }
    printf("\nret=%d\n", ret);

    // read by 3 characters
    rewind(pFile);
    char buf[] = {[0 ... 32] 1};
    while ((ret = fscanf(pFile, "%3s", buf)) != EOF) // read by 3 characters if < lines length !!! ONLY 1 LINE BY 3 chars or by rest of the line
    {
        printf("new str:\n");
        puts(buf);
    }
    printf("\nret=%d\n", ret);

    pclose(pFile);

    return 0;
}