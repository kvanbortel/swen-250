/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"

// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.

// Search for c in str, return a pointer to the first occurrence,
// or a pointer to the end of the string if it was not found
static char *my_strchr(char *str, char c) {
    while (*str != '\0' && *str != c)
    {
        str++;
    }

    return str;
}

// Save state of str as the start of a new token
// Get the end of the token with my_strchr
// Set the end of the token (the delimiter) to a null terminator to return the first part of the string
// Save the pointer to the start of the next token
static char *my_strtok(char **str, char d) {
    char *start = *str;
    char *end_of_token = my_strchr(start, d);

    if (*end_of_token == '\0')
    {
        *str = NULL;
    }
    else
    {
        *end_of_token = '\0';
        *str = end_of_token + 1;
    }

    return start;
}

// Read input into an array.
// Tokenize the input. For each token, convert and store results.
void read_data( char *my_char, int *my_int, double *my_double ) {
    char line[64];
    int i;
    int next_char;
    for (i = 0; i < 64; i++)
    {
        next_char = getchar();

        if (next_char == EOF)
            break;

        line[i] = next_char;
    }
    line[i] = '\0';

    char *pos = line;
    *my_char = *my_strtok(&pos, '$');
    *my_int = atoi(my_strtok(&pos, '$'));
    *my_double = atof(my_strtok(&pos, '$'));

	return ;
}
