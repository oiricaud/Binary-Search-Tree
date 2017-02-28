#include <stdio.h>
#include <stdlib.h>
#include "foo.h"  /* Include the header here, to obtain the function declaration */

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
    printf("Type a number to choose \n 1) Read a file \n 2) Write a file \n 3) Search Employee \n 4) Hire Employee \n"
                   " 5) Fire employee ");
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
    printf("In the writeFile method ");


    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
    }
    else {
        getchar();
        printf("Type first and last name: ");
        characters = getline(&b, &bufsize, stdin);
        printf("%zu characters were read.\n", characters);
        printf("You typed: '%s'\n", buffer);

        const char *text = buffer;
        fprintf(fptr, "%s\n", text);
    }

}
void searchEmployee(){
    printf("In the searchEmployee method \n");
    userInterface();
}
void insertEmployee(){
    printf("In the insertEmployee method \n");
    userInterface();
}
void deleteEmployee(){
    printf("In the deleteEmployee method \n");
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
