output: main.o binarySearchTree.o
	cc main.o binarySearchTree.o -o output

main.o: main.c
	cc -c main.c

clean:
	rm -f *.o output