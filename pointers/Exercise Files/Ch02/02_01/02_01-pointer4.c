#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a;

	printf("%p\n", a);
	printf("%p\n", p);
	for( x=0; x<5; x++ )
	{
		//value of p incremented by x integer sized chunks
		printf("%d\n", *(p+x) );
		printf("%p\n", &a[x] );
	}

	return(0);
}
