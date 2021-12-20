#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit;
	for(x=0; x<4; x++)
	{
		printf("First letter: %c\n", **f );//same as *(*f) //inside brackets is address. asterix dereferences address and gets a value
		printf("First letter: %s\n", *(*f) );//QUESTION: WHY DOES THSI NOT WORK?
		f++;
	}

	return(0);
}
