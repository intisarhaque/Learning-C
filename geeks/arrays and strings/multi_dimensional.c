// Program 1
#include<stdio.h>
int main()
{
int a[][2] = {{1,2},{3,4}}; // Works
printf("%lu", sizeof(a)); // prints 4*sizeof(int)
getchar();
return 0;
}


// Program 2
#include<stdio.h>
int main()
{
int a[][2][2] = { {{1, 2}, {3, 4}},
					{{5, 6}, {7, 8}}
				}; // Works
printf("%lu", sizeof(a)); // prints 8*sizeof(int)
getchar();
return 0;
}

/* to do
https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/
*/