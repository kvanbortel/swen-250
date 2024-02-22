// unit_tests.c
// Larry Kiser October 30, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "cpractice1.h"
#include "unit_tests.h"

// used by stdout switching functions
static int stdout_file_descriptor = 0 ;
static fpos_t stdout_position ;

// Redirect printf's to the specified text file (redirect stdout).
static void switch_stdout_to_file( char *filename )
{
	fflush( stdout ) ;
	fgetpos( stdout, &stdout_position ) ;
	stdout_file_descriptor = dup( fileno( stdout ) ) ;
	freopen( filename, "w", stdout ) ;
}

// Restore normal printf behavior (restore stdout).
// MUST be called only after a prior call to switch_stdout_to_file!
static void restore_stdout( void )
{
	if ( stdout_file_descriptor )
	{
		fflush( stdout ) ;
		dup2( stdout_file_descriptor, fileno( stdout ) ) ;
		close( stdout_file_descriptor ) ;
		clearerr( stdout ) ;
		fsetpos( stdout, &stdout_position ) ;
	}
}

// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	// bogus code that does nothing except avoid compiler warning on these two unused functions.
	#pragma GCC diagnostic ignored "-Waddress"
	if ( switch_stdout_to_file && restore_stdout ) ;
	#pragma GCC diagnostic warning "-Waddress"
	
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
int test()
{
	int passcount = 0 ;
	int failcount = 0 ;
	char test81target[10] = "abc" ;
	char test81source[] = "def" ;
	char test82target[10] = "" ;
	
	
	// Test 1 -- 
	assert( find_char_in_array( "findinstring", 'n' ) == 2,
		"Expected to find n in index position 2" )
		? passcount++ : failcount++ ;
		
	// Test 2 -- 
	assert( find_char_in_array( "findinstring", 'g' ) == 11,
		"Expected to find g in index position 11" )
		? passcount++ : failcount++ ;
		
	// Test 3 -- 
	assert( find_char_in_array( "findinstring", 'x' ) == -1,
		"Expected -1 because x is not in the string" )
		? passcount++ : failcount++ ;
		
	// Test 4 -- 
	assert( find_char_in_array( "", 'x' ) == -1,
		"Expected -1 because the passed in string is an empty string (just an EOF or null character)" )
		? passcount++ : failcount++ ;
		
	// Test 5 -- 
	assert( fix_bad_code( 5, 5 ) == 0,
		"Expected 0 for two equal values" )
		? passcount++ : failcount++ ;
		
	// Test 6 -- 
	assert( fix_bad_code( 6, 5 ) == 1,
		"Expected 1 because 6 > 5" )
		? passcount++ : failcount++ ;
		
	// Test 7 -- 
	assert( fix_bad_code( 3, 5 ) == -1,
		"Expected -1 because 3 is < 5" )
		? passcount++ : failcount++ ;
		
	// Test 8 -- 
	add_string_to_end( test81target, "" ) ;
	assert( strcmp( test81target, "abc" ) == 0,
		"Expected source string to now be abc but got %s", test81target )
		? passcount++ : failcount++ ;
		
	// Test 9 -- 
	add_string_to_end( test82target, test81source ) ;
	assert( strcmp( test82target, "def" ) == 0,
		"Expected source string to now be def but got %s", test82target )
		? passcount++ : failcount++ ;
		
	// Test 10 -- 
	add_string_to_end( test81target, test81source ) ;
	assert( strcmp( test81target, "abcdef" ) == 0,
		"Expected source string to now be abcdef but got %s", test81target )
		? passcount++ : failcount++ ;
		
	// Test 11 -- 
	mydata data = get_string_info( "" ) ;
	assert( data.count == -1,
		"Expected -1 for the count" )
		? passcount++ : failcount++ ;
		
	// Test 12 -- 
	assert( data.first_character == '\0',
		"Expected end of string for the first_character" )
		? passcount++ : failcount++ ;
		
	// Test 13 -- 
	data = get_string_info( "12345" ) ;
	assert( data.count == 5,
		"Expected 5 for the count. Got %d ", data.count )
		? passcount++ : failcount++ ;
		
	// Test 14 -- 
	assert( data.first_character == '1',
		"Expected 1 for the first_character" )
		? passcount++ : failcount++ ;
		

	
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}