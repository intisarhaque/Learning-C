#include <stdio.h> 

int main()
{
    int j;
    int i; 
    for( i = 0; i < 10; i++ )
    {
        int j = 0; //different to line 5
        for( j = 10; j > 0; j-- ) //j==0
        {
            if( i > j )
            {
                printf("Variable i (%d) is bigger than j (%d) \n", i, j);
                break;
            }
        }
    }
    /* print result */
    printf("Last values: i (%d), j (%d) \n", i, j);
    return 0;
}


/*

variable i (6) is bigger than j (4)
variable i (7) is bigger than j (3)
variable i (8) is bigger than j (2)
variable i (9) is bigger than j (1)

las values: i(random/garbage), j--



*/

