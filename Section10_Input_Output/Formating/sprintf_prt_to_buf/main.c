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

// !!! "int sprintf(char *buf, const char *format, ...)" print data to buf and automatically add '\0'
// !!! UNSAFE - not check for overflow

int main()
{
    char buf[32] = {[0 ... 31] 1};
    int size = sprintf(buf, "hello Andy %d", 55);
    printf("size=%d data:\n", size);
    puts(buf);

    return 0;
}