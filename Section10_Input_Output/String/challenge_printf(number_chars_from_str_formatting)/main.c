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

// !!! "ssize_t getline(char ** restrict buf, int maxNumToRead, FILE * pStream)" read line(until '\n' or EOF) with '\n' or EOF
// from stdin/file to the buffer (maxNumToRead is including '\0') !!!
// return number of read characters (not including the '\0') or -1 if failure (failure even if EOF)

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments =%d, must be 3", argc);
        return -1;
    }

    char *fileName = argv[1];
    char checkChar = argv[2][0];
    // char checkChar = checkCharStr[0];

    FILE *pFile = fopen(fileName, "r");
    if (!pFile)
    {
        printf("fopen() error=%s", strerror(errno));
    }

    char *buf = NULL;
    size_t len = 0;
    ssize_t result;
    while ((result = getline(&buf, &len, pFile)) > 0)
    {
        char *ch = '\0';
        if (strchr(buf, checkChar))
        {
            printf("%.*s", (int)result, buf);
        }
    }
    printf("\nbuf_len=%ld\n", len);
    free(buf);
    fclose(pFile);
    return 0;
}