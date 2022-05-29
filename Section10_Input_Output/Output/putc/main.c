#include <stdio.h>
#include <errno.h>
#include <string.h>

//// File access
// mode | Meaning       | Explanation                  | Action if file already exists   | Action if file  does not exist
// "r"	| read	        | Open a file for reading      | read from start                 | failure to open
// "w"	| write	        | Create a file for writing	   | destroy contents	             | create new
// "a"	| append        | Append to a file	           | write to end	                 | create new
// "r+"	| read extended	| Open a file for read/write   | read from start	             | error
// "w+"	| write extended| Create a file for read/write | destroy contents	             | create new
// "a+"	|append extended| Open a file for read/write   | write to end#pragma region      | create new

// !!! "int putc(char ch, FILE *pFile)" can write to FILE or stream !!!

void DuplicateFileContent()
{
    char ch = '\0';
    // open the same file with different descriptors
    FILE *pFile1;
    FILE *pFile2;

    if ((pFile1 = fopen("test.txt", "r")) && (pFile2 = fopen("test.txt", "a+"))) // check for a NULL ptr
    {
        int res;
        while (1)
        {
            ch = getc(pFile1);
            // printf("ch=%c", ch);
            if (res < 0)
                printf("Error gets() res=%d strerror=%s\n", res, strerror(errno));
            if (ch == EOF)
                break;
            res = putc(ch, pFile2); // !!! Put char to file
            if (res < 0)
                printf("Error putc() res=%d strerror=%s\n", res, strerror(errno));
        }
        if (res < 0)
            printf("Error res=%d strerror=%s\n", res, strerror(errno));
    }
    if (!pFile1 || !pFile2)
        printf("\npFiles=NULL\n");

    putc('\n', stdout); // !!! Put char to stdout
    putc('E', stdout);
    putc('N', stdout);
    putc('D', stdout);
    fclose(pFile1);
    fclose(pFile2);
}

int main()
{
    DuplicateFileContent();
    return 0;
};
