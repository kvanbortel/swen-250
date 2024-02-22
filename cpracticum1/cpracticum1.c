// C (no pointers) Practicum
// SWEN-250
// Larry Kiser Feb. 13, 2018
//             New no pointers practicum without structs
// Revised Feb. 28, 2021 for 250-01 term 2205
// Revised Feb. 15, 2021 for 250-04 term 2215
// Larry Kiser Sept. 27, 2022 updated


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "cpracticum1.h"
#include "unit_tests.h"



// This function is implemented incorrectly. You need to correct it.
// It is supposed to count the number of times that the find_this character
// is present in the passed string. It returns this integer count.
// Example: "" searching for 'c' returns 0.      // (empty strings always return a 0)
// Example: "abcdef" searching for 'c' returns 1.
// Example: "abcdef" searching for 'g' returns 0.
// Example: "aaxxxa" searching for 'a' returns 3.
// NOTE -- you are required to correct this code. You are not allowed to completely rewrite it.
//         There are several errors in this routine. You must fix all errors. It is possible that the
//         unit tests may pass without all errors being corrected. Make sure that your corrected
//         code does not produce any warnings.
int fix_bad_code( char mystring[], char find_this )
{
	int i = 0 ;
	int result = 0 ;
	
	for ( ; mystring[i] != '\0' ; i++ )
    {
		if ( mystring[i] == find_this )
			result++ ;
    }

	return result ;
} 


// This function swaps the first character and the last character in
// the passed string. Only do this swap if the passed string has two
// or more characters.
// Example: "First" becomes "tirsF")
// The F was the first character and is now the last.
// The t was the last character and is now the first.
//
// Return 1 if the first and last were swapped.
// Return 0 if the passed string is an empty string.
// Return 0 if the passed string only has one character.
//
// You are allowed to use the strlen library function. 
int swap_first_and_last( char mystring[] )
{
    if (mystring[0] == '\0' || mystring[1] == '\0')
        return 0;

    int temp;
    int n = strlen(mystring);

    temp = mystring[0];
	mystring[0] = mystring[n - 1];
	mystring[n - 1] = temp;

	return 1 ;		// fix this -- incorrect value to allow the code to compile without warnings.
}

// For the passed string you must change every character that is an ASCII digit in the passed string.
// If the digit is '0' through '8' you must add one ('0' becomes '1', '8' become '9').
// If the digit is '9' you must change it to a '0'. 
// Do not change make any other changes to the array.
// For example a string "ab192 C0" would become "ab203 C1".
//
// The string may be an empty string. If it is empty do nothing.
// Note that this means you are directly changing the characters in the passed string.
// Hint -- you may want to use the isdigit function to make your code easier.
void update_digits( char mystring[] )
{
    int i;
    int j;
    for (i = 0; mystring[i] != '\0'; i++)
    {
        if (mystring[i] == 57)
            mystring[i] = 48;
    
        else
        {
            for (j = 48; j < 57; j++)
            {
                if (mystring[i] == j)
                    mystring[i] = ++j;
            }
        }
    }
}



// Copy of the typedef struct from cpracticum1.h for your convenience.
// struct defintion
// typedef struct
// {
//    int num_letters ;   // number of letters in a string ('a' through 'z' and 'A' through 'Z')
//    int num_digits ;    // number of digits ('0' through '9')
// } char_counts_t ;
//
// Count the number of digits in the passed string ('0' through '9' ) and
// count the number of lettes in the passed string ('a' through 'z' and 'A' through 'Z' )
// and store those counts in the char_counts_t typedef struct.
// Return that struct from this get_counts function.
char_counts_t get_counts( char mystring[] )
{
    // add your code here. Refer to the above copy of the struct definition.
	char_counts_t my_counts ;

    my_counts.num_letters = 0;
    my_counts.num_digits = 0;

    int i;
    for (i = 0; mystring[i] != '\0'; i++)
    {
        if (isalpha(mystring[i]))
            my_counts.num_letters++;
        else if (isdigit(mystring[i]))
            my_counts.num_digits++;
    }
    
	return my_counts ;
}



// Only runs the unit tests.
int main( int argc, char *argv[] ) {

	// Execute unit tests
	return test() ;
}

