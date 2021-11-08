// Array declaration by specifying size and initializing
// elements
//int arr[6] = { 10, 20, 30, 40 }

// Compiler creates an array of size 6, initializes first 4 elements as specified by user and rest two elements as 0. 
// above is same as "int arr[] = {10, 20, 30, 40, 0, 0}"

// C program to demonstrate that
// array elements are stored
// contiguous locations

#include <stdio.h>
int main()
{
	// an array of 10 integers.
	// If arr[0] is stored at address x, then arr[1] is stored at x + sizeof(int) arr[2] is stored at x + sizeof(int) + sizeof(int)
	// and so on.
	//int arr[5] = {12,15,59,95,1};
    int arr[5];
    int i;
	printf("Size of integer in this compiler is %lu\n", sizeof(int));

	for (i = 0; i < 5; i++){
		// The use of '&' before a variable name, yields address of variable.
		printf("Address arr[%d] (%d) is %p\n", i, arr[i], &arr[i]);

    }
	return 0;
}
