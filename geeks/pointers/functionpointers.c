#include <stdio.h>

int add(int a, int b)
{
    return a+b;
}

int main(){
    //pointer to an array
    //int (*ptr)[10]; //ptr is pointer pointing to array of 10 integers

    //pointer to function
    int result;
    int (*ptr)(int,int);// ptr to function containing 2 arguments and it returns an integer
    ptr = &add; //assign address of function to pointer
    result = (*ptr)(10,20);
    printf("%d", result);

    return 0;
}