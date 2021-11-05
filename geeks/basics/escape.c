// // C program to illustrate
// // \a escape sequence
// #include <stdio.h>
// int main(void)
// {
// 	printf("My mobile number "
// 		"is 7\a8\a7\a3\a9\a2\a3\a4\a0\a8\a");
// 	printf("Hello Geeks\b\b\b\bF");
//     printf("Hello fri \r ends");
// 	printf("Hello\\GFG");
// 	return (0);
// }

// C program to illustrate the concept of Line splicing.
#include <stdio.h>
int main()
{
    // Line Splicing\
    printf("Hello GFG\n");
    printf("welcome\n");
    /* Example 2 - both of the below lines will be printed*/ \
    printf("Hello\t");
    printf("World");
    return (0);
}