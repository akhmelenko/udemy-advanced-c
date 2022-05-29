
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    // open dynamic object
    void *stringLibHandle = dlopen("../lib_dir/libmystring.so", RTLD_LAZY);
    if (stringLibHandle == NULL)
    {
        fprintf(stderr, "dlopen() error=%s\n", dlerror());
        return -1;
    }
    // clear all dl errors
    dlerror();

    int (*StringFreqChar)(char *, char) = dlsym(stringLibHandle, "StringFreqChar");
    if (StringFreqChar == NULL) // check for errors
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    char c = 'r';
    char *str = "statistics";
    int freq = StringFreqChar(str, c);
    printf("\"%c\" in \"%s\" freq=%d\n", c, str, freq);

    char *(*StringRemoveNotAlpha)(char *) = dlsym(stringLibHandle, "StringRemoveNotAlpha");
    if (dlerror() != NULL) // other way check for errors
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    str = "statistics is32 important 123";
    char *newStr = StringRemoveNotAlpha(str);
    printf("newStringNoAlpha=\"%s\"\n", newStr);
    free(newStr);

    int (*StringLength)(char *) = dlsym(stringLibHandle, "StringLength");
    if (StringLength == NULL)
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    str = "Calculate the string length";
    printf("length of \"%s\"=%d\n", str, StringLength(str));

    int (*StringConcat)(char *, char *) = dlsym(stringLibHandle, "StringConcat");
    if (StringConcat == NULL)
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    char str1[50] = "Word1";
    char *str2 = "Word2";
    int ret = StringConcat(str1, str2);
    printf("concat of \"%s\" and \"%s\" =%s with ret=%d\n", "Word1", "Word2", str1, ret);

    int (*StringCopy)(char *, char *) = dlsym(stringLibHandle, "StringCopy");
    if (StringCopy == NULL)
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    char str3[50];
    char *str4 = "Word22";
    ret = StringCopy(str4, str3);
    printf("copy of \"%s\" =%s with ret=%d\n", str4, str3, ret);

    int (*StringGetSubstring)(char *, int, int, char *) = dlsym(stringLibHandle, "StringGetSubstring");
    if (StringGetSubstring == NULL)
    {
        fprintf(stderr, "dlsym() error=%s\n", dlerror());
        return -1;
    }
    char str5[50] = "erererererererererererererrere";
    char *str6 = "initial string";
    ret = StringGetSubstring(str6, 11, 3, str5);
    printf("substring of \"%s\" =%s with ret=%d\n", str6, str5, ret);

    // close dynamic object
    if (dlclose(stringLibHandle) != 0)
    {
        fprintf(stderr, "dlclose() error=%s\n", dlerror());
        return -1;
    }
}