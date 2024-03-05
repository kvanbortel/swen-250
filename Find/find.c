/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
    char *p_str = string;
    int i;
    for (i = 0; *p_str != '\0'; i++)
    {
        if (*p_str++ == ch)
            return i;
    }
	return NOT_FOUND ;
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
	char *p_str = string;
    while(*p_str != '\0')
    {
        if (*p_str++ == ch)
            return --p_str;
    }
    return NULL ;
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
    int i;
    int j;
    char *p_str = string;
    for (i = 0; *p_str != '\0'; i++)
    {
        char *p_stop = stop;
        for (j = 0; *p_stop != '\0'; j++)
        {
            if (*p_str == *p_stop++)
                return i;
        }
        *p_str++;
    }
    return NOT_FOUND ;
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char* stop) {
	char *p_str = string;
    char *p_stop = stop;
    while (*p_str != '\0')
    {
        char *p_stop = stop;
        while (*p_stop != '\0')
        {
            if (*p_str == *p_stop++)
                return p_str;
        }
        *p_str++;
    }
    return NULL ;	// placeholder
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char* substr) {
	return NULL ;	// placeholder
}
