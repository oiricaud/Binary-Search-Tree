#include <stdio.h>
#include <stdlib.h>



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

/**
 *
 * @param root a new node on the tree if the data is not already stored
 * @param data the data we are trying to insert to the tree
 * @return
 */
int insert(struct node* root, int data){
    struct node *n;
    // If the root that points to data is not null
    if(!root->data){
        printf("If the root is null then insert here \n");
        root->data = data;
    }
    else{
        if(data == root->data) // We can't add duplicates to the binary search tree
            return -1;
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
    return 0;
}
void printTree(struct node* root, int height){
    int i;

    if(root){
        printTree(root->leftChild, height+1);
        for(i = 0; i < height; i++)
            printf("  ");
        printf("%d\n", root->data);
        printTree(root->rightChild, height +1);
    }
}




//#include "foo.h"  /* Include the header here, to obtain the function declaration */
void userInterface();
void readFile();
void writeFile();
void searchEmployee();
void insertEmployee();
void deleteEmployee();
void doWeWantToQuit();


FILE *fptr;
char buffer[32];
char *b = buffer;
size_t bufsize = 32;
size_t characters;

int input(char *s,int length);

int main(void) {
    userInterface();
    return 0;
}

void userInterface(){
    printf("In the userInterface method\n");
    int userInput;
    printf("Type a number to choose \n \n 1) Read a file \n 2) Write a file \n 3) Search Employee \n 4) Hire Employee \n"
                   " 5) Fire employee \n");
    scanf("%d", &userInput);
    if(userInput == 1){
     readFile();
    }
    else if(userInput == 2){
        writeFile();
    }
    else if(userInput == 3){
        searchEmployee();
    }
    else if(userInput == 4){
        insertEmployee();
    }
    else if (userInput == 5){
        deleteEmployee();
    }
}


void readFile(){
    printf("In the readFile method \n");

    FILE *file;
    int c;
    file = fopen("ListOfEmployees.txt", "r");
        if (file) {
            printf("\n**** BEGIN READING TEXT FILE **** \n");
            while ((c = getc(file)) != EOF)
                putchar(c);
                printf("\n");
            fclose(file);
            printf("**** END READING TEXT FILE **** \n \n");
        }
    doWeWantToQuit();
}


void writeFile(){
    printf("In the writeFile method \n");

    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
    }
    else {
        printf("\n**** BEGIN WRITING IN A TEXT FILE **** \n");
        getchar();
        printf("Type first and last name: ");
        characters = getline(&b, &bufsize, stdin);
        printf("**** END WRITING IN A TEXT FILE **** \n \n");
        printf("**** SUCCESS **** \n \n");
        const char *text = buffer;
        fprintf(fptr, "%s", text);
    }

    doWeWantToQuit();
}


void searchEmployee(){
    printf("In the searchEmployee method \n");
    userInterface();
}


void insertEmployee(){
    printf("In the insertEmployee method \n");
    printf("In the writeFile method \n");

    fptr = fopen("ListOfEmployeesBTreeStructure.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
    }
    else {
        printf("\n**** Hire Employee **** \n");
        struct node *root = NULL;
        root = newNode(0);
        insert(root, 2);
        insert(root, 3);
        insert(root, 1);
        printTree(root, 1);
    }

    doWeWantToQuit();
}


void deleteEmployee(){
    printf("In the deleteEmployee method \n");
    printf("Firing someone is not an easy task to do. Please type in the first name and last name:\n");
    userInterface();
}


 void doWeWantToQuit(){
    int userInput;
     printf("Type a number to choose \n 1) Quit \n 2) Continue \n");
    scanf("%d", &userInput);
    if(userInput == 1){
        printf("Have a great day!\n");
    }
    if(userInput == 2){
        userInterface();
    }
}
