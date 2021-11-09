#include <stdio.h>



void howManyCalls(void){ 
    static int i = 0;
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

