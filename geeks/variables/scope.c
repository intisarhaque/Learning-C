// # include <stdio.h>

// int x = 0;
// int f()
// {
// return x;
// }
// int g()
// {
// int x = 1;
// return f();
// }
// int main()
// {
// printf("%d", g());
// printf("\n");
// getchar();
// }

//function scope
// C program to illustrate the global scope

// #include <stdio.h>

// // Global variable
// int global = 5;

// // global variable accessed from
// // within a function
// void display()
// {
// 	printf("%d\n", global);
// }

// // main function
// int main()
// {
// 	printf("Before change within main: ");
// 	display();

// 	// changing value of global
// 	// variable from main function
// 	printf("After change within main: ");
// 	global = 10;
// 	display();
// }

#include <stdio.h>
 
// Driver Code
int main()
{
    {
        int x = 10, y = 20;
        {
            // The outer block contains declaration of x and y, so following statement is valid and prints 10 and 20
            printf("x = %d, y = %d\n", x, y);
            {
                // y is declared again, so outer block y is not accessible in this block
                int y = 40;
                // Changes the outer block variable x to 11
                x++;
                // Changes this block's variable y to 41
                y++;
                printf("x = %d, y = %d\n", x, y);
            }
            // This statement accesses only outer block's variables
            printf("x = %d, y = %d\n", x, y); //11 and 20
        }
    }
    return 0;
}