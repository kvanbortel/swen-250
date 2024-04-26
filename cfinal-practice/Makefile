EADERS = cfinal.h unit_tests.h

default: test

test:	main.o cfinal.o unit_tests.o
	gcc -g -o test main.o cfinal.o unit_tests.o
	
cfinal.o: cfinal.c $(HEADERS)
	gcc -Wall -g -c cfinal.c

main.o: main.c $(HEADERS)
	gcc -Wall -g -c main.c
	
unit_tests.o: unit_tests.c $(HEADERS)
	gcc -Wall -g -c unit_tests.c

clean:
	-rm -f cfinal.o
	-rm -f main.o
	-rm -f unit_tests.o
	-rm -f test
	
