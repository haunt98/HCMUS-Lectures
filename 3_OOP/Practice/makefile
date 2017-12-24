CC = g++
CROSS = i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -Wfatal-errors -static
SRCS = virtual.cpp 
TAG = ctags

all:
	$(CROSS) $(CFLAGS) $(SRCS)

tag:
	$(TAG) .
