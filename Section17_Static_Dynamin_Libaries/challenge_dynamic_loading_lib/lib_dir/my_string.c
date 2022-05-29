#include <stdio.h>
#include <malloc.h>

int StringFreqChar(char *str, char c)
{
    int freq = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == c)
            freq++;
    }
    return freq;
}

int StringLength(char *str)
{
    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        cnt++;
    }
    return cnt;
}

char *StringRemoveNotAlpha(char *str)
{
    // calc alloc size
    int cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z' || 'A' <= str[i] && str[i] <= 'Z')
            cnt++;
    }
    // alloc
    char *newStr = (char *)malloc(cnt + 1);
    newStr[cnt] = 0;
    // fill the new string
    cnt = 0;
    for (int i = 0; str[i]; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z' || 'A' <= str[i] && str[i] <= 'Z')
        {
            newStr[cnt] = str[i];
            cnt++;
        }
    }
    return newStr;
}

int StringConcat(char *str0, char *str1)
{
    if (!str0 || !str1)
        return -1;
    int length = StringLength(str0);
    // copy str1 to end of str0
    int i = 0;
    for (; str1[i]; i++)
    {
        str0[length + i] = str1[i];
    }
    str0[length + i] = 0;
    return 0;
}

int StringCopy(char *src, char *dest)
{
    if (!src || !dest)
        return -1;
    int i = 0;
    for (; src[i]; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return 0;
}

int StringGetSubstring(char *src, int start, int length, char *target)
{
    if (!src || !target || start + length > StringLength(src) || length > StringLength(target))
        return -1;
    int i = 0;
    for (; i < length; i++)
    {
        target[i] = src[start + i];
    }
    target[i] = 0;
    return 0;
}