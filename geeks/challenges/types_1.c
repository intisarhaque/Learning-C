#include <stdio.h>




int sum(int a, int b, int c){
    return (a+b+c);
}

int main()
{
    int a=3, b=5, c=10;
    int total = sum(a,b,c);
    printf("Total is = %d\n", total);
    return 0;
}

