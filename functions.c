#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

FILE *fptr;
char buffer[32];
char *b = buffer;
size_t bufsize = 32;
size_t characters;

/*
 * Reads a file, the file must exist for it to work. Solve this issue later.
 */
void readFile(){
    int c;
    fptr = fopen("ListOfEmployees.txt", "r");
    if (fptr) {
        printf("\n**** READING TEXT FILE **** \n");
        while ((c = getc(fptr)) != EOF)
            putchar(c);
        printf("\n");
        fclose(fptr);
        printf("**** DONE READING TEXT FILE **** \n");
    }
    userInterface();
}

/*
 * Takes input from the user and inserts the first name and last name of an employee into the ListOfEmployees.txt file
 */
void writeFile(){
    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
    }
    else {
        printf("\n**** BEGIN WRITING IN A TEXT FILE **** \n");
        getchar();
        printf("Type first and last name: \n");
        characters = getline(&b, &bufsize, stdin);
        printf("\n");
        printf("**** END WRITING IN A TEXT FILE **** \n \n");
        const char *text = buffer;
        fprintf(fptr, "%s", text);
        fclose(fptr);
    }
    userInterface();
}
int countNumberOfLinesInATextFile(char* filename){
    int c;
    fptr = fopen("ListOfEmployees.txt", "r");
    int counter = 0;
    if (fptr) {
        printf("\n**** BEGIN COUNTER IN TEXT FILE **** \n");
        while ((c = getc(fptr)) != EOF)
            if (c == '\n')
                counter++;
        fclose(fptr);
        printf("**** END COUNTER IN TEXT FILE **** \n \n");
        return counter;
    }
    return -1;
}
void createBST() {
    node *root = NULL;
    FILE *file = fopen("ListOfEmployees.txt", "r");
    int numberOfLines = countNumberOfLinesInATextFile(file);
    printf("\n %s %d %s", "number of lines: ", numberOfLines, "\n");
    char line[numberOfLines][256];
    if (file) {
        printf("\n**** BEGIN CREATING BST FROM THE TEXT FILE**** \n");
        root = newNode(0);
        int i=0;
        while (fgets(line[i], sizeof(line), file) != 0) {
            //note that fgets don't strip the terminating \n, checking its presence would allow to handle lines longer
            // that sizeof(line)
            insert(root, line[i]);
            i++;
        }
        fclose(file);
        printf("**** END CREATING BST FROM TEXT FILE **** \n \n");
        result = log(numberOfLines+1)/log(2);
        printTree(root, 1); // pass the root and the height
        nextState(root); // Ask the user if they want to fire an employee
    }
}

void deleteEmployee(node* root){
    getchar();
    char userInput[256];
    int whatToDoNext;

    printf("Firing someone is not an easy task to do. Please type in the first name and last name:\n");
    fgets(userInput, 256, stdin);

    printf("%s %s %s", "Are you sure you want to fire:", userInput, "1) Yes \n 2) No \n");

    scanf("%d", &whatToDoNext);
    if(whatToDoNext == 1){
        deleteNode(root, userInput);            // Delete node from the binary search tree
        clearTextFile(root);                    // Clear everything from the text file
        addUpdatedEmployees(root);              // Write the new structure of the tree to the text file
        printTree(root, result);                // Print the tree passing the height of log(number of employees)
    }
    else
        printf("%s %s\n", "Yeah I don't think it is a good idea to fire", userInput);
    userInterface();                        // Go Back to the starting state
}

void nextState(node *root){
    int userInput;
    printf("Type a number to choose \n 1) Fire employee \n 2) Quit\n");
    scanf("%d", &userInput);
    if(userInput == 1){
        deleteEmployee(root);
    }
    if(userInput == 2) {
        printf("Have a great day!\n");
    }
}
/*
 * Create an empty file for output operations. If a file with the same name already exists,
 * its contents are discarded and the file is treated as a new empty file. [3]
 */
void clearTextFile(){
    fclose(fopen("ListOfEmployees.txt", "w"));
}

void addUpdatedEmployees(node *root){
    int i;

    if(root){
        addUpdatedEmployees(root->leftChild);
        char *employee = root->data;
        printf("%s\n", employee);
        writeUpdatedEmployeesInTextFile(employee);
        addUpdatedEmployees(root->rightChild);
    }
}

/*
 * When we delete an employee from the binary search tree we must also update the text file.
 * This method handles that [4].
 */
void writeUpdatedEmployeesInTextFile(char *employee){
    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
    }
    else {
        fputs(employee, fptr);
        fclose(fptr);
    }
}


/*
 * We must allocate memory for a new node and fill it's data with the proper value.
 */
node *newNode(char *data){
    /* Malloc allocates space for an array of elements,
     * initialize them to zero and then return a void
     * pointer to the memory [2].
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

/**
 * This method inserts data to the Binary Search Tree [1]
 * @param root a new node on the tree if the data is not already stored
 * @param data the data we are trying to insert to the tree
 * @return 0 for error and 1 for success
 */

node *insert(node* root, char* data){
    // If the root data < 1. Means our tree is empty
    if(!root->data){
        root->data = data;
    }
    else{
        int compare;
        compare = strcmp(data, root->data);

        if(compare == 0) {
            printf("We already have that employee in our system\n");
        }
        // data > root->data ex. New employee is greater than the root, store left subtree.
        else if (compare > 0){
            if(root->leftChild) {  // Check if you have a left child already, if so keep recursively, comparing
                                    // and traversing.
                return insert(root-> leftChild, data);
            }
            else {// Create a new child
                root-> leftChild = newNode(data);
            }
        }
        else{
            if(root->rightChild) {
                return insert(root->rightChild, data);
            }
            else {
                root->rightChild = newNode(data);
            }
        }
    }
    return root;
}

/**
 * This method only executes if the tree has a left subtree & the root is being deleted
 * After it visits the root's left child it verifies if the root's left child has a right child a swapping occurs
 * between the root and the root's left child, right child.
 * a swapping occurs
 * @param
 * @return
 * */
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
/**
 * This method deletes an employee from the tree [2].
 * @param root is the root of the tree
 * @param data is the employee we are terminating from the company
 * @return
 */
node *deleteNode(node* root, char* data){
    node *temp = NULL;

    if(root == NULL) {
        return root;
    }

    int result;
    result = strcmp(root->data, data);

    // If the result is negative it means the root Employee is less than the Employee
    // Therefore we must traverse the left-subtree
    if(result < 0) {
        root->leftChild = deleteNode(root->leftChild, data);
    }
        // If the result is positive we must search for the employee the right-subtree
    else if(result > 0){
        root->rightChild = deleteNode(root->rightChild, data);
    }

        // Else we find the node
    else{
        // If both the subtrees, left & right are empty free the root
        if(root->leftChild == NULL && root->rightChild == NULL){
            free(root);
            return NULL;
        }
            // If the left subtree has no children, destroy the root node and return the right node
        else if(root->leftChild == NULL){
            temp = root->rightChild;
            free(root);
            return temp;
        }
            // If the right root is empty, destroy the root node and return the left node
        else if(root->rightChild == NULL){
            temp = root->leftChild;
            free(root);
            return temp;
        }
        // We must find the maximum value from the left subtree and store it to the temp
        temp = maxNode(root->leftChild);
        root->data = temp->data;
        root->leftChild = deleteNode(root->leftChild, temp->data);
    }
    // returns the new tree
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
            printf("             ├──  ");
        printf("%s\n", root->data);
        printTree(root->rightChild, height+1);
    }
}


