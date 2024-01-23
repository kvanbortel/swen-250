/**
 * Display a table of farhrenheit to celsius conversion in increments of 20
 * using floating point and right-justification
 */

#include <stdio.h>

int main()
{
	printf("Fahrenheit-Celsius");

	for (int i=0; i<=300; i+=20) {
		float celsius = (i - 32) * (5.0f / 9.0f);
		printf("\n%7d%9.1f", i, celsius);
	}
	printf("\n");

	return 0;
}
