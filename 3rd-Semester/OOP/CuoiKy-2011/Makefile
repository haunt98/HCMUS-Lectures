CC = clang++
CFLAGS = -Wall -Wextra -g
SRCS = main.cpp MayLoc.cpp
TAG = ctags

all:
	$(CC) $(CFLAGS) $(SRCS) -o program.out

tag:
	$(TAG) .

mem:
	valgrind --leak-check=yes ./program.out

clean:
	rm -f *.out *.o

run:
	./program.out
