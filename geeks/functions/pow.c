// C program to illustrate
// power function
#include <math.h>
#include <stdio.h>

int main()
{
	double x = 6.1, y = 4.8;

	// Storing the answer in result.
	double result = pow(x, y);
	printf("%.2lf", result);

    //some compiler not like squaring int so will round down. 
    // 5^2 becomes 24.999 so int will be 24.
    //overcome like so:
    int a = (int)(pow(5, 2) + 0.5);

	return 0;
}

