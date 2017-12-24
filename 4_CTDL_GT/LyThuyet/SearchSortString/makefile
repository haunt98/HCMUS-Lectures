CC = i686-w64-mingw32-g++
CFLAGS = -Wall -Wextra -Wfatal-errors -static
SRCS = main.cpp random.cpp
SRCS_FIND = search.cpp 
SRCS_SORT = sort_lo.cpp sort_hi.cpp sort_ha.cpp sort_ha_mod.cpp
SRCS_STR = strmatch.cpp 
TAG = ctags
all:
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_FIND) $(SRCS_SORT) $(SRCS_STR)

tag:
	$(TAG) .
