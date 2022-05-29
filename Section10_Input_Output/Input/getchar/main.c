#include <stdio.h>

//// File access
// mode | Meaning       | Explanation                  | Action if file already exists   | Action if file  does not exist
// "r"	| read	        | Open a file for reading      | read from start                 | failure to open
// "w"	| write	        | Create a file for writing	   | destroy contents	             | create new
// "a"	| append        | Append to a file	           | write to end	                 | create new
// "r+"	| read extended	| Open a file for read/write   | read from start	             | error
// "w+"	| write extended| Create a file for read/write | destroy contents	             | create new
// "a+"	|append extended| Open a file for read/write   | write to end#pragma region      | create new

// !!! "int getchar(void)" can only read stdin !!!

void ReadCharFromKeyboard()
{
    char ch = '\0';
    printf("Enter your character: ");
    ch = getchar(); // getchar() returns an int, then convert int to char
    printf("character=%c\n", ch);
}

// read from keyboard until press CNTRL-D (EOF)
void ReadCharFromKeyboardUntilCtrlD()
{
    char ch = '\0';
    while (ch != EOF)
    {
        // printf("Enter your character: ");
        ch = getchar(); // getchar() returns an int, then convert int to char
        printf("character=%c\n", ch);
    }
}

int main()
{
    ReadCharFromKeyboard();
    printf("\n\n");
    ReadCharFromKeyboardUntilCtrlD();
    return 0;
};
