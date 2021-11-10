/*
when strings declared as character array, stored like other type of array.
if str[] is auto variable then stored in stack. if global variable stored in data
segement.

Using character pointer
 - read only string in shared segment - when string assinged to a pointer it's stored
 in a read only block. but pointer stored in r/w location. can change pointer where
 it points to.

 - dynamically allocated in a heap segement - sored like other dynamically allocated
 things in C and can be shared among functions


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *str; 
    str = "GfG";     /* Stored in read only part of data segment */
    *(str+1) = 'n'; /* Problem:  trying to modify read only memory */
    getchar();
    return 0;
}

int main()
{
    char str[] = "GfG";  /* Stored in stack segment like other auto variables */
    *(str+1) = 'n';   /* No problem: String is now GnG */
    getchar();
    return 0;
}

int main()
{
    int size = 4;

    /* Stored in heap segment like other dynamically allocated things */
    char *str = (char *)malloc(sizeof(char)*size);
    *(str+0) = 'G'; 
    *(str+1) = 'f';  
    *(str+2) = 'G';    
    *(str+3) = '\0';  
    *(str+1) = 'n';  /* No problem: String is now GnG */
    getchar();
    return 0;
}   


//below string stored in shared segment
char *getString()
{
  char *str = "GfG"; /* Stored in read only part of shared segment */
  
  /* No problem: remains at address str after getString() returns*/
  return str;  
}     
int main()
{
  printf("%s", getString());  
  getchar();
  return 0;
}

//below string stored in heap segment and data in heap persists even after return
//of get string
char *getString()
{
  int size = 4;
  char *str = (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
  *(str+0) = 'G'; 
  *(str+1) = 'f';  
  *(str+2) = 'G';
  *(str+3) = '\0';  
  /* No problem: string remains at str after getString() returns */    
  return str;  
}     
int main()
{
  printf("%s", getString());  
  getchar();
  return 0;
}


// may print garbage data as string is stored in stackframe of getString() and data
//may not be there after getstring returns.
char *getString()
{
  char str[] = "GfG"; /* Stored in stack segment */
  
  /* Problem: string may not be present after getString() returns */
  /* Problem can be solved if write static before char, i.e. static char str[] = "GfG";*/
  return str; 
}     
int main()
{
  printf("%s", getString());  
  getchar();
  return 0;
}