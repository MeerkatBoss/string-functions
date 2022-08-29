#include "strfunc.h"

size_t string_length(const char *str)
{
    size_t i = 0;
    while((str[i++]))
        {}
    return i - 1u; /* don't count NUL-terminator */
}

char *string_copy(char *to, const char *from)
{
    while ((*(to++) = *(from++)))
        {}
    return to;
}

char *find_char(char *str, char c)
{
    for (; *str != c && *str != '\0'; str++)
        {}
    if (*str == c)
        return str;
    return NULL;
}

int compare_strings(const char *str1, const char *str2)
{
    while (*str1 != '\0'
        && *str2 != '\0'
        && (*(str1) == *(str2)))
        {
            str1++;
            str2++;
        }
    return *str1 - *str2;
}

char *string_concat(char *to, const char *from)
{
    while ((*(to++)))
        {}
    to--;
    return string_copy(to, from);
}
