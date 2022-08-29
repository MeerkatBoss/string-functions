#include <stdio.h>
#include <stdlib.h>
#include "strfunc.h"

int main()
{
    char str1[] = "ABCDEF";
    char str2[] = "ABCD";
    char *str3 = (char *) calloc(1, sizeof(str1) + sizeof(str2));
    string_copy(str3, str1);
    string_concat(str3, str2);
    printf("%s + %s = %s\n", str1, str2, str3);
    return 0;
}