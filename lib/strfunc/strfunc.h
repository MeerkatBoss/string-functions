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

#include <stddef.h>

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
 * @note If memory allocated for `to` is not enough to store `from`
 * this will lead to undefined behavior
 */
char *string_copy(char *to, const char *from);

/**
 * @brief Finds first occurence of a character in string
 * 
 * @param[in] str - string
 * @param[out] c - searched character
 * @return Pointer to found character or NULL if character was not found
 */
char *find_char(char *str, char c);

/**
 * @brief Compares two string alphabetically
 * 
 * @param[in] str1 - first string
 * @param[in] str2 - second string
 * @return
 * Positive number if `str1` is alpabetically bigger than `str2`;
 * Negative number if `str1` is alpabetically less   than `str2`;
 * Zero if `str1` is equal to `str2`
 */
int compare_strings(const char *str1, const char *str2);

/**
 * @brief Appends string to another string
 * 
 * @param[inout] to - string to append to
 * @param[in] from - appended string
 * @return Parameter `to` 
 */
char *string_concat(char *to, const char *from);

#endif