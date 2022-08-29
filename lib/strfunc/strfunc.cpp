#include "strfunc.h"

/*
    TODO: puts, strncpy, strncat, fgets, strdup, getline
*/

size_t string_length(const char *str)
{
    size_t i = 0;
    while((str[i++]))
        continue;
    return i - 1u; /* don't count NUL-terminator */
}

char *string_copy(char *to, const char *from)
{
    char *original = to;
    while ((*(to++) = *(from++)))
        continue;
    return original;
}

char *find_char(const char *str, char c)
{
    for (; *str != c && *str != '\0'; str++)
        continue;

    if (*str == c)
        return (char *) str;
    return NULL;
}

int compare_strings(const char *str1, const char *str2)
{
    for (; *str1 != '\0' && *str2 != '\0'; ++ str1, ++ str2)
        if (*str1 != *str2)
            return *str1 - *str2;
    return 0;
}

char *string_concat(char *to, const char *from)
{
    string_copy(to + string_length(to), from);
    return to;
}
