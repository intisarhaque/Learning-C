#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/* array and pointer different. 
- array sizeof gives no of elements, pointer size of gives size of pointer.
- array is alias for &array[0] and returns address of first element 
    - &pointer returns address of pointer
- using char array adds \0. using string literal doesn't
- pointer variable assigned a value where as array variable can't
    -int a[10];
    int *p; 
    p=a; legal
    a=p; illegal
- arithhmetic on pointer allowed


similar too
- array names give address of first element of array
- array members access using pointer arithmetic
- array parameters always passed as pointers even using square brackets








*/

#include <stdio.h>
// int main()
// {
//     int arr[] = { 10, 20, 30, 40, 50, 60 };
//     // Assigns address of array to ptr
//     int* ptr = arr;
//     printf("Value of first element is %d", *ptr); //*arr too
//     return 0;
// }

int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;
   printf("arr[2] = %d\n", arr[2]);
   printf("*(arr + 2) = %d\n", *(arr + 2));
   printf("ptr[2] = %d\n", ptr[2]);
   printf("*(ptr + 2) = %d\n", *(ptr + 2));
   return 0;
}