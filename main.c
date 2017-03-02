#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "bstHeader.h"


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
    struct node *root = NULL;
    char line[10][256];
    FILE *file = fopen("ListOfEmployees.txt", "r");
    if (file) {
        printf("\n**** BEGIN INSERTING EMPLOYEES **** \n");
        root = newNode(0);
        int i=0;
        while (fgets(line[i], sizeof(line), file) != 0) {
            //note that fgets don't strip the terminating \n, checking its
            // presence would allow to handle lines longer that sizeof(line)
            printf("%s %s", "line:", line);
            insert(root, line[i]);
            i++;
        }
        fclose(file);
        printf("**** END INSERTING EMPLOYEES **** \n \n");
        nextState(root);
    }
        /*
        while (fgets(line, sizeof(line), file)  != '\n') {

          //note that fgets don't strip the terminating \n, checking its
         // presence would allow to handle lines longer that sizeof(line)

            printf("%s %s", "line:", line);
            insert(root, line);

        }
        fclose(file);
        printf("**** END INSERTING EMPLOYEES **** \n \n");
        nextState(root);
    }
*/
/*
    insert(root, "Javi");
    insert(root, "Oscar");
    insert(root, "Daniel");
    insert(root, "Gisela");
    nextState(root);
*/


/*
    struct node *root = NULL;
    root = newNode(0);
    FILE *file;
    int c;
    char line[256] ="";

    file = fopen("ListOfEmployees.txt", "r");
    if (file) {

        printf("\n**** BEGIN INSERTING EMPLOYEES **** \n");

        while (fgets(line, sizeof(line), file)  != 0) {
             note that fgets don't strip the terminating \n, checking its
               presence would allow to handle lines longer that sizeof(line)

            insert(root, line);
           // printf("%s %s", "line:", fgets(line, sizeof(line), file));
        }

        fclose(file);
        printf("**** END INSERTING EMPLOYEES **** \n \n");
    }

    insert(root, "Javi");
    insert(root, "Oscar");
    insert(root, "Daniel");
    insert(root, "Gisela");

    nextState(root);


    fptr = fopen("ListOfEmployees.txt", "r");
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
        insert(root, 4);
        insert(root, 0);
        printTree(root, 1);
    }
    printf("\n**** End Hire Employee **** \n");
    nextState();
     */

}

void deleteEmployee(){
    printf("In the deleteEmployee method \n");
    printf("Firing someone is not an easy task to do. Please type in the first name and last name:\n");
    userInterface();
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
void nextState(struct node *root){
    int userInput;
     printf("Type a number to choose \n 1) Quit \n 2) Continue \n 3) Print Tree \n");
    scanf("%d", &userInput);
    if(userInput == 1){
        printf("Have a great day!\n");
    }
    if(userInput == 2){
        userInterface();
    }
    if(userInput == 3) {
        printTree(root, 1);
    }
}
