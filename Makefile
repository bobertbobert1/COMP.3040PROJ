CC = g++
CFLGS = -c -g -Og -Wall -Werror -ansi -pedantic

all: main.o Char.o Alpha.o Str.o DFA.o
	$(CC) main.o char.o alpha.o str.o -o 3040
	
main.o: main.cpp
	$(CC) $(CFLGS) -o main.o main.cpp
	
char.o: Char.cpp Char.hpp
	$(CC) $(CFLGS) -o char.o Char.cpp Char.hpp

alpha.o: Alpha.cpp Alpha.hpp
	$(CC) $(CFLGS) -o alpha.o Alpha.cpp Alpha.hpp

str.o: Str.cpp Str.hpp
	$(CC) $(CFLGS) -o str.o Str.cpp Str.hpp
	
clean:
	rm main.o alpha.o char.o str.o
	