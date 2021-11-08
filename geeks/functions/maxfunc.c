#include <stdio.h>

// An example function that takes two parameters 'x' and 'y'
// as input and returns max of two input numbers
// function declared and defined at the same time
int max(int x, int y)
{
    //x and y are formal parameters
	if (x > y)
	return x;
	else
	return y;
}

// main function that doesn't receive any parameter and
// returns integer.
int main(void)
{
    //actual parameters
	int a = 10, b = 20;

	// Calling above function to find max of 'a' and 'b'
	int m = max(a, b);
    

	printf("m is %d", m);
	return 0;
}


//function declaration
// A function that takes two integers as parameters
// and returns an integer
int max(int, int);
  
// A function that takes an int pointer and an int variable as parameters
// and returns a pointer of type int
int *swap(int*,int);
  
// A function that takes a charas parameters
// and returns a reference variable
char *call(char b);
  
// A function that takes a char and an int as parameters
// and returns an integer
int fun(char, int);