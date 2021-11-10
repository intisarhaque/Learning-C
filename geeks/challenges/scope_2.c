#include <stdio.h>
//Write a program that pass a phrase to a function, and the function prints this phrase.

void printPhrase(char phrase[]){ //can be *phrase
    //check if parameter is null especially when null
    printf("Phrase is: %s", phrase);
}

int main()
{
    char phrase[50] = "i am jimbob"; //r+w; allocates memory in program - pushes to a stack.
    char *phrase1 = "i am jimbob"; //r; segmentation fault if trying to change string. string lives in memory thats not writeable; allocates outside of stack and you point to it. rvalue
    printPhrase(phrase);
    return 0;
}

