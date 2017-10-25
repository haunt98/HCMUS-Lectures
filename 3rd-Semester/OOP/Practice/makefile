CC = g++
CROSS = i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -static
SRCS = interface.cpp 
TAG = ctags

all:
	$(CROSS) $(CFLAGS) $(SRCS)

tag:
	$(TAG) .
