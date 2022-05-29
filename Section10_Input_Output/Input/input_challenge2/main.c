
#include <stdio.h>
#include <ctype.h>

//// File access
// mode | Meaning       | Explanation                  | Action if file already exists   | Action if file  does not exist
// "r"	| read	        | Open a file for reading      | read from start                 | failure to open
// "w"	| write	        | Create a file for writing	   | destroy contents	             | create new
// "a"	| append        | Append to a file	           | write to end	                 | create new
// "r+"	| read extended	| Open a file for read/write   | read from start	             | error
// "w+"	| write extended| Create a file for read/write | destroy contents	             | create new
// "a+"	|append extended| Open a file for read/write   | write to end#pragma region      | create new

void ToggleLettersCase(const char *fileName)
{
    // open the same file for read and write with different file ptrs
    FILE *pFileRead = fopen(fileName, "r");
    FILE *pFileWrite = fopen(fileName, "r+");
    char ch = '\0';
    while ((ch = getc(pFileRead)) != EOF)
    {
        if (isupper(ch))
            fputc(tolower(ch), pFileWrite);
        else
            fputc(toupper(ch), pFileWrite);
    }
    pclose(pFileRead);
    pclose(pFileWrite);
}

int main(int argc, char *argv[])
{
    printf("argv=%d\n", argc);
    if (argc == 2)
    {
        ToggleLettersCase(argv[1]);
    }
    else
    {
        printf("Incorrect number of arguments!\n");
    }

    return 0;
}