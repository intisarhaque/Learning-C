//Write a program that call a function 10 times, each time this function must display a counter of how many times it was already used.

#include <stdio.h>

void howManyCalls(void){ 
    static int i = 0; //written in static memory
    int j = 0; //written in stack 
    //(also a heap memory for malloc stuff)
    i+=1;
    printf("used %d times\n", i);
}

int main()
{
    for (int j = 0; j<10; j+=1){
        howManyCalls();
    }
    return 0;
}

