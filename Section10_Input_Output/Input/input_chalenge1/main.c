
#include <stdio.h>
#include <ctype.h>

void CalcWordsAndChars(FILE * pFile){
    int cCnt = 0;
    int wCnt = 0;
    char ch = '\0';
    while ((ch = getc(pFile)) != EOF){
        cCnt++;
        if (isspace(ch))
            wCnt++;
    }
    printf("Number of words =%d, number of characters =%d", wCnt, cCnt);
}

int main(int argv, char *argc[]){
    printf("argv=%d\n", argv);
    if (argv == 1){
        CalcWordsAndChars(stdin);
    } else if (argv == 2){
        FILE * pFile = fopen(argc[1], "r");
        if (pFile)
            CalcWordsAndChars(pFile);
        pclose(pFile);
    } else {
        printf("Incorrect number of arguments!\n");
    }
 
    return 0;
}