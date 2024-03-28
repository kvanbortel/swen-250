// C pointers Practicum with malloc and free
// SWEN-250
// Larry Kiser October 30, 2015
// Larry Kiser updated to summer version July 11, 2017
// Larry Kiser (LLK) updated March 20, 2018
// Larry Kiser converted to run on Ubuntu and improved text.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cpracticum2.h"
#include "unit_tests.h"


// This function is implemented incorrectly. You need to correct it.
// When fixed it returns 1 if there are any digits (0 through 9) anywhere in the passed string.
// If there are no digits it returns 0.
// It also returns 0 if the passed string pointer is NULL or if the string points to an empty string.
// You can re-write this code completely if you prefer.
int fix_bad_code( char *pstring )
{
	int result = 0 ;	// is this a good choice for initialization?
	
	// Fix this next line so it correctly returns 0 if the passed pointer is NULL or
	// if the pointer points to an empty string.
	if ( pstring == NULL || *pstring == '\0' )
		return result;
	
	// does this loop work correctly?
	while ( *pstring != '\0' )
	{
		if ( isdigit( *pstring++ ) )	// isdigit returns true if the passed character is a number 0 through 9
			result = 1 ;
	}
		
	return result;
}

// Determine if the p_unknown pointer points to one of the integers in the  array of integers.
// You need to use num_int_in_array -- this is the number of integers in the p_int_array array.
// return 1 if p_unknown pointer points to one of the integers in the array of integers.
// If not return 0.
// For example, if p_int_array has 3 entries then p_unknown points to one of the integers
// in the array if it points to the first, second, or third entry.
// Hint -- use pointer arithmetic to solve this.
// NOTE -- only look at the positions defined as valid by the num_int_in_array!
int is_pointer_in_array( int *p_int_array, int *p_unknown, int num_int_in_array )
{
	int i;
	for (i = 0 ; i < num_int_in_array; i++)
	{
		int *wp_int = p_int_array;
		int j;
		for (j = 0; j < num_int_in_array; wp_int++, j++)
		{
			if (*p_unknown == *wp_int)
				return 1;
		}
	}
	return 0;

}

// The first time this is called return the first unsigned char in the mylist array.
// The second time this is called return the second unsigned char in the mylist array.
// On subsequent calls return the next entry in mylist.
// HOWEVER, after you return the last item in the array the next call must return
// the first element in the array followed by returning the second element.
unsigned char my_random()
{
	unsigned char mylist[] = { 5, 9, 254, 129, 55, 8, 32, 99, 207 } ; // DO NOT change this array!
	// your code here
	static unsigned char value = 0;
	static int i = 0;
	int size = sizeof(mylist);
	if (i < size)
	{
		value = mylist[i];
		i += 1;
	}
	else
	{
		i = 0;
		value = mylist[i];
		i++;
	}
	return value ;
}

// Using malloc create an integer array called  p_product that contains exactly number_of_entries.
// Store the product of each value in pfirst and psecond in the corresponding postion in p_product.
// e.g. p_product[0] = p_first[0] * p_second[0]; p_product[1] = p_first[1] * p_second[1]
// The p_first and p_second arrays are the same size.
// The third parameter is the number of entries in each array.
// Return NULL if either array pointer is NULL.
// Return NULL if the number of entries is <= 0.
int *create_array_of_products( int *p_first, int *p_second, int number_of_entries )
{
	if (p_first == NULL || p_second == NULL || number_of_entries <= 0)
		return NULL;

	int *p_product = malloc(sizeof(int) * number_of_entries);
	int i;
	for (i = 0; i < number_of_entries; i++)
	{
		p_product[i] = p_second[i] * p_first[i];
	}

	return p_product ;
}

// Calculate the total of all of the entries in the passed array and return that total.
// Return a zero if the passed array (pointer) is NULL or the number of entries
// is less than or equal to 0.
// Only free the passed pointer if it is not NULL and the number of entries is greater than 0.
// hint: be sure to free the passed pointer only as described above!
int get_total_and_free( int *p_array, int number_of_entries )
{
	if (p_array == NULL || number_of_entries <= 0)
		return 0;

	int *wp_array = p_array;
	int sum = 0;
	int i;
	for (i = 0; i < number_of_entries; i++, wp_array++)
	{
		sum += *wp_array;
	}
	free (p_array);


	return sum;
}

