// C pointers final Practicum
// SWEN-250
// Larry Kiser December 8, 2021


#define BOGUS_POINTER (char *)1
#define BAD_PARAMETERS (-999999)

// structs
struct statistics
{
	int upper_case_count ;	// number of upper case letters 'A' through 'Z'
	int lower_case_count ;	// number of lower case letters 'a' through 'z'
	int digits_count ;		// number of numeric characters '0' through '9'
	char *string_copy ;		// an optimally sized copy of the passed string created using malloc
} ;


// cfinal functions
char *make_big_string_from_two( char *p_first, char *p_second ) ;
int string_statistics( char *string, struct statistics *p_statistics ) ;
int add_odd_integers( int *p_integers, int number_of_integers ) ;
int fix_bad_code( char *pstring ) ;

