// C pointers final practicum 
// SWEN-250 Fall 2021
// Larry Kiser December 8, 2021

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cfinal.h"
#include "unit_tests.h"

// Return a NULL pointer if pfirst or psecond is a NULL pointer..
//
// The purpose of this function is to return a string that you
// create by copying the pfirst and the psecond strings to a new
// malloc'ed string. You then return this malloc'ed string.
//
// NOTE -- you must malloc exactly the amount of space needed to
// store both strings.
//
// Example: pfirst is "start " and psecond is "end". You will
// create a new string containing "start end". You return a pointer to
// this new string.
//
// You are allowed to use functions like strlen and strcat.
//
// Parameters:
//		*pfirst is a character pointer to first string to copy to your new string.
//		*pfirst is a character pointer to second string to copy after the first string to your new string.
//		position is an index into pstring that may or may not be a valid location in pstring.
//      Note that position 0 is the first character in pstring.
char *make_big_string_from_two( char *pfirst, char *psecond )
{
	// Your code here -- be sure to free pstring as described above!

	return BOGUS_POINTER ;		// FIX THIS!!
}


// Analyzes a passed string and makes a copy of that string on the heap using malloc.
// Returns 0 if the passed string is NULL or the passed struct pointer is NULL.
// When returning a 0 do not malloc any space and do not modify the passed struct.
//
// Returns 1 when both parameters are not NULL even if the passed string is an empty string.
// If the passed string is an empty string all counts are (of course) zero.
// In the empty string case the string_copy must be a malloc'ed area of the minimum
// size to contain an empty string.
//
// You must malloc the minimum size on the heap to get a copy of the passed string 
// NOTE -- the struct definition is in cfinal.h
// You must count the number of upper case, lower case, and numeric characters and
// record those counts in the struct's count values.
int string_statistics( char *string, struct statistics *p_statistics )
{
	// avoid crash in unit_test 12
	if ( p_statistics != NULL )
		p_statistics->string_copy = BOGUS_POINTER ;
	
	// your code here

	return 2 ;		// bogus -- fix this!
}

// p_integers points to an array of integers.
// number_of_integers specifies the length of this array.
// if p_integers is a NULL pointer return BAD_PARAMETERS (defined in cfinal.h)
// if number_of_integers is zero or negative return BAD_PARAMETERS
// if both parameters are valid return the sum of every odd integer in the array.
int add_odd_integers( int *p_integers, int number_of_integers )
{
	// your code here

	return -1 ;		// bogus -- fix this!
}

// This function is implemented incorrectly. You need to correct it.
// Refer to the comments on what the code is supposed to be doing.
// In most cases the code is not doing what the comment says it should do.
// When fixed it swaps the third and fourth characters in the passed string.
// It returns returns 1 on success.
// It returns 0 if the passed string is NULL or is an empty string.
// If it is not empty you can assume it has at least four characters.
//
int fix_bad_code( char *pstring )
{
	// test to return 0 if pstring is NULL
	if ( pstring = NULL )
		return -1 ;

	// make sure pstring is not NULL before attempting to use it
	if ( pstring != NULL )
	{
		// return 0 if pstring is an empty string
		if ( pstring == '\0' )
			return 0 ;
		else	// string is not empty so OK to swap.
		{
			pstring += 3 ;	// point to the third character
			// now swap the characters
			*pstring = *( pstring + 1 ) ;
			*( pstring + 1 ) = *pstring ;
		}
	}
	
	return 2 ;
}

