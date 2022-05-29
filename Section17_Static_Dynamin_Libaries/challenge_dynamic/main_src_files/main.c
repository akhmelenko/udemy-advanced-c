#include <stdio.h>
#include <malloc.h>
#include <my_string.h>

int main()
{
    char c = 'r';
    char *str = "statistics";
    int freq = StringFreqChar(str, c);
    printf("\"%c\" in \"%s\" freq=%d\n", c, str, freq);

    str = "statistics is32 important 123";
    char *newStr = StringRemoveNotAlpha(str);
    printf("newStringNoAlpha=\"%s\"\n", newStr);
    free(newStr);

    str = "Calculate the string length";
    printf("length of \"%s\"=%d\n", str, StringLength(str));

    char str1[50] = "Word1";
    char *str2 = "Word2";
    int ret = StringConcat(str1, str2);
    printf("concat of \"%s\" and \"%s\" =%s with ret=%d\n", "Word1", "Word2", str1, ret);

    char str3[50];
    char *str4 = "Word22";
    ret = StringCopy(str4, str3);
    printf("copy of \"%s\" =%s with ret=%d\n", str4, str3, ret);

    char str5[50] = "erererererererererererererrere";
    char *str6 = "initial string";
    ret = StringGetSubstring(str6, 11, 3, str5);
    printf("substring of \"%s\" =%s with ret=%d\n", str6, str5, ret);
}
