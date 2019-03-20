# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: lab3

lab3: star.o planet.o lab3.o
	$(CC) $(CFLAGS) star.o planet.o lab3.o -o lab3

star.o: Star.cpp Star.h Planet.h
	$(CC) $(CFLAGS) -c Star.cpp -o star.o

planet.o: Planet.cpp Planet.h
	$(CC) $(CFLAGS) -c Planet.cpp -o planet.o

lab3.o: lab3.cpp Star.cpp Star.h Planet.cpp Planet.h
	$(CC) $(CFLAGS) -c lab3.cpp -o lab3.o

clean:
	rm *.o lab3

run: lab3
	./lab3

memcheck: lab3
	valgrind ./lab3
