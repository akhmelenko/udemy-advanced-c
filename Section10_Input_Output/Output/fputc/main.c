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

// !!! "int fputc(char ch, FILE *pFile)" (is not a macro) can write to FILE or stream !!!

void WriteToFile()
{
    FILE *pFile;
    if (pFile = fopen("test.txt", "a")) // check for a NULL ptr
    {
        for (char ch = 'A'; ch <= 'G'; ch++)
        {
            fputc(ch, pFile);
        }

        fclose(pFile);
    }
}

void WriteToStream()
{
    for (char ch = 'H'; ch <= 'M'; ch++)
    {
        fputc(ch, stdout);
    }
}

int main()
{
    WriteToFile();
    WriteToStream();
    return 0;
};
