CLANG_CL = clang-cl
CFLAGS = -Wall -Wextra
SRCS = main.cpp

all:
	$(CLANG_CL) $(CFLAGS) $(SRCS) -o program.exe

clean:
	del /F *.exe *.o

mem:
	drmemory.exe program.exe

run:
	program.exe