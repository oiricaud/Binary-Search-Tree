#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "bstHeader.h"
#include <math.h>

FILE *fptr;
char buffer[32];
char *b = buffer;
size_t bufsize = 32;
size_t characters;

int input(char *s,int length);

int main(void) {
    printf("\n|***** Welcome to Electric Fetus Music Store! ******|\n");
    userInterface();
    return 0;
}

/*
 * This method handles the interaction between the user and the terminal. The user has an array of options such as reading
 * writing a file, search, hire or even fire employees.
 */
void userInterface(){
    int userInput;
    printf("Type a number to choose \n "
                   "1) Read a file \n 2) Write inside the text file \n 3) Create a BST from the text file \n 4) Quit\n");
    printf(">> ");
    scanf("%d", &userInput);
    if(userInput == 1){
     readFile();
    }
    else if(userInput == 2){
        writeFile();
    }
    else if(userInput == 3){
        createBST();
    }
    else if(userInput == 4){
        printf("|***** Thank you very much for using our Service ******|\n");
        return;
    }
}

/*
 * Reads a file, the file must exist for it to work. Solve this issue later.
 */
void readFile(){
    FILE *file;
    int c;
    file = fopen("ListOfEmployees.txt", "r");
        if (file) {
            printf("\n**** READING TEXT FILE **** \n");
            while ((c = getc(file)) != EOF)
                putchar(c);
                printf("\n");
            fclose(file);
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
        printTree(root, result); // pass the root and the height
        nextState(root); // Ask the user if they want to fire an employee
    }
    userInterface();
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
        deleteNode(root, userInput); // Delete node from the binary search tree
        deleteEverythingFromTextFile(root); // Clear everything from the text file
        writeFromBSTTotextFile(root); // Write the new structure of the tree to the text file
        printTree(root, result); // Print the tree with the log(number of employees)
    }
    userInterface();
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
int countNumberOfLinesInATextFile(char* filename){
    FILE *file;
    int c;
    file = fopen("ListOfEmployees.txt", "r");
    int counter = 0;
    if (file) {
        printf("\n**** BEGIN COUNTER IN TEXT FILE **** \n");
        while ((c = getc(file)) != EOF)
            if (c == '\n')
                counter++;
        fclose(file);
        printf("**** END COUNTER IN TEXT FILE **** \n \n");
        return counter;
    }
    return -1;
}
