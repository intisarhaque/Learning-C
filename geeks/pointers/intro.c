// // C program to demonstrate use of * for pointers in C
// #include <stdio.h>

// int main()
// {
// 	// A normal integer variable
// 	int Var = 10;

// 	// A pointer variable that holds address of var.
// 	int *ptr = &Var;

// 	// This line prints value at address stored in ptr.
// 	// Value stored is value of variable "var"
// 	printf("Value of Var = %d\n", *ptr);

// 	// The output of this line may be different in different runs even on same machine.
// 	printf("Address of Var = %p\n", ptr);

// 	// We can also use ptr as lvalue (Left hand side of assignment)
// 	*ptr = 20; // Value at address is now 20

// 	// This prints 20
// 	printf("After doing *ptr = 20, *ptr is %d\n", *ptr);

// 	return 0;
// }


// #include <stdio.h>
// void geeks()
// {
// 	// Declare an array
// 	int val[3] = { 5, 10, 15};

// 	// Declare pointer variable
// 	int *ptr;

// 	// Assign address of val[0] to ptr.
// 	// We can use ptr=&val[0];(both are same)
// 	ptr = val ;
//     printf("Elements of the array are %d %d %d", ptr[0], ptr[1], ptr[2]);

// 	return;
// }

// // Driver program
// int main()
// {
// 	geeks();
// 	return 0;
// }

#include<stdio.h>
int main()
{
    char *ptr = "ceeksforgeeks";
    printf("1 %c\n", *&*&*ptr); // g
    printf("2 %s\n", *&*&ptr); // geekforgeeks

    printf("3 %c\n", *ptr); // g
    printf("4 %p\n", &*ptr); // address of g ox50
    printf("5 %c\n", *&*ptr); //  g
    printf("6 %p\n", &*&*ptr);// address of g

    printf("7 %p\n", &ptr); //different address (maybe address of 6) //adress of object of pointer 0x2
    printf("8 %p\n", *&ptr); //address of g
    printf("9 %s\n", *&ptr); //geekforgeeks
    printf("10 %p\n", &*&ptr); // print same as 7
    printf("11 %s\n", &*&ptr); // nothing
    printf("12 %p\n", *&*&ptr); // print same as 8
    printf("13 %s\n", *&*&ptr); // geekforgeeks

    return 0;
}
/*
2 interrupts, software/hardare
device sends interrupt to high or low to notify that there's data to read.
kernel POV. System that controls the GPIO set as interrupt.
when interrupt arrives there is assembler code that calls function
callback function on kernel variables and needs to be really fast and do a few operations
in function you define what to do - if interrupt enable device to read and set a flag


Pointer tools
2 categories
    - operators
        - unary * (poiinter)
        - unary & (address-of)
        - sizeof (keyword but also operator)
    - symbolic constant
        - null (pointer not assigned to address)
        - size_t (byte count for use when allocating memory)

data type | name | value | & contains address of sotrage location | sizeof how much variable occupies in storage
      int   size =  64

array a[] and pointer *p
    - to assign P to base of array: p = a
    - assign p to array element n: p = &a[n]
    - access element n's address: p+n
    - access element n's value: *(p+n)

*/
