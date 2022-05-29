#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool IsPrime(int x){
    for (int i = 2; i < x/2; i++){
        if (x % i == 0)
            return false;
    }
    return true;
}

void MySolution(){
    FILE *f = fopen("numbers.txt", "r");
    if (!f)
        fprintf(stderr, "error open file!\n");
    char *buf = NULL;
    size_t len = 0;
    ssize_t readNumber;

    while((readNumber = getline(&buf, &len, f)) != -1){
        int number;
        char *pWord = buf;
        while(sscanf(pWord, "%d", &number) > 0){
            printf("%d - ", number);
            // process number
            if (number > 0 && IsPrime(number))
                    printf("prime\n");
            else if (number % 2 == 0)
                printf("even\n");
            else
                printf("odd\n");            
            // skip current digit
            while(pWord[0] != '\n' && pWord[0] != ' ' && pWord[0] != '\t')
                pWord++;
            // skip space
            while(pWord[0] != '\n' && (pWord[0] == ' ' || pWord[0] == '\t')){
                pWord++;
            }
            if (pWord[0] == '\n')
                break;
            // printf("search=%d\n", (int)pWord);
        }
    }
    free(buf);

    fclose(f);
}

void JasonSolution(){
    FILE *f = fopen("numbers.txt", "r");
    if (!f)
        fprintf(stderr, "error open file!\n");
        // exit(EXIT_FAILURE);
    int num;
    while(fscanf(f, "%d", &num) != -1){
            // process number
            printf("%d - ", num);
            if (num > 0 && IsPrime(num))
                    printf("prime\n");
            else if (num & 1)
                printf("odd\n");
            else
                printf("even\n");            
    }

    fclose(f);
}

int main()
{
    JasonSolution();

    return 0;
}