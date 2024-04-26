// C pointers final practicum
// SWEN-250
// unit_tests
// Larry Kiser updated December 8, 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "cfinal.h"
#include "unit_tests.h"

// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	
	if ( ! test_result ) {
		va_start( arguments, error_format ) ;
		printf( "Test # %d failed: ", test_number ) ;
		vprintf( error_format, arguments ) ;
		printf( "\n" ) ;
		result = 0 ;
	}
	test_number++ ;
	return result ;
}

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
int test( int all )	// if all is true do the free unit tests at the end
{
	int passcount = 0 ;
	int failcount = 0 ;
	
	printf( "\nTests for make_big_string_from_two.................\n" ) ;

	// Test 1
	assert( make_big_string_from_two( NULL, "a" )  == NULL,
		"Expected NULL because pfirst is NULL" )
		? passcount++ : failcount++ ;

	// Test 2 
	assert( make_big_string_from_two( "b", NULL ) == NULL,
		"Expected NULL because psecond is NULL" )
		? passcount++ : failcount++ ;

	// Test 3
	char *ptest3 = make_big_string_from_two( "one ", "two" ) ;
	int good_pointer = ( ptest3 != NULL && ptest3 != BOGUS_POINTER ) ;
	assert( good_pointer,
		"Expected valid pointer but but it is NULL or BOGUS_POINTER" )
		? passcount++ : failcount++ ;

	// Test 4 
	if ( ! good_pointer )
	{
		assert( 0,
			 "Skipping test 4 due to bad pointer from test 3" ) ;
		failcount++ ;
	}
	else
		assert( strcmp( ptest3, "one two" ) == 0,
			"Expected \"one two\" but got \"%s\"", ptest3 )
		? passcount++ : failcount++ ;
	
	printf( "\nTests for string_statistics.........................\n" ) ;
	
	// Test 5
	struct statistics stat1 ;
	assert( string_statistics( NULL, &stat1 ) == 0,
		"Expect 0 since the string is NULL" )
		? passcount++ : failcount++ ;
	// Test 6
	assert( string_statistics( "", NULL ) == 0,
		"Expect 0 since the statistics struct pointer is NULL" )
		? passcount++ : failcount++ ;
	// Test 7 
	memset( &stat1, 0xff, sizeof(stat1) ) ;	// fill with bad values
	stat1.string_copy = BOGUS_POINTER ;		// use standard bogus pointer
	assert( string_statistics( "", &stat1 ) == 1,
		"Expect 1 since both parameters are not NULL" )
		? passcount++ : failcount++ ;
	// Test 8
	assert( stat1.upper_case_count == 0 && stat1.lower_case_count == 0 &&
			stat1.digits_count == 0,
		"Expect all three counts to be 0 but got upper %d, lower %d, digits %d",
		stat1.upper_case_count, stat1.lower_case_count, stat1.digits_count )
		? passcount++ : failcount++ ;
	// Test 9 
	assert( stat1.string_copy != BOGUS_POINTER && stat1.string_copy[0] == '\0',
		"Expect string_copy to not be the BOGUS_POINTER and expect it to be an empty string" )
		? passcount++ : failcount++ ;
	// Test 10
	struct statistics stat2 ;
	memset( &stat2, 0xff, sizeof(stat2) ) ;	// fill with bad values
	stat2.string_copy = BOGUS_POINTER ;		// use standard bogus pointer
	char *teststring = "12 aaBbff9" ;
	assert( string_statistics( teststring, &stat2 ) == 1,
		"Expect 1 since both parameters are not NULL" )
		? passcount++ : failcount++ ;
	// Test 11
	assert( stat2.upper_case_count == 1 && stat2.lower_case_count == 5 &&
			stat2.digits_count == 3,
		"Expect upper 1, lower 5, digits 3 but got upper %d, lower %d, digits %d",
		stat2.upper_case_count, stat2.lower_case_count, stat2.digits_count )
		? passcount++ : failcount++ ;
	// Test 12
	if ( stat2.string_copy == BOGUS_POINTER )
	{
		assert( 0,
			 "Skipping Test 12 because string_copy is a BOGUS_POINTER" ) ;
		failcount++ ;
	}
	else
		assert( stat2.string_copy != BOGUS_POINTER && strcmp( stat2.string_copy, teststring ) == 0,
		"Expect string_copy to not be the BOGUS_POINTER and expect it to be \"%s\" but got \"%s\"",
			teststring, stat2.string_copy )
		? passcount++ : failcount++ ;

	printf( "\nTests for add_odd_integers...........................\n" ) ;
	// Test 13
	int result = 0 ;
	result = add_odd_integers( NULL, 5 ) ;
	assert( result == BAD_PARAMETERS,
		"Expect BAD_PARAMETERS because p_integers is NULL but got %d", result )
		? passcount++ : failcount++ ;
	// Test 14
	int array1[] = { 0, 1 } ;
	result = add_odd_integers( array1, 0 ) ;
	assert( result == BAD_PARAMETERS,
		"Expect BAD_PARAMETERS because number of integers is 0 but got %d", result )
		? passcount++ : failcount++ ;
	// Test 15
	result = add_odd_integers( array1, -1 ) ;
	assert( result == BAD_PARAMETERS,
		"Expect BAD_PARAMETERS because number of integers is -1 but got %d", result )
		? passcount++ : failcount++ ;
	// Test 16
	result = add_odd_integers( array1, 2 ) ;
	assert( result == 1,
		"Expect 1 because there is one odd integer with the value 1 but got %d", result )
		? passcount++ : failcount++ ;
	// Test 17
	int array2[] = { 3, 8, 6, -1, 44, 99 } ;
	result = add_odd_integers( array2, 6 ) ;
	assert( result == 101,
		"Expect 101 because 3 - 1 + 99 is 101 but got %d", result )
		? passcount++ : failcount++ ;

	printf( "\nTests for fix_bad_code...............................\n" ) ;
	// Test 18
	result = fix_bad_code( NULL ) ;
	assert( result == 0,
		"Expect 0 because string pointer is NULL but got %d", result )
		? passcount++ : failcount++ ;
	// Test 19
	char *string1 = "" ;	// test for an empty string
	result = fix_bad_code( string1 ) ;
	assert( result == 0,
		"Expect 0 because string is an empty string but got %d", result )
		? passcount++ : failcount++ ;
	// Test 20
	char string2[] = "exchange" ;	// now test for an actual swap
	result = fix_bad_code( string2 ) ;
	assert( result == 1,
		"Expect 1 because string is a valid string but got %d", result )
		? passcount++ : failcount++ ;
	// Test 21
	assert( strcmp( string2, "exhcange" ) == 0,
		"Expect updated string to be \"exhcange\" but got \"%s\"", string2 )
		? passcount++ : failcount++ ;

	// NOTE -- if this is crashing it is because of an error in your implementation
	//         of create_copy. If you cannot figure out what to do change
	//         your code to always return NULL.
	if ( all )
	{
		printf( "\nNow freeing pointers created during prior unit tests\n" ) ;

		if ( good_pointer )
		{
			free( ptest3 ) ;	// free valid malloc from Test 3
			printf( "\nfirst free successful:  %d tests passed  %d tests failed", ++passcount, failcount ) ;
		}
		if ( stat1.string_copy != BOGUS_POINTER )
		{
			free( stat1.string_copy ) ;
			printf( "\nsecond free successful: %d tests passed  %d tests failed", ++passcount, failcount ) ;
		}
		if ( stat2.string_copy != BOGUS_POINTER )
		{
			free( stat2.string_copy ) ;
			printf( "\nthird free successful:  %d tests passed  %d tests failed", ++passcount, failcount ) ;
		}
	}
	else
		printf( "\nSKIPPING free unit tests\n" ) ;

	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
