CC = i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -static
SRCS = main.cpp random.cpp
SRCS_SORT = sort_lo.cpp sort_hi.cpp sort_ha.cpp
TAG = ctags
all:
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_SORT)

tag:
	$(TAG) .
