
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = "My initial string";
    printf("init str: %s\n", str);
    int startChar = 5;
    char *newStr = strdup(&str[startChar]);
    printf("strdup() from %d: %s\n", startChar, newStr);

    int totalChar = 3;
    char *new2Str = strndup(&str[startChar], totalChar);
    printf("strndup() from %d with total %d chars: %s\n", startChar, totalChar, new2Str);
    free(newStr);
    free(new2Str);

    return 0;
}
