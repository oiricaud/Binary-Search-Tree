#include <stdio.h>
#include <stdlib.h>
#include "structHeader.h"


/**
 *
 * @param root a new node on the tree if the data is not already stored
 * @param data the data we are trying to insert to the tree
 * @return 0 for error and 1 for success
 */
int insert(struct node* root, int data){
    struct node *n;

    if(!root->data){
        printf("If the root is null then insert here \n");
        root->data = data;
    }
    else{
        if(data == root->data) // We can't add duplicates to the binary search tree so just return and ignore.
            return 0;
        else if(data > root->data){ // If data is greater than the root
            if(root->rightChild){  // This statement runs if the root has a right child
                // printf("This statement runs if the root has a right child\n");
                return insert(root->rightChild, data);
            }
            else{ // Create new right child
                root->rightChild = newNode(data);
                // printf("Create a new right child\n");
            }
        }
        else{ // Insert at the left child
            if(root->leftChild){ // This statement runs if the root has a left child
                // printf("This statement runs if the root has a left child");
                return insert(root->leftChild, data);
            }
            else{ // Create a new left child
                root->leftChild = newNode(data);
                //  printf("Create a new left child");
            }
        }
    }
    return 1;
}
void printTree(struct node* root, int height){
    int i;

    if(root){
        printTree(root->leftChild, height+1);
        for(i = 0; i < height; i++) {
            printf("  ");
        }
        printf("%d\n", root->data);
        printTree(root->rightChild, height +1);
    }
}