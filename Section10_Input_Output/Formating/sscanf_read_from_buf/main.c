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

// !!! "int sscanf(const char * srcBuf, const char *format, ...)" read data by word(separated by space) from buf and save to the pointed variable (add '\0' at the end)
// !!! return number of receiving arguments

int main()
{
    char srcbuf[] = "Anton    engineer 39";
    char name[32];
    char position[32];
    int age;

    sscanf(srcbuf, "%s%s%d", name, position, &age); // %s(name = Anton), %s(position = engineer), %d(age = 39)
    printf("Name: %s\n", name);
    printf("Position: %s\n",position);
    printf("Age: %d\n",age);

    return 0;
}