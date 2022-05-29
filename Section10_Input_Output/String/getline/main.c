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

// !!! "ssize_t getline(char ** restrict buf, int maxNumToRead, FILE * pStream)" read line(until '\n' of EOF) with '\n' of EOF
// from stdin/file to the buffer (maxNumToRead is including '\0') !!!
// return number of read characters (not including the '\0') or -1 if failure (failure even if EOF)

void ReadFirstLineFromFileAutoAlloc() // getline() insise allocation
{
    FILE *pFile = fopen("test.txt", "r");
    if (!pFile)
    {
        printf("Error file open!\n");
        return;
    }
    char *buf = NULL;
    size_t bufSize = 0;
    ssize_t readSize = getline(&buf, &bufSize, pFile);
    if (readSize == -1)
    {
        printf("fgets() error %s", strerror(errno));
        return;
    }
    printf("%ld characters were read:\n", readSize);
    for (ssize_t i = 0; i < readSize; i++)
        printf("%c", buf[i]);
    fclose(pFile);
}

void ReadFirstLineFromFileManualAlloc() // use malloc
{
    FILE *pFile = fopen("test.txt", "r");
    if (!pFile)
    {
        printf("Error file open!\n");
        return;
    }
    size_t bufSize = 32;
    char *buf = (char *)malloc(sizeof(bufSize));
    ssize_t readSize = getline(&buf, &bufSize, pFile);
    if (readSize == -1)
    {
        printf("fgets() error %s", strerror(errno));
        return;
    }
    printf("%ld characters were read:\n", readSize);
    for (ssize_t i = 0; i < readSize; i++)
        printf("%c", buf[i]);
    fclose(pFile);
}

int main()
{
    ReadFirstLineFromFileAutoAlloc();
    ReadFirstLineFromFileManualAlloc();
}