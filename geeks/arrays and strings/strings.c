// 1. char str[] = "GeeksforGeeks";

// 2. char str[50] = "GeeksforGeeks";

// 3. char str[] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};

// 4. char str[14] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};
// C program to illustrate strings

// #include<stdio.h>

// int main()
// {
// 	// declare and initialize string
// 	char str[] = "Geeks";
	
// 	// print string
// 	printf("%s",str);
	
// 	return 0;
// }

// C program to illustrate how to
// pass string to functions
#include<stdio.h>

void printStr(char str[])
{
	printf("String is : %s",str);
}

int main()
{
	// declare and initialize string
	char str[] = "GeeksforGeeks";
	
	// print string by passing string
	// to a different function
	printStr(str);
	
	return 0;
}
