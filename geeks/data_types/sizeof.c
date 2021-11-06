// #include <stdio.h>
// #include <stdbool.h>

// int main()
// {
// 	int a = 1;
// 	char b = 'G';
// 	double c = 3.14;
// 	printf("Hello World!\n");

// 	// printing the variables defined
// 	// above along with their sizes
// 	printf("Hello! I am a character. My value is %c and "
// 		"my size is %lu byte.\n",
// 		b, sizeof(char));
// 	// can use sizeof(b) above as well

// 	printf("Hello! I am an integer. My value is %d and "
// 		"my size is %lu bytes.\n",
// 		a, sizeof(int));
// 	// can use sizeof(a) above as well

// 	printf("Hello! I am a double floating point variable."
// 		" My value is %lf and my size is %lu bytes.\n",
// 		c, sizeof(double));
// 	// can use sizeof(c) above as well

// 	printf("Bye! See you soon. :)\n");

// 	return 0;
// }
// C implementation of the above idea
// #include <stdio.h>

// // Declaration of enum
// typedef enum { F, T } boolean;

// int main()
// {
// 	boolean bool1, bool2;
// 	bool1 = F;

// 	if (bool1 == F) {
// 		printf("bool1 is false\n");
// 	}
// 	else {
// 		printf("bool1 is true\n");
// 	}
// 	bool2 = T;
// 	if (bool2 == F) {
// 		printf("bool2 is false\n");
// 	}
// 	else {
// 		printf("bool2 is true\n");
// 	}
// }


// C program to demonstrate that size_t or
// any unsigned int type should be used 
// carefully when used in a loop.
#include<stdio.h>
  
#define N 10
  
int main()
{
    int a[N];
  
    // This is fine.
    for (size_t n = 0; n < N; ++n) {
        a[n] = n;
    }
          
    // But reverse cycles are tricky for unsigned 
    // types as they can lead to infinite loops.
    for (size_t n = N-1; n >= 0; --n){
        printf("%d\n ", a[n]);
         printf("%d ", n);
   }
}
        