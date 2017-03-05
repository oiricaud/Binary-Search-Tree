all: main

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

main: functions.o main.o
	cc -o $@ $^ -lm

functions.o: functions.c functions.h
	cc -c $(CFLAGS) functions.c

main.o: main.c functions.h
	cc -c $(CFLAGS) main.c



clean:
	rm -f *.o main

demo: main
	./main

