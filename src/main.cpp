#include "strfunc.h"

int main()
{
    char *line = NULL;
    size_t n = 0;
    while (get_line(&line, &n, stdin) != -1)
        put_string(line);
    return 0;
}