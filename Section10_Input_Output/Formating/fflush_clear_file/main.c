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

// !!! "int fflush(FILE * file)" data in file
// !!! 0 if SUCCESS, otherwise return EOF

int main()
{
    FILE * f = fopen("test.txt", "w");
    if (fflush(f) == 0)
        printf("fflush() file is SUCCESS\n");

    puts("STDOUT DATA");

    if (fflush(stdout) == 0)
        printf("fflush() stdout is SUCCESS\n");
    return 0;
}