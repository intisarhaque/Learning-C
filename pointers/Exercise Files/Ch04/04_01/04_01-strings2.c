#include <stdio.h>

//QUESTION: WHY DOES THIS +X KNOW TO GO TO THE NEXT STRING COMPARED TO STRINGS4 IT 
int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit;
	for(x=0; x<4; x++)
		printf("Address: %p = %s\n", *(f+x), *(f+x) );

	return(0);
}
