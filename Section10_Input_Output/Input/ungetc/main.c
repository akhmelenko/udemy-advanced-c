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

// !!! "int ungetc(int ch, FILE *pFile)" !!!
// !!! If return does not equal EOF, pushes the character ch (reinterpreted as unsigned char) into the input buffer associated with the stream!!!

void FilterSpacesInStream()
{
    char ch = '\0';

    while (isspace(ch = getchar()))
        ;
    ungetc(ch, stdin); // send ch back to stream
    printf("filtered character=%c\n\n", getchar());
}

void FilterSpacesInFile()
{
    char ch = '\0';

    FILE *pFile;

    if (pFile = fopen("test.txt", "rw"))
    {
        while (isspace(ch = getc(pFile)))
            ;
        ungetc('u', pFile); // send ch back to stream if space
        printf("filtered character=%c", getchar());
    }
    fclose(pFile);
}

void ChangeSpacesInFile()
{
    char ch = '\0';

    FILE *pFile;

    if (pFile = fopen("test.txt", "r"))
    {
        while (ch != EOF)
        {
            if (isspace(ch = getc(pFile)))
            {
                ungetc('S', pFile); // send "S" back to stream if space
                ungetc('S', pFile); // send "S" back to stream if space
            }
            printf("%c", ch);
        }
    }
    fclose(pFile);
}

int main()
{
    FilterSpacesInStream();
    // FilterSpacesInFile(); // !!! NOT WORKS
    ChangeSpacesInFile();
    return 0;
};
