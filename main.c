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
    userInterface();
    return 0;
}

/*
 * This method handles the interaction between the user and the terminal. The user has an array of options such as reading
 * writing a file, search, hire or even fire employees.
 */
void userInterface(){
    printf("In the userInterface method\n");
    int userInput;
    printf("Type a number to choose \n \n 1) Read a file \n 2) Write a file \n 3) Search Employee \n 4) Hire Employee \n");

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
}

/*
 * Reads a file, the file must exist for it to work. Solve this issue later.
 */
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
    nextStateNoTreeOption();
}

/*
 * Writes a file
 */
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
    nextStateNoTreeOption();
}

/*
 * Searches for an employee.
 */
void searchEmployee(){
    printf("In the searchEmployee method \n");
    userInterface();
}

void insertEmployee() {
    printf("In the insertEmployee method \n");
    double result; // to obtain the height of the tree
    node *root = NULL;
    FILE *file = fopen("ListOfEmployees.txt", "r");
    int numberOfLines = countNumberOfLinesInATextFile(file);
    printf("\n %s %d %s", "number of lines: ", numberOfLines, "\n");
    char line[numberOfLines][256];
    if (file) {
        printf("\n**** BEGIN READING EMPLOYEES FROM TEXT FILE**** \n");
        root = newNode(0);
        int i=0;
        while (fgets(line[i], sizeof(line), file) != 0) {
            //note that fgets don't strip the terminating \n, checking its presence would allow to handle lines longer
            // that sizeof(line)
            insert(root, line[i]);
            i++;
        }
        fclose(file);
        printf("**** END READING EMPLOYEES FROM TEXT FILE **** \n \n");
        result = log(numberOfLines+1)/log(2);
        printTree(root, result); // pass the root and the height
      //  printTree(root, result); // pass the root and the height
        nextState(root);
    }
}

void deleteEmployee(node* root){
    printf("In the deleteEmployee method \n");
    getchar();
    char userInput[256]; // Length 256
    printf("Firing someone is not an easy task to do. Please type in the first name and last name:\n");
    fgets(userInput, 256, stdin);
    deleteNode(root, userInput);
    printTree(root, 3); // pass the root and the height
    nextState(root);
}


void nextStateNoTreeOption(){
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
void nextState(node *root){
    int userInput;
     printf("Type a number to choose \n 1) Quit \n 2) Continue \n 3) Delete employee \n");
    scanf("%d", &userInput);
    if(userInput == 1){
        printf("Have a great day!\n");
    }
    if(userInput == 2){
        userInterface();
    }
    if(userInput == 3) {
        deleteEmployee(root);
    }
}
int countNumberOfLinesInATextFile(char* filename){
    printf("In the readFile method \n");

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
