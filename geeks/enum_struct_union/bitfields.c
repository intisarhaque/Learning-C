// #include <stdio.h>
// // A simple representation of the date
// struct date {
// 	unsigned int d;
// 	unsigned int m;
// 	unsigned int y;
// };

// int main()
// {
// 	printf("Size of date is %lu bytes\n",
// 		sizeof(struct date));
// 	struct date dt = { 31, 12, 2014 };
// 	printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
// }
/*
size is 12 bytes bc unsigned int is 4 each.
but what if we know what the max sizes can be?
therefor we use bitfields
*/
#include <stdio.h>

// A structure without forced alignment
struct test1 {
	unsigned int x : 5;
	unsigned int y : 8;
};

// A structure with forced alignment
struct test2 {
	unsigned int x : 5; //5 bits from 00000 to 11111 = 15 (31 if not unsisnged)
	unsigned int : 0;
	unsigned int y : 8;
};

struct {
   unsigned int age : 3; //if you want to store a number between 0 and 7
} Age;

int main()
{
	printf("Size of test1 is %lu bytes\n",
		sizeof(struct test1));
	printf("Size of test2 is %lu bytes\n",
		sizeof(struct test2));
	return 0;
}



#include <stdio.h>
#include <string.h>

/* define simple structure */
struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status2;
 
int main( ) {
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1)); //will be 8 only using 2 bits
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2)); //will be 4 only using 2 bits
   return 0;
}