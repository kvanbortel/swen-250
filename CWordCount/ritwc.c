#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main() {
    int tot_chars = 0 ;	/* total characters */
    int tot_lines = 0 ;	/* total lines */
    int tot_words = 0 ;	/* total words */
    int nchar ;         /* new character read in */
    int in_word = 0 ;   /* boolean to control counting words */


    while ((nchar = getchar()) != EOF) {
        tot_chars++; // We loop over a char each time, so add 1 to characters
        
        // Count lines
        // Count words that end with newlines
        if (nchar == '\n') {
            tot_lines++;

            if (in_word)
            tot_words++;

            in_word = 0;
        }

        // Count words that end with spaces
        else if(isspace(nchar)) {
            if (in_word)
            tot_words++;
            
            in_word = 0;
        }

        // Declare that we are in a word
        else
            in_word = 1;
    }

    printf("%3d%4d%4d\n", tot_lines, tot_words, tot_chars);

	return 0 ;
}
