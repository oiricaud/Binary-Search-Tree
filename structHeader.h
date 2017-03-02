#ifndef BINARY_SEARCH_TREE_STRUCTHEADER_H
#define BINARY_SEARCH_TREE_STRUCTHEADER_H


/* Below we define the Binary Search Tree properties */

/* What are properties a node has? Each node must store data and may have a left or right child. */
struct node {
    struct node *leftChild;
    struct node *rightChild;
    int data;
};

/*
 * We must allocate memory for a new node and fill it's data with the proper value.
 */
struct node *newNode(int data){

    /* Calloc allocates space for an array of elements,
     * initialize them to zero and then return a void
     * pointer to the memory
     */
    struct node *n = (struct node*) calloc(1, sizeof(struct node));
    n->leftChild = NULL;
    n->rightChild = NULL;
    n->data = data;
    return n;
}

#endif //BINARY_SEARCH_TREE_STRUCTHEADER_H
