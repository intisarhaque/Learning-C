#include <stdio.h>
#include <stdlib.h>

unsigned long ul(int x){
    unsigned long y =(unsigned long) x;
    return (unsigned long) y;
}

int main()
{
    unsigned long int base = 0;
    char str[] = "14235235";
    // char c;
    // printf("%s\n",str);
    // printf("%d wgewe\n", sizeof(str));
    // for loop end to beginning doing x10^length-i

    int x = atoi(str);//error handling
    printf("%d has size of %li\n", x, sizeof(x)); //expecting 4
    
    unsigned long y = ul(x);
    printf("%li has size of %li \n ", y, sizeof(y)); //expecting 8 (varies depending on machine chipset)

    return 0;
}

