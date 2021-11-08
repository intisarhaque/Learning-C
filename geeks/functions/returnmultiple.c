// //using pointers
// // Modified program using pointers
// #include <stdio.h>

// // add is the short name for address
// void compare(int a, int b, int* add_great, int* add_small)
// {
// 	if (a > b) {

// 		// a is stored in the address pointed
// 		// by the pointer variable *add_great
// 		*add_great = a;
// 		*add_small = b;
// 	}
// 	else {
// 		*add_great = b;
// 		*add_small = a;
// 	}
// }

// // Driver code
// int main()
// {
// 	int great, small, x, y;

// 	printf("Enter two numbers: \n");
// 	scanf("%d%d", &x, &y);

// 	// The last two arguments are passed
// 	// by giving addresses of memory locations
// 	compare(x, y, &great, &small);
// 	printf("\nThe greater number is %d and the"
// 		"smaller number is %d",
// 		great, small);

// 	return 0;
// }
/*output
Enter two numbers: 
5 8
The greater number is 8 and the smaller number is 5
*/



// //using struct
// // Modified program using structures
// #include <stdio.h>
// struct greaterSmaller {
// 	int greater, smaller;
// };

// typedef struct greaterSmaller Struct;

// Struct findGreaterSmaller(int a, int b)
// {
// 	Struct s;
// 	if (a > b) {
// 		s.greater = a;
// 		s.smaller = b;
// 	}
// 	else {
// 		s.greater = b;
// 		s.smaller = a;
// 	}

// 	return s;
// }

// // Driver code
// int main()
// {
// 	int x, y;
// 	Struct result;

// 	printf("Enter two numbers: \n");
// 	scanf("%d%d", &x, &y);

// 	// The last two arguments are passed
// 	// by giving addresses of memory locations
// 	result = findGreaterSmaller(x, y);
// 	printf("\nThe greater number is %d and the"
// 		"smaller number is %d",
// 		result.greater, result.smaller);

// 	return 0;
// }
/*output
Enter two numbers: 
5 8
The greater number is 8 and the smaller number is 5
*/



