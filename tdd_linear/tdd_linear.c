// TDD Linear equation activity
// Larry L. Kiser April l8, 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>


static int test_number = 1 ;	// hide this from outside world

// reset test number function to allow independent sets of unit tests.
void reset_test_counter( void )
{
	test_number = 1 ;
}


// Simple boolean assert function for unit testing
// DO NOT MODIFY THIS FUNCTION
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
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

// Linear equation -- create an array of y values for y = m * x + b
// Returns a malloc'ed integer array that has exactly the same number of
// integer values as the x array based on the passed count of entries in
// the x array.
//
// Returns NULL if the x pointer is NULL.
// Returns NULL if the count parameter is <= 0.
// The m and b integer parameters can be any valid integer value.
//
// Submit to the tdd_linear directory in your GitLab repo.
// NOTE -- you are required to use a work pointer that is a copy
//    of the int *x that is passed to this function.
int *linear( int *x, int count, int m, int b )
{
	if (!x || count <= 0)
		return NULL;
	
	int *y = (int *)malloc(sizeof(int) * count);
	int *x_work = x;
	int *y_work = y;
	int i;
	for (i = 0; i < count; i++, y_work++, x_work++)
	{
		*y_work = *x_work * m + b;
	}

	return y;
}

// create unit tests in the correct order by checking for valid
// parameters for all of the cases mentioned in the description.
// Then create tests to create a valid y array for these cases:
// x is an array of just 1 integer with m = 2 and b = 0
// Verify that the y array has one value that is 2 times the x value.
// free the y array
// x is an array of two integers with m = 4 and b = 2
// Verify that both y values are correct.
// do not free this second y array. Instead use valgrind to
// verify that the memory leak is exactly the right size.
// Example code for a test for a valid array:
//    int test1[] = { 10, 20 } ;
//    int *test1_y = linear( test1, sizeof(test1) / sizeof(int), 4, 2 ) ;
int unit_tests()
{
	int passcount = 0;	// default to failure (returns number of tests that passed)
	int failcount = 0;
	int x1[] = {1};
	int x2[] = {1, 2};

	// write test to verify that it returns a NULL pointer when the x pointer is NULL
	int *p_work = linear(NULL, 1, 5, 10);
	assert(p_work == NULL, "input x pointer is NULL but did not get a null pointer response") // don't try to print out an unknown pointer
		? passcount++ : failcount++;
	free(p_work);

	// insert a test for count > 0 before doing this next test!
	// verify that it returns a NULL pointer when the count is <= 0
	p_work = linear(x2, -1, 5, 10);
	assert(p_work == NULL, "count is <= 0 but did not get a null pointer response")
		? passcount++ : failcount++;
	free(p_work);

	// verify a null pointer isn't returned when x is valid
	p_work = linear(x2, sizeof(x2) / sizeof(int), 5, 10);
	assert(p_work != NULL, "input x pointer is valid but got a null pointer response")
		? passcount++ : failcount++;
	free(p_work);

	// verify a null pointer isn't returned when count is valid
	p_work = linear(x2, sizeof(x2) / sizeof(int), 5, 10);
	assert(p_work != NULL, "count is valid but got a null pointer response")
		? passcount++ : failcount++;
	free(p_work);

	// x array has one integer, m = 2, b = 0
	p_work = linear(x1, sizeof(x1) / sizeof(int), 2, 0);
	int expected1[] = {2};
	if (p_work < (int *)1000)	// avoid bogus pointer value crashes
	{
		// force the assert to fail to report a bad pointer
		assert( 0,
			"Bad pointer!")
			? passcount++ : failcount++ ;
	}
	else
	assert(memcmp(p_work, expected1, sizeof(expected1)) == 0, "expected array {2} but pointer was {%d}", *p_work)
		? passcount++ : failcount++;
	free(p_work);

	// x array has two integers, m = 4, b = 2
	p_work = linear(x2, sizeof(x2) / sizeof(int), 4, 2);
	int expected2[] = {6, 10};
	if (p_work < (int *)1000)	// avoid bogus pointer value crashes
	{
		// force the assert to fail to report a bad pointer
		assert( 0,
			"Bad pointer!")
			? passcount++ : failcount++ ;
	}
	else
	assert(memcmp(p_work, expected2, sizeof(expected2)) == 0, "expected array {6, 10} but pointer was {%d, %d}", p_work[0], p_work[1])
		? passcount++ : failcount++;
	// as per directions, not doing: free(p_work);



	printf("Passed: %d, Failed: %d\n", passcount, failcount);

	return failcount;	// return number of tests that failed
}

int main( int arg_count, char *args[] )
{
	return unit_tests() ;
}
