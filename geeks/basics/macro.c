// #include <stdio.h>
// #define MULTIPLY(a, b) a*b
// int main()
// {
// 	// The macro is expanded as 2 + 3 * 3 + 5, not as 5*8. doesn't use brackets to evaluate
// 	printf("%d", MULTIPLY(2+3, 3+5));
// 	return 0;
// }
// // Output is 16

// #include <stdio.h>
// //here, instead of writing a*a we write (a)*(b)
// #define MULTIPLY(a, b) (a)*(b)
// int main()
// {
// 	// The macro is expanded as (2 + 3) * (3 + 5), as 5*8
// 	printf("%d", MULTIPLY(2+3, 3+5));
// 	return 0;
// }
// // Output is 40
// //macro arguments not evaluated before macro expression
// //https://www.includehelp.com/c-programs/macro-arguments-evaluation-in-c.aspx


// #include <stdio.h>
// #define merge(a, b) a##b
// int main()
// {
//     printf("%d ", merge(12, 34));
// }
// // Output is 1234 - Token-pasting

// #include<stdio.h> 
// #define f(g,g2) g##g2 
// int main() 
// { 
//    int var12 = 100; 
//    printf("%d", f(var,12)); 
//    return 0; 
// }
// //becomes
// int main() 
// { 
//    int var12 = 100; 
//    printf("%d", var12); 
//    return 0; 
// } // output is 100




// #include <stdio.h>
// #define get(a) #a
// int main()
// {
// 	// GeeksQuiz is changed to "GeeksQuiz"
// 	printf("%s", get(GeeksQuiz));
// }
// // Output is GeeksQuiz - token converted to string literal

// #include <stdio.h>
// #define PRINT(i, limit) while (i < limit) \
// 						{ \
// 							printf("GeeksQuiz "); \
// 							i++; \
// 						}
// int main()
// {
// 	int i = 0;
// 	PRINT(i, 3);
// 	return 0;
// }
// // GeeksQuiz GeeksQuiz GeeksQuiz - can write macros in multiple lines using \


// #include <stdio.h>
// #define square(x) x*x
// static inline int squareTwo(int y) { return y*y; }
// int main()
// {
// 	// Expanded as 36/6*6 like the function directly is called into line 63
// 	int x = 36/square(6);
// 	printf("%d \n", x);
// 	int y = 36/squareTwo(6);
// 	printf("%d", y);
// 	return 0;
// }
// // 36 \n 1 - macros with arguments should be avoided. inline functions preferred.

// int main()
// {
// #if VERBOSE >= 2
// 	printf("Trace Message");
// #endif
// }
// // no output - preprocessers support if-else directives

// #include <stdio.h>
 
// int main()
// {
//    printf("Current File :%s\n", __FILE__ );
//    printf("Current Date :%s\n", __DATE__ );
//    printf("Current Time :%s\n", __TIME__ );
//    printf("Line Number :%d\n", __LINE__ );
//    return 0;
// }
// //Current File :macro.c Current Date :Nov  5 2021 Current Time :09:33:05 Line Number :86 - standard macros


// #include <stdio.h>
// #define PRINT(i, limit) do 	{ if (i++ < limit) { printf("GeeksQuizn"); continue; } }while(1)

// int main()
// {
// 	int i = 0;
// 	//will work if you put i in
// 	PRINT(0, 3);
// 	return 0;
// }
//The PRINT macro gets expanded at the pre-processor time i.e. before the compilation time. 
//After the macro expansion, the if expression becomes: if (0++ < 3). 
//Since 0 is a constant figure and represents only r-value, applying increment operator gives compile-time error: 
//lvalue required. lvalue means a memory location with some address.

#include<stdio.h>
#define SQR(x) (x*x)
int main()
{
    int a;
    int b=4;
    a=SQR(b+2);
    printf("%d",a);
    return 0;
}
// output is 14