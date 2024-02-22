// C (no pointers) Practice Practicum
// SWEN-250
// Larry Kiser October 30, 2015

// cpractice1 struct typedef
typedef struct
{
	int count ;				// the number of characters in the string
							// (not including the end of string)
	char first_character ;	// the first character in the string.
} mydata ;

// cpractice1 functions
int find_char_in_array( char mystring[], char find_this_character ) ;
int fix_bad_code( int first, int second ) ;
void add_string_to_end( char target_string[], char source_string[] ) ;
mydata get_string_info( char mystring[] ) ;
