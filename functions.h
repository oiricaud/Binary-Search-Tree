#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* What are properties a node has? Each node must store data and may have a left or right child. */
typedef struct node {
    struct node *leftChild;
    struct node *rightChild;
    char *data;
} node;

/* Create new Node */
struct node *newNode(char *data);

/* Pass the root to this method and it will find the maximum node if the root
 * has a left child and the left child has a right child, a swap occurs
 * between root and the right child. */
struct node *maxNode(node *root);

/* Insert Node */
struct node *insert(node* root, char* data);

/* Delete Node */
 struct node *deleteNode(node* root, char* data);

/* Prints the tree */
void printTree(node* root, int height);

/* Takes input from the user to navigate through the state machine of the system.
 * i.e Read a file, Write inside a text file, Create a BST or Quit */
void userInterface();

/* To obtain the height of the tree */
double result;

/* Takes input from the user to do either of the steps, Fire Employee or Quit */
void nextState(node *root);

/* After binary search tree has been modified we clear the text file before
 * we write the new binary search tree*/
void clearTextFile();

/* We add the new Binary Search Structure here */
void addUpdatedEmployees(node *root);

/* Reads the ListOfEmployees.txt */
void readFile();

/* Writes the ListOfEmployees.txt */
void writeFile();

/* Creates Binary Search Tree based on the ListOfEmployees.txt*/
void createBST();

/* Deletes an Employee. Pass it the root so we can find out what
 * tree structure we are using*/
void deleteEmployee(node* root);

/* Returns the number of lines in the ListOfEmployees.txt*/
int countNumberOfLinesInATextFile(char *filename);

/* This method actually writes into the text file.
 * It gets called called recursively by @addUpdatedEmployees */
void writeUpdatedEmployeesInTextFile(char *employee);

#endif //FUNCTIONS_H
