#include <stdio.h>
#include "foo.h"  /* Include the header here, to obtain the function declaration */

void userInterface();

int main(void)
{

    userInterface();
    return 0;
}

void userInterface(){
    printf("In the userInterface method\n");
}
int readFile(){
    return 0;
}
int writeFile(){
    return 0;
}
int searchEmployee(){
    return 0;
}
int insertEmployee(){
    return 0;
}
int deleteEmployee(){
    return 0;
}