#ifndef BST_H
#define BST_H


/* What are properties a node has? Each node must store data and may have a left or right child. */
typedef struct node {
    struct node *leftChild;
    struct node *rightChild;
    char *data;
} node;

node *newNode(char *data);
node *deleteNode(node* root, char* data);
void printTree(node* root, int height);
/*
 * We must allocate memory for a new node and fill it's data with the proper value.
 */
node *newNode(char *data){

    /* Calloc allocates space for an array of elements,
     * initialize them to zero and then return a void
     * pointer to the memory
     */
    node *newNode = NULL;
    newNode=malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }

    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

node *maxNode(node *root);
/**
 * This method inserts data to the Binary Search Tree[1]
 * @param root a new node on the tree if the data is not already stored
 * @param data the data we are trying to insert to the tree
 * @return 0 for error and 1 for success
 */

node *insert(node* root, char* data){
    //node *n;
   // printf("%s %s %s %s %s", "root->data: ", root->data, "Data: ", data,"\n");

    if(!root->data){
      //  printf("%s %s %s %s %s %s", "Tree is empty: ", "Root->Data: ", root->data, "Data: ", data, "\n");
        root->data = data;
    }
    else{
      //  printf("%s %s %s %s %s", "HEREroot->data: ", root->data, "Data: ", data,"\n");
        int compare;
        compare = strcmp(data, root->data);
        if(compare == 0) { // If the data is equal to the root then,
        //    printf("%s %s %s %s %s %d %s", "Data: ", data, "Root->Data: ", root->data, "Compare: ", compare, "\n");
        }
        else if (compare < 0){ // data is less than root->data.
         //   printf("%s %s %s %s %s, %s", "data is > root->data|", data, ">", root->data, "compareStrings", "\n");
            if(root->rightChild) {  // This statement runs if the root has a right child
                // printf("This statement runs if the root has a right child\n");
                return insert(root->rightChild, data);
            }
            else {// Create new right child
                root->rightChild = newNode(data);
                // printf("Create a new right child\n");
            }
        }
        else{ // Insert at the left child
        //    printf("%s %s %s %s %s", "data is < root->data|", data, "<", root->data, "\n");
            if(root->leftChild) { // This statement runs if the root has a left child
                // printf("This statement runs if the root has a left child");
                return insert(root->leftChild, data);
            }
            else {// Create a new left child
                root->leftChild = newNode(data);
                //  printf("Create a new left child");
            }
        }
    }
    return root;
}

node *maxNode(node* root){
   if(root == NULL){
       return NULL;
   }
    node *temp = root;
    while(temp->rightChild != NULL){
        temp = temp->rightChild;
    }
    return temp;

}
node *deleteNode(node* root, char* data){
    printf("%s %s\n", "rootdata:", root->data);

    node *temp = NULL;

    if(root == NULL) {
        return root;
    }

    int compare;
    compare = strcmp(root->data, data);

    // Recurse Left
    if(compare < 0) {
        printf("Here 1");
        root->leftChild = deleteNode(root->leftChild, data);
    }
    // Recurse Right
    else if(compare > 0){
        printf("Here 2");
        root->rightChild = deleteNode(root->rightChild, data);
    }

    // else we find the node
    else{
        // If both the subtrees, left & right are empty free the root
        if(root->leftChild == NULL && root->rightChild == NULL){
            free(root);
            printf("Here 3");
            return NULL;
        }
        else if(root->leftChild == NULL){
            temp = root->rightChild;
            free(root);
            printf("Here 4");
            return temp;
        }
        else if(root->rightChild == NULL){
            temp = root->leftChild;
            free(root);
            printf("Here 5");
            return temp;
        }
        temp = maxNode(root->leftChild);
        root->data = temp->data;
        root->leftChild = deleteNode(root->leftChild, temp->data);
    }
    return root;
}
/**
 * This method prints the tree nicely[1]
 * @param root is a pointer type node
 * @param height is the height of the tree.
 */
void printTree(node* root, int height){
    int i;

    if(root){
        printTree(root->leftChild, height+1);
        for(i = 0; i < height; i++)
            printf("  ├──  ");
            printf("%s\n", root->data);
        printTree(root->rightChild, height+1);
    }
}

#endif //BST_H
