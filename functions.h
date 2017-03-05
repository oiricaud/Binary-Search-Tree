#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* What are properties a node has? Each node must store data and may have a left or right child. */
typedef struct node {
    struct node *leftChild;
    struct node *rightChild;
    char *data;
} node;


// Creates nodes
struct node *newNode(char *data);

struct node *maxNode(node *root);

/* Create functions */

struct node *insert(node* root, char* data);

// Delete Nodes
 struct node *deleteNode(node* root, char* data);

// Prints the tree
void printTree(node* root, int height);



void userInterface();

/* Function Declaration */
double result; // to obtain the height of the tree

void nextState(node *root);

void clearTextFile();

void addUpdatedEmployees(node *root);



void readFile();

void writeFile();

void createBST();

void deleteEmployee(node* root);



int countNumberOfLinesInATextFile(char *filename);


void writeUpdatedEmployeesInTextFile(char *employee);



#endif //FUNCTIONS_H
