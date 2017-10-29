CC = g++
CROSS = i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -static
SRCS = main.cpp Animal.cpp
TAG = ctags

all:
	$(CROSS) $(CFLAGS) $(SRCS)

tag:
	$(TAG) .
