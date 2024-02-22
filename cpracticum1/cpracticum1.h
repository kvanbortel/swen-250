// C (no pointers) Practicum
// SWEN-250
// Larry Kiser Feb. 13, 2018
//             New first no pointers practicum without structs
// Larry Kiser Sept. 27, 2022 updated
// Larry Kiser Feb. 22, 2024 added struct function

// struct defintion
typedef struct
{
	int num_letters ;	// number of letters in a string ('a' through 'z' and 'A' through 'Z')
	int num_digits ;	// number of digits ('0' through '9')
} char_counts_t ;

// cpracticum1 functions
int fix_bad_code( char mystring[], char find_this ) ;
int swap_first_and_last( char mystring[] ) ;
void update_digits( char mystring[] ) ;
char range_test( int value, int lower_limit, int upper_limit ) ;
char_counts_t get_counts( char mystring[] ) ;
