// Array declaration by specifying size and initializing
// elements
//int arr[6] = { 10, 20, 30, 40 }

// Compiler creates an array of size 6, initializes first 4 elements as specified by user and rest two elements as 0. 
// above is same as "int arr[] = {10, 20, 30, 40, 0, 0}"

// C program to demonstrate that
// array elements are stored
// contiguous locations

// #include <stdio.h>
// int main()
// {
// 	// an array of 10 integers.
// 	// If arr[0] is stored at address x, then arr[1] is stored at x + sizeof(int) arr[2] is stored at x + sizeof(int) + sizeof(int)
// 	// and so on.
// 	//int arr[5] = {12,15,59,95,1};
//     int arr[5];
//     int i;
// 	printf("Size of integer in this compiler is %lu\n", sizeof(int));

// 	for (i = 0; i < 5; i++){
// 		// The use of '&' before a variable name, yields address of variable.
// 		printf("Address arr[%d] (%d) is %p\n", i, arr[i], &arr[i]);

//     }
// 	return 0;
// }


/*
normally passing array done using address.
but possible to pass array by value. done by wrapping array in a structure and
creating a variable of type of that structure and assining values to that array.
after that, passing variable to some other function and modifying it as per
requirements.
only works with non-dynamic arrays (not made using new/malloc)

*/

#include<stdio.h>
#include<stdlib.h>

# define SIZE 5

// A wrapper for array to make sure that array
// is passed by value.
struct ArrayWrapper
{
	int arr[SIZE];
};

// An array is passed by value wrapped in temp
void modify(struct ArrayWrapper temp)
{
	int *ptr = temp.arr;
	int i;

	// Display array contents
	printf("In 'modify()', before modification\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", ptr[i]);

	printf("\n");

	// Modify the array
	for (i = 0; i < SIZE; ++i)
		ptr[i] = 100; // OR *(ptr + i)

	printf("\nIn 'modify()', after modification\n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", ptr[i]); // OR *(ptr + i)
}

// Driver code
int main()
{
	int i;
	struct ArrayWrapper obj;
	for (i=0; i<SIZE; i++)
		obj.arr[i] = 10;

	modify(obj);

	// Display array contents
	printf("\n\nIn 'Main', after calling modify() \n");
	for (i = 0; i < SIZE; ++i)
		printf("%d ", obj.arr[i]); // Not changed

	printf("\n");

	return 0;
}
