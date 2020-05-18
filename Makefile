CC = g++
CFLGS = -c -g -Og -Wall -Werror -ansi -pedantic

all:
	$(CC) main.o char.o alpha.o -o 3040
	
main.o: main.cpp
	$(CC) $(CFLGS) -o main.o main.cpp
	
char.o: Char.cpp Char.hpp
    $(CC) $(CFLGS) -o char.o Char.cpp Char.hpp

alpha.o: Alpha.cpp Alpha.hpp
	$(CC) $(CFLGS) -o alpha.o Alpha.cpp Alpha.hpp
	
clean:
	rm main.o alpha.o char.o
	