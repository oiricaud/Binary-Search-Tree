all: main

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

main: main.o
	cc -o $@ $^ -lm

main.o: main.c main.h bstHeader.h
	cc -c $(CFLAGS) main.c

clean:
	rm -f *.o main

demo: main
	./main

