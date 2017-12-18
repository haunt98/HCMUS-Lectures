CLANG = clang++
CFLAGS = -Wall -Wextra -g
SRCS = main.cpp Market.cpp Sap.cpp
VALGRIND = valgrind --leak-check=yes 

all:
	$(CLANG) $(SRCS) $(CFLAGS) -o output.out

mem:
	$(VALGRIND) ./output.out

clean:
	rm -f *.out *.o

run:
	./output.out
