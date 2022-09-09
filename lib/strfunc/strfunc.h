#ifndef STRFUNC_H
#define STRFUNC_H

/**
 * @file strfunc.h
 * @author MeerkatBoss
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

/**
 * @brief Outputs string to stdout, followed by '\\n'
 * 
 * @param[in] str - printed string
 */
void put_string(const char *str);

/**
 * @brief
 * Reads no more than `n - 1` characters from stream,
 * appends '\\0' at end
 * 
 * @param[in] stream - input stream 
 * @param[in] n - maximum stored length
 * @param[out] str - output string
 * @return Parameter `str`
 */
char *file_get_string(FILE *stream, size_t n, char *str);

/**
 * @brief Reads string delimited by '\\n' from stream
 * 
 * @param[inout] lineptr - allocated line
 * @param[inout] n - length of allocated line
 * @param[in] stream - input stream
 * @return Number of characters read or -1 upon failure
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/**
 * @brief Calculates length of a string
 * 
 * @param[in] str - string
 * @return Length of a string
 */
size_t string_length(const char *str);

/**
 * @brief Copies contents of a string to another string
 * 
 * @param[out] to - destination string
 * @param[in] from - source string
 * @return Parameter `to`
 * 
 * @warning
 * If memory allocated for `to` is not enough to store `from`
 * this will lead to undefined behavior
 */
char *string_copy(char *to, const char *from);

/**
 * @brief Allocates memory and stores string
 * 
 * @param[in] str - source string
 * @return Allocated string
 * 
 * @note Memory is allocated with calloc and can be freed with free
 */
char *string_duplicate(const char *str);

/**
 * @brief
 * Copies no more than `n` characters from a string to another
 * string. If source string contains less than `n` characters,
 * additional '\\0' characters are appended, to ensure that
 * exactly `n` characters were written to destination string
 * 
 * @param[out] to - destination string
 * @param[in] from - source string
 * @param[in] n - maximum number of characters to copy
 * @return Parameter `to`
 * 
 * @warning
 * If memory allocated for `to` is not enough to store the result
 * this will lead to undefined behavior
 */
char *string_ncopy(char *to, const char *from, size_t n);

/**
 * @brief Finds first occurence of a character in string 
 * 
 * @param[in] str - string
 * @param[out] c - searched character
 * @return Pointer to found character or NULL if character was not found
 */
char *find_char(const char *str, char c);

/**
 * @brief Compares two string alphabetically
 * 
 * @param[in] str1 - first string
 * @param[in] str2 - second string
 * @return
 * Positive number if `str1` is lexicographically bigger than `str2`;
 * Negative number if `str1` is lexicographically less   than `str2`;
 * Zero if `str1` is equal to `str2`
 */
int compare_strings(const char *str1, const char *str2);

/**
 * @brief Appends string to another string
 * 
 * @param[inout] to - string to append to
 * @param[in] from - appended string
 * @return Parameter `to` 
 * 
 * @warning
 * If memory allocated for `to` is not enough to store
 * concatenated strings this will lead to undefined behavior
 */
char *string_concat(char *to, const char *from);

/**
 * @brief
 * Appends no more than `n` characters from string to another string.
 * NUL-terminator is always appended
 * 
 * 
 * @param[inout] to - string to append to
 * @param[in] from - appended string
 * @param[in] n - maximum number of characters to be appended
 * @return Parameter `to` 
 * 
 * @warning
 * If memory allocated for `to` is not enough to store the result
 * this will lead to undefined behavior
 */
char *string_nconcat(char *to, const char *from, size_t n);

#endif