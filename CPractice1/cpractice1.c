// C (no pointers) Practice Practicum
// SWEN-250
// Larry Kiser October 30, 2015

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpractice1.h"
#include "unit_tests.h"


// Get the length of a string
int get_size(char mystring[])
{
    int i;
    for (i = 0; ; i++)
    {
        if (mystring[i] == '\0')
            break;
    }
    return i;
}

// Returns the index position of the requested character
// in the string that is in the array.
// Returns a -1 if the requested character is not found.
// NOTE -- you must also handle an empty string. If mystring is
//         empty then you must ALWAYS return a -1.
// You are NOT allowed to use any library functions to do this.
// You must search the array and return the correct result.
int find_char_in_array( char mystring[], char find_this_character )
{
    int i;
    for (i = 0; mystring[i] != '\0'; i++)
    {
        if (mystring[i] == find_this_character)
            return i;
    }

	return -1 ;
}

// This function is implemented incorrectly. You need to correct it.
// This function is supposed to return 0 if the two integers passed to
// this function are equal. If first is larger than second then return 1.
// If first is less than second then return -1.
int fix_bad_code( int first, int second )
{
	if ( first == second )
		return 0 ;
	if ( first > second )
		return 1 ;
	return -1 ;
}

// Create your own version of strcat (string concatenation meaning to add a string
// to the end of an existing string).
// You can assume that the target string (the one receiving the additional string at its
// end has enough space in its array to take that string.
// NOTE -- you must handle the cases where the target string is an empty string and
//         where the source_string is an empty string.
void add_string_to_end( char target_string[], char source_string[] )
{
    int size = get_size(target_string);
    int i;

    for (i = 0; source_string[i] != '\0'; i++)
        target_string[size + i] = source_string[i];

    target_string[size + i] = '\0';

}

// Returns the mydata struct that is typedef'ed in cpractice1.handle
// Copy the first character in the passed string array to the first_character
// field in mydata. Set the count field in mydata to the number of actual
// characters in the passed string. Do not include the end of string character.
// NOTE -- you must handle an empty string. If you have an empty string set
//         set the count to a -1 and the first_character to '\0'.
// NOTE -- you cannot use any library functions in this code.
// For your convenience I have made a copy of that struct definition below:
//
//typedef struct
//{
//	int count ;				// the number of characters in the string
//							// (not including the end of string)
//	char first_character ;	// the first character in the string.
//} mydata ;


mydata get_string_info( char mystring[] )
{
	mydata data ;

    if (mystring[0] == '\0')
    {
        data.count = -1;
        data.first_character = '\0';
    }

    else
    {
        data.first_character = mystring[0];
        data.count = get_size(mystring);
	}

	return data ;
}

// Run the unit tests or as a "normal program".
int main( int argc, char *argv[] ) {

	// Execute unit tests if program name contains "test".
	if ( strstr( argv[0], "test" ) )
		return test() ;

	printf( "\nDoes nothing -- please run unit tests instead.\n\n" ) ;
	
	return 0 ;
}
