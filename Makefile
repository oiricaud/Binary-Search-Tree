program: main.o
	gcc -o program main.o

main.o: main.c main.h bstHeader.h
	gcc -c main.c

clean:
	rm -f *.o output