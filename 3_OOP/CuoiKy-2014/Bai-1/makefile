GCC = g++
MINGW_GCC = i686-w64-mingw32-g++
CLANG = clang++
MINGW_CLANG = i686-w64-mingw32-clang++
CLANG_CL = clang-cl
CFLAGS = -Wall -Wextra
SRCS = main.cpp bike.cpp
TAG = ctags

all:
	$(CLANG_CL) $(CFLAGS) $(SRCS) -o prog.exe

tag:
	$(TAG) .

clean:
	del /F *.exe *.o

mem:
	drmemory.exe prog.exe

run:
	prog.exe