#include <stdio.h>

int main()
{
    //should specify size of int 
    int a=0, b=0;
    for (int i=1; i<21; i+=1){ //++i performance better, especially on embedded
        a+=3;
        b+=7;
        printf("%d-\t",i);
        if (i%5==0){
            printf("a is:%d ", a);
            printf("b is:%d\n", b);
            continue;
        }
        if (a%2!=0){ //bitwise operator faster
            printf("a is:%d", a);
        }
        if (b%2==0){
            printf("b is:%d", b);
        }
        printf("\n");
    }
    return 0;
}
// for (uint8_t i=10; i>=0; i--) (will never go below 0)
// 00000000
// unsigned 2x2^8
// signed 2x2^7
// 