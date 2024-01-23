/**
 * Display a table of farhrenheit to celsius conversion in increments of 20
 */

#include <stdio.h>

int main()
{
	printf("Fahrenheit-Celsius");

	for (int i=0; i<=300; i+=20) {
		int celsius = 5 * (i - 32) / 9;
		printf("\n    %-7d%d", i, celsius);
	}
	printf("\n");

	return 0;
}
