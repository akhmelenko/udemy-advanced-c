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

// !!! "int putchar(char ch)" write stream !!!

void PrintToSTDIO()
{
    char *str = "Hello\n Anton!\n";

    int i = 0;
    while (str[i] != '\0')
    {
        putchar(str[i]); // !!! Put char to stdio
        i++;
    }
}

void LoopBack()
{
    char ch = '\0';

    while ((ch = getchar()) != EOF) // CNTRL-D
    {
        // putchar(ch); // !!! Put char to stdio
        ungetc(ch, stdin);
    }
}

int main()
{
    PrintToSTDIO();
    LoopBack();
    return 0;
};
