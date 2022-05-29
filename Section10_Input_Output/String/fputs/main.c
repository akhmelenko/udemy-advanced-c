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

// !!! "int fputs(const char * str, FILE * stream)" write to the file/stdout !!!
// !!! return non negative value if SUCCESS !!!
// !!! DO NOT automaticaly add '\n' at the end!
// !!! DO NOT automaticaly add '\0' at the end!

int main()
{
    FILE *pFile = fopen("test.txt", "w");
    if (!pFile)
    {
        perror("fopen() error!");
        return -1;
    }
    char *ch = "Hello fputs!";
    if (fputs(ch, pFile) < 0)
        perror("fputs() error");
    if (fputs("And good bue!", pFile) < 0)
        perror("fputs() error");
    fclose(pFile);

    return 0;
}
