#include <stdio.h>
#include "foo.h"  /* Include the header here, to obtain the function declaration */

void userInterface();
void readFile();
void writeFile();
void searchEmployee();
void insertEmployee();
void deleteEmployee();
void doWeWantToQuit();


int main(void)
{

    userInterface();
    return 0;
}

void userInterface(){
    printf("In the userInterface method\n");
    int userInput;
    printf("Type a number to choose \n 1) Read a file \n 2) Write a file \n 3) Search Employee \n 4) Hire Employee \n"
                   " 5) Fire employee \n");
    scanf("%d", &userInput);
    if(userInput == 1){
     readFile();
    }
    if(userInput == 2){
        writeFile();
    }
    if(userInput == 3){
        searchEmployee();
    }
    if(userInput == 4){
        insertEmployee();
    }
    if(userInput == 5){
        deleteEmployee();
    }
}
void readFile(){
    printf("In the readFile method \n");

    FILE *file;
    int c;
    file = fopen("ListOfEmployees.txt", "r");
        if (file) {
            while ((c = getc(file)) != EOF)
                putchar(c);
                printf("\n");
            fclose(file);
        }
    doWeWantToQuit();
}
void writeFile(){
    printf("In the writeFile method \n");
    userInterface();
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
    printf("Would you like to quit? Type '1' for yes, '0' for no \n");
    scanf("%d", &userInput);
    if(userInput == 1){
        printf("Have a great day!\n");
    }
    else{
        readFile();
    }
}