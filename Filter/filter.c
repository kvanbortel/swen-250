/*
 * Implementation of functions that filter values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h> OTHER THAN
 * strcpy() and strlen()
 *****
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filter.h"

#define NUL ('\0')

/*
 * YOU MAY FIND THIS FUNCTION USEFUL.
 * Return true if and only if character <c> is in string <s>.
 */
static bool includes(char c, char *s) {
    while( *s && c != *s ) {
        s++ ;
    }
    return c == *s ;
}

/*
 * YOU MAY ALSO FIND THIS FUNCTION USEFUL.
 * Return true if and only if string <pre> is a prefix of string <s>.
 */
static bool prefix(char *s, char *pre) {
    while( *pre && *s == *pre ) {
        s++ ;
        pre++ ;
    }
    return *pre == NUL ;
}

/*
 * Copy <string> to <result> while removing all occurrences of <ch>.
 */
void filter_ch_index(char string[], char result[], char ch) {
    int i = 0;
    int j = 0;
    for ( ; string[i] != NUL; i++)
    {
        if (string[i] != ch)
        {
            result[j] = string[i];
            j++;
        }
    }
    result[j] = NUL ;
}

/*
 * Return a pointer to a string that is a copy of <string> with
 * all occurrences of <ch> removed. The returned string must occupy
 * the least possible dynamically allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_ch_ptr(char *string, char ch) {
    char *src_pos = string;
    char *dest = malloc(strlen(string) + 1);
    char *dest_pos = dest;
    for ( ; *src_pos != NUL; src_pos++)
    {
        if (*src_pos != ch)
        {
            *dest_pos = *src_pos;
            dest_pos++;
        }
    }
    *dest_pos = NUL;
    char *result = realloc(dest, dest_pos - dest + 1);
    return result ;
}

/*
 * Copy <string> to <result> while removing all occurrences of
 * any characters in <remove>.
 */
void filter_any_index(char string[], char result[], char remove[]) {
    int i = 0;
    int j = 0;
    for ( ; string[i] != NUL; i++)
    {
        if (!includes(string[i], remove))
        {
            result[j] = string[i];
            j++;
        }
    }
    result[j] = NUL ;
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of any characters in <remove>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_any_ptr(char *string, char* remove) {
    char *src_pos = string;
    char *dest = malloc(strlen(string) + 1);
    char *dest_pos = dest;
    for ( ; *src_pos != NUL; src_pos++)
    {
        if (!includes(*src_pos, remove))
        {
            *dest_pos = *src_pos;
            dest_pos++;
        }
    }
    *dest_pos = NUL;
    char *result = realloc(dest, dest_pos - dest + 1);
    return result ;
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of the substring <substr>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE ARRAY INDEXING.
 *****
 */
char *filter_substr(char *string, char* substr) {
    char *src_pos = string;
    char *dest = malloc(strlen(string) + 1);
    char *dest_pos = dest;
    while (*src_pos != NUL)
    {
        if (prefix(src_pos, substr))
        {
            src_pos += strlen(substr);
        }
        else
        {
            *dest_pos = *src_pos;
            dest_pos++;
            src_pos++;
        }
    }
    *dest_pos = NUL;
    char *result = realloc(dest, dest_pos - dest + 1);
    return result ;
}
