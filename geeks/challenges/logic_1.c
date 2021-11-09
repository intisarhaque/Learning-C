#include <stdio.h>

int main()
{
    int a=0, b=0;
    for (int i=1; i<21; i+=1){
        a+=3;
        b+=7;
        printf("%d-\t",i);
        if (i%5==0){
            printf("a is:%d ", a);
            printf("b is:%d\n", b);

            continue;
        }
        if (a%2!=0){
            printf("a is:%d", a);
        }
        if (b%2==0){
            printf("b is:%d", b);
        }
        printf("\n");
    }


    return 0;
}

