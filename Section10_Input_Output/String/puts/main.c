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

// !!! "int puts(const char * str)" write to the stdout !!!
// !!! return non negative value if SUCCESS !!!
// !!! automaticaly add '\n' at the end

int main()
{
    char *ch = "Hello puts!";
    if (puts(ch) < 0)
        perror("puts() error");
    if (puts("And good bue!") < 0)
        perror("puts() error");
    return 0;
}
