#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "strfunc.h"

void put_string(const char *str)
{
    assert(str != NULL);

    const size_t buffer_length = 1024u;

    char buffer[buffer_length] = "";
    size_t length = string_length(str);
    for (size_t i = 0; i < length; i += buffer_length)
    {
        string_ncopy(buffer, str, buffer_length);
        size_t written = 0;
        while (written < buffer_length)
            written += (size_t) write(
                STDIN_FILENO,
                buffer + written,
                buffer_length - written
            );
    }
    while (!write(STDOUT_FILENO, "\n", 1))
        continue;

}

char *file_get_string(FILE *stream, size_t n, char *str)
{
    assert(stream != NULL);
    assert(str != NULL);

    int fd = fileno(stream);
    size_t used = 0;
    while (used < n)
        used += (size_t) read(fd, str + used, n - used);
    return str;
}

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    assert(lineptr != NULL);
    assert(n != NULL);
    assert(stream != NULL);

    const size_t buffer_length = 1024u;

    if (*lineptr == NULL || *n == 0)
    {
        *lineptr = (char*) calloc(buffer_length, sizeof(**lineptr));
        *n = buffer_length;
    }

    for (size_t i = 0; ; i++)
    {
        if (i >= *n - 1)
        {
            *n += buffer_length;
            *lineptr = (char*) reallocarray(*lineptr, *n, sizeof(**lineptr));
        }

        int c = getc(stream);
        if (c == EOF)
        {
            (*lineptr)[i] = '\0';
            return i == 0 ? -1 : (ssize_t) i;
        }
        if (((*lineptr)[i] = (char) c) == '\n')
        {
            (*lineptr)[i + 1] = '\0';
            return (ssize_t) i;
        }
    }

    assert(0 && "Unreachable code");
    return -1;
}

char *string_duplicate(const char *str)
{
    assert(str != NULL);

    char *res = (char *) calloc(1,
                            sizeof(*res) * string_length(str));
    return string_copy(res, str);
}

size_t string_length(const char *str)
{
    assert(str != NULL);

    size_t i = 0;
    while((str[i++]))
        continue;
    return i - 1u; /* don't count NUL-terminator */
}

char *string_copy(char *to, const char *from)
{
    assert(to != NULL);
    assert(from != NULL);

    char *original = to;
    while ((*(to++) = *(from++)))
        continue;
    return original;
}

char *string_ncopy(char *to, const char *from, size_t n)
{
    assert(to != NULL);
    assert(from != NULL);

    char *original = to;
    size_t i = 0;
    while ((i++ < n) && (*(to++) = *(from++)))
        continue;
    while((i++ < n))
        *(to++) = '\0';
    return original;
}

char *find_char(const char *str, char c)
{
    assert(str != NULL);

    for (; *str != c && *str != '\0'; str++)
        continue;

    if (*str == c)
        return (char *) str;
    return NULL;
}

int compare_strings(const char *str1, const char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    for (; *str1 != '\0' && *str2 != '\0'; ++ str1, ++ str2)
        if (*str1 != *str2)
            return *str1 - *str2;
    return 0;
}

char *string_concat(char *to, const char *from)
{
    assert(to != NULL);

    string_copy(to + string_length(to), from);
    return to;
}

static void terminated_string_ncopy(char *to, const char *from, size_t n);

char *string_nconcat(char *to, const char *from, size_t n)
{
    size_t tlen = string_length(to);
    terminated_string_ncopy(to + tlen, from, n);
    return to;
}

static void terminated_string_ncopy(char *to, const char *from, size_t n)
{
    assert(to != NULL);
    assert(from != NULL);
    if (n == 0)
        return;

    while ((n--) && (*(to++) = *(from++)))
        continue;
    
    if (to[-1] != '\0')
        to[0] = '\0';
}
