#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    char *x;

    int b;
    int *y;

    printf("Address of a is %p\n", &a);
    printf("Address of b is %p\n", &b);

    x = &a;
    y = &b;

    printf("X holds address %p\n", x);
    printf("Y holds address  %p\n", y);





}