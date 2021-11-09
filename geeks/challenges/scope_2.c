#include <stdio.h>

void printPhrase(char phrase[]){ //can be *phrase
    printf("Phrase is: %s", phrase);
}

int main()
{
    char phrase[50] = "i am jimbob";
    printPhrase(phrase);
    return 0;
}

