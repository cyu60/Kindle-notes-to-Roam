CC = g++
#CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

run: clippings.exe
	./clippings.exe

# create executable
clippings.exe: clippings.cpp 
	$(CC) clippings.cpp -o clippings

# create object file for testing linked list functions
#test.o: list_test.c list.h
#	$(CC) -c list_test.c

# clean up
clean:
	rm -f *~ *.exe test
