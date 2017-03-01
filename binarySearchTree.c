#include <stdio.h>
#include <stdlib.h>

/* What are properties a node has? Each node must store data and may have a left or right child. */
struct node {
    struct node *leftChild;
    struct node *rightChild;
    int data;
};



