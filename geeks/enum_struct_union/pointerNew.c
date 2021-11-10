// #include<stdio.h>

// void *newLoc(int **app){
//     printf("app before innewloc %p\n", app);
//     int d = 20;
//     printf("d innewloc %p\n", &d);
//     int *dp = &d;
//     app = &dp;
//     printf("app after innewloc %p\n", app);
//     return 0;
// }

// int main(){
//     int a = 10;
//     int *ap = &a;
//     int **app = &ap;
//     printf("ap before %p\n", ap);
//     printf("app before %p\n", app);
//     newLoc(app);

//     printf("ap after %p\n", ap);
//     printf("app after %p\n", app);

//     return 0;
// }


#include<stdio.h>

void newLoc (int **ap){
    
    int b = 20;
    int *bp = &b;
    printf("bp %p\n", bp);
    printf("b value %d\n", *bp);
    *ap = bp;
    return;
}

int main(){

    int a = 10;
    int *ap = &a;
    printf("first ap %p\n", ap);
    printf("first a value %d\n", *ap);
    newLoc(&ap);
    printf("final ap %p\n", ap);
    printf("final a value %d\n", *ap);
    return 0;
}