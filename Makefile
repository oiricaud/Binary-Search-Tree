output: main.o foo.o binarySearchTree.o
	cc main.o foo.o binarySearchTree.o -o output

main.o: main.c
	cc -c main.c

foo.o: foo.c
	cc -c foo.c

clean:
	rm -f *.o output