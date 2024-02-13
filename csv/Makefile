# Makefile for csv activity
# Kayla Van Bortel, RIT, 02/12/2024


all: csv test check

csv: csv.c
	gcc -o csv -g -Wall csv.c unit_tests.c

test: unit_tests.c
	gcc -o test -g -Wall csv.c unit_tests.c

check: test
	./test

clean:
	rm csv test
