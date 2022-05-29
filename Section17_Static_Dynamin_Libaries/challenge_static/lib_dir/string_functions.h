
#ifndef _STRING_FUNCTIONS_H_
#define _STRING_FUNCTIONS_H_

int StringFreqChar(char *str, char c);
int StringLength(char *str);
char *StringRemoveNotAlpha(char *str);
int StringConcat(char *str0, char *str1);
int StringCopy(char *src, char *dest);
int StringGetSubstring(char *src, int start, int length, char *target);

#endif //_STRING_FUNCTIONS_H_