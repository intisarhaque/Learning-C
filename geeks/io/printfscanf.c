/*
printf returns total number of chars printed or <0 if error
scanf returns total number of inputs scanned successfully or EOF if input failure occus.
scanf need to use & before variable name assignment unless it is array/string
https://www.geeksforgeeks.org/scanf-fscanf-sscanf-scanf_s-fscanf_s-sscanf_s/
*/
// #include <stdio.h>
// int main()
// {
// 	long int n = 2355;

// 	printf("While printing ");
// 	printf(", the value returned by printf() is : %li", printf("%ld", n));

// 	return 0;

// }

#include <stdio.h>
int main()
{
	char a[100], b[100], c[100];

	// scanf() with one input
	printf("\n First scanf() returns : %d", scanf("%s", a));

	// scanf() with two inputs
	printf("\n Second scanf() returns : %d", scanf("%s%s", a, b));

	// scanf() with three inputs
	printf("\n Third scanf() returns : %d", scanf("%s%s%s", a, b, c));

    printf("\n %s -- %s -- %s", a, b, c);

	return 0;
}
