// C pointers practicum 2 with malloc and free
// SWEN-250 Term 2225
// Larry Kiser Mar. 30, 2023

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpracticum2.h"
#include "unit_tests.h"


// This function is implemented incorrectly. You need to correct it.
//
// When fixed it changes the third character in the passed string to 'A'.
// It returns returns 1 on success.
// It returns 0 if the passed string is NULL or is an empty string.
// If the passed string is not empty you can assume it has at least three characters.
//
// NOTE -- you are NOT allowed to use an index value in your solution.
//         You cannot use "pstring + index" or "pstring[index]" syntax.
//         You can use the increment and decrement operators (++ and --).
//         You can move the pointer with code like this: p += 4 which moves the pointer 4 positions.
//
int fix_bad_code( char *pstring )
{
	// Pro-Tip: add code here to check for a NULL pointer to avoid a crash
	if (pstring == NULL || *pstring == '\0') // or do if (strlen(pstring) == 0) {return 0;}
		return 0;

	pstring += 2 ; 
	*pstring = 'A' ;

	return 1 ;
}


// Compare two arrays of integers that are terminated by the special
// value of -1 (the -1 says this is the end of the array)
//
// NOTE -- you are NOT allowed to use an index value in your solution.
//         You cannot use "pfirst + index" or "pfirst[index]" syntax.
//         Pro-Tip: use work pointers.
//
// Return 0 if the two arrays are identical. You must confirm that all values are the same!
// Return 1 if they are not the same length.
// Return 2 if one or more values are different but they are the same length.
// return 3 if either pointer is NULL.
int compare_arrays( int *pfirst, int *psecond )
{
	if (pfirst == NULL || psecond == NULL)
		return 3;

	for ( ; ; pfirst++, psecond++)
	{
		if (*pfirst == -1 && *psecond == -1)
			break;
		else if (*pfirst == -1 || *psecond == -1)
			return 1;
		if (*pfirst != *psecond)
			return 2;
	}
	return 0;


// Solution:
//	int status = 3; // default to one or both pointers are NULL
//	if  (pfirst != NULL || psecond != NULL)
//	{
//		int *p1 = pfirst;
//		int *p2 = psecond;
//
//		// look for different lengths
//		for ( ; *p1 != -1 && *p2 != -1; p1++, p2++);
//		if (*p1 == -1 && *p2 == -1) // if are the same length
//		{
//			for (p1 = pfirst, p2 = psecond; *p1 != -1; p1++, p2++)
//			{
//				if (*p1 != *p2)
//					return 2;
//			}
//		}
//		else
//			return 1;
//
//		status = 0; // assume both are the same
//	}
//	return status;

}

// The first time this is called it returns the number passed in the value parameter.
// The second time it returns the sum of the previous value and the current value parameter.
// Each time after that it returns the sum of all previous values and the current value.
// FOR EXAMPLE: Successive calls passing in 7, 2, and 3 would return 7 first time, 9 the second time,
// and 12 on the third time.
int sum_each_number( int value )
{
	static int last_value = 0; // static is only initialized at program start
	last_value += value;
	return last_value;
}


// Create a new key_value_pair struct by allocating space on the heap (use malloc).
// Here is a copy of the struct from cpracticum2.h for your convenience:
	// struct for create_copy function
	//struct key_value_pair
	//{   
    //	char *key ; 
    //	char *value ;
	//} ;
// You will also need to malloc space for the key and value strings
// in your malloc'd struct. You must malloc the exact amount of space
// needed for the key and the value string. Copy the passed key and
// value strings into this struct you created.
// Return this struct that you created.
//
// NOTE -- at the end of the unit tests the space you malloc'd for
//         the key, value, and the key_value_pair struct will be freed.
//         This code is at the bottom of unit_tests.c.
// NOTE -- If your code is incorrect you will get a severe error. If you cannot
//         get it to work without crashing comment out your code and return NULL.
// NOTE -- you are allowed to use strcpy.
// NOTE -- The passed key and value strings are valid and not empty. You do
//         not have to test the key and value strings for NULL or empty.
struct key_value_pair *create_key_value ( char *key, char *value )
{
	struct key_value_pair *new_pair = malloc(sizeof(struct key_value_pair));
	new_pair->key = malloc(strlen(key) + 1);
	strcpy(new_pair->key, key);

	new_pair->value = malloc(strlen(value) + 1);
	strcpy(new_pair->value, value);

	return new_pair;
}
