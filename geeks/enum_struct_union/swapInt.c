#include<stdio.h>

void swap(int *ap, int *bp){
    // printf("before swap %p  %p\n", ap, bp); //address
    // printf("before swap %d  %d\n", *ap, *bp); //value    
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
    // printf("after swap %p  %p\n", ap, bp); //address
    // printf("after swap %d  %d\n", *ap, *bp); //value    
}

void swapNoVar(int *ap, int *bp){
    // printf("before swap %p  %p\n", ap, bp); //address
    // printf("before swap %d  %d\n", *ap, *bp); //value    
    /*
        a = 20, b=10
        a = a+b: a=30 b =10
        b = a-b: a=30 b =20
        a = a-b a=10 b=20
    */
    *ap = *ap + *bp;
    *bp = *ap - *bp;
    *ap = *ap - *bp;
    // printf("after swap %p  %p\n", ap, bp); //address
    // printf("after swap %d  %d\n", *ap, *bp); //value    
}

int main(){
    
    int a = 10;
    int b = 20;
    printf("before swap %d  \n", a); //address
    printf("before swap %d  \n", b); //value   
    int * ap = &a;
    int * bp = &b;
    swap(ap, bp);
    printf("after swap %d  \n", a); //address
    printf("after swap %d  \n", b); //value   
    int c = 50;
    int d = 30;
    printf("before swap %d  \n", c); //address
    printf("before swap %d  \n", d); //value  
    int * cp = &c;
    int * dp = &d;
    swapNoVar(cp, dp);
    printf("after swap %d  \n", c); //address
    printf("after swap %d  \n", d); //value   


    return 0;
}