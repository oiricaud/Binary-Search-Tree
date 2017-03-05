#include <stdio.h>      /* for printf */
#include <stdlib.h>     /* for free() */
#include <string.h>     /* for strlen */
#include "functions.h"

int input(char *s,int length);
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

int main(void) {

    printf("\n|***** Welcome to Electric Fetus Music Store! ******|\n");
    userInterface();
    return 0;
}
