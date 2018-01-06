CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = $(wildcard *.c) 

all:
	$(CC) $(CFLAGS) $(SRCS) -o program.out

mem:
	valgrind --leak-check=yes ./program.out

clean:
	rm -f *.out *.o
