/*
after memory management
https://www.geeksforgeeks.org/variable-length-arrays-in-c-and-c/

*/

//shorthand array
// #include <stdio.h>
  
// int main()
// {
//     // This line is same as
//     // int array[10] = {1, 1, 1, 1, 0, 0, 2, 2, 2, 2};
//     int array[10] = {[0 ... 3]1, [6 ... 9]2};//4...5 autod as 0

  
//     for (int i = 0; i < 10; i++)
//         printf("%d ", array[i]);
//     return 0;
// }



/*
no arrayoutofboundsexception in C like java
when happens its called Undefined Behaviour.
result of executing computer code whose behaviour not prescribed 
by language spec to current state of program (memory)
*/
#include <stdio.h>
int main()
{
    int arr[] = {1,2,3,4,5};
    printf("arr [0] is %d\n", arr[0]);
      
    // arr[10] is out of bound so brings random number that is garbage value
    // can access memory not owned by it causing crash of segmentation fault
    printf("arr[10] is %d\n", arr[10]); 
    return 0;
}