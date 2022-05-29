#include <stdio.h>

//// File access
// mode | Meaning       | Explanation                  | Action if file already exists   | Action if file  does not exist
// "r"	| read	        | Open a file for reading      | read from start                 | failure to open
// "w"	| write	        | Create a file for writing	   | destroy contents	             | create new
// "a"	| append        | Append to a file	           | write to end	                 | create new
// "r+"	| read extended	| Open a file for read/write   | read from start	             | error
// "w+"	| write extended| Create a file for read/write | destroy contents	             | create new
// "a+"	|append extended| Open a file for read/write   | write to end#pragma region      | create new

// !!! "int fgetc(FILE *pFile)" can only read from FILE !!!

void ReadCharsFromFile()
{
    char ch = '\0';
    printf("ch=%d\n\n", ch);

    FILE *pFile;

    if (pFile = fopen("test.txt", "rw")) // check for a NULL ptr
    {
        while ((ch = fgetc(pFile)) != EOF) // getc() returns an int, then convert int to char
            printf("%c", ch);
    }
    printf("\n");
    fclose(pFile);
}

int main()
{
    ReadCharsFromFile();
    return 0;
};
