program: main.o
	gcc -o program main.o

main.o: main.c binarySearchTree.h
	gcc -c main.c

clean:
	rm -f *.o output