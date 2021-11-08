// C program to demonstrate
// example of tolower() function.

#include <ctype.h>
#include <stdio.h>

int main()
{
	int j = 0;
	char str[] = "GEEKSFORGEEKS\n";


	// convert ch to lowercase using toLower()
	char ch;

	while (str[j]) {
		ch = str[j];

		// convert ch to lowercase using toLower()
		putchar(tolower(ch));

		j++;
	}

	return 0;
}
