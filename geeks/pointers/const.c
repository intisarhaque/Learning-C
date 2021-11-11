#include <stdio.h>

int main(){

    int *ptr; //can change value of ptr and value ptr pointing to. stored in read/write
    const int *ptr1; //can change pointer to point to another variable but can't chagne value of object pointed using ptr. pointer in r/w object in read only.
    int *const ptr2; // can cahnge value of object pointed by pointer, but can't change pointer to point to another variable.
    const int *const ptr3; // can't change where object points nor object value.



    return 0;
}

int main(void)
{
	/* i is stored in read only area*/
	int const i = 10;
	int j = 20;

	/* pointer to integer constant. Here i
	is of type "const int", and &i is of
	type "const int *". And p is of type
	"const int", types are matching no issue */
	int const *ptr = &i;	

	printf("ptr: %d\n", *ptr);

	/* error */
	*ptr = 100;	

	/* valid. We call it up qualification. In
	C/C++, the type of "int *" is allowed to up
	qualify to the type "const int *". The type of
	&j is "int *" and is implicitly up qualified by
	the compiler to "const int *" */

	ptr = &j;		
	printf("ptr: %d\n", *ptr);

	return 0;
}
