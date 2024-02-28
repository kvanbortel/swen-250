HEADERS = read_data.h

test_pointers:	read_data.o main.o
	gcc -o test_pointers -g read_data.o main.o
	
read_data.o: read_data.c $(HEADERS)
	gcc -g -Wall -c read_data.c

main.o: main.c $(HEADERS)
	gcc -g -Wall -c main.c

clean:
	-rm -f read_data.o main.o test_pointers
