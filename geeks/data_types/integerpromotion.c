// #include <stdio.h>
// int main()
// {
// 	char a = 30, b = 40, c = 10;
// 	char d = (a * b) / c;
// 	printf ("%d ", d);
// 	return 0;
// }
// //initially char assigned as unsigned length which is -128 to 127. but integer promotion takes place.


#include <stdio.h>

int main()
{
	char a = 0xfb;
	unsigned char b = 0xfb;

	printf("a = %c", a);
	printf("\nb = %c", b);

	if (a == b)
	printf("\nSame");
	else
	printf("\nNot Same");
	return 0;
}
// output is not same because though they have same binary representation as char, when comparison operator is used
// they are converted to int. A is signed so its value becomes -5. B becomes 251.\

#include<stdio.h>
int main()
{
	float x = 0.1;
	if (x == 0.1)
		printf("IF");
	else if (x == 0.1f)
		printf("ELSE IF");
	else
		printf("ELSE");
}
//output is ELSEIF bc binary equivalent of 0.1 is different to binary equiavelent of 0.1f
//but binary equivalent of 0.5f is same as 0.5
