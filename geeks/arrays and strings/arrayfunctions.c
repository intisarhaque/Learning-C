/*
strcpy used to copy one string into another
present in string.h
char* strcpy(char* dest, const char* src);
 - dest: pointer to destination array where content is to be copied
 - src: string which will be copied.
 - return: pointer to destination string.

replaced entire content. 
doesn't effect source string
*/
// #include<stdio.h>
// #include<string.h>
 
// int main ()
// {
//     char str1[]="Hello Geeks!";
//     char str2[] = "GeeksforGeeks";
//     char str3[40];
//     char str4[40];
//     char str5[] = "GfG";
     
//     strcpy(str2, str1);
//     strcpy(str3, "Copy successful");
//     strcpy(str4, str5);
//     printf("str1: %s\nstr2: %s\nstr3: %s\nstr4:%s\n", str1, str2, str3, str4);
//     return 0;
// }



/*
strcmp takes 2 strings and compares them lexicographically
present in string.h
int strcmp(const char *leftStr, const char *rightStr );
- compares characters parameter by parameter until characters in both strings 
equal or a NULL encountered.
- returns integer
    - 0 if both strings equal
    - >0 if first non-matching character in left string bigger than right string
    - <0 if first non-matching character in left string smaller than right string

*/
// #include<stdio.h>
// #include<string.h>
// int main()
// { 
      
//     char leftStr[] = "g f g";
//     char rightStr[] = "g f g";
//     char leftStr1[] = "zfz";
//     char rightStr1[] = "gfg";
//     char leftStr2[] = "bfb";
//     char rightStr2[] = "gfg";
      
//     // Using strcmp()
//     int res = strcmp(leftStr, rightStr);
//     int res1 = strcmp(leftStr1, rightStr1);
//     int res2 = strcmp(leftStr2, rightStr2);

      
//     if (res==0)
//         printf("Strings are equal");
//     else 
//         printf("Strings are unequal");
      
//     printf("\nValue returned by strcmp() is:  %d" , res);
//     printf("\nValue returned by strcmp() is:  %d" , res1);
//     printf("\nValue returned by strcmp() is:  %d" , res2);
//     return 0;
// }

/*
strdup/strndup used to duplicate a string

strdup() : 
Syntax : char *strdup(const char *s); 
returns pointer to null-terminated byte string which is a duplicate to string
pointed by S.
memory obtained dynamically using malloc.
*/
// #include<stdio.h>
// #include<string.h>
 
// int main()
// {
//     char source[] = "GeeksForGeeks";
 
//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = strdup(source);
 
//     printf("%s", target);
//     return 0;
// }

/*
strndup() : 
syntax: char *strndup(const char *s, size_t n); 
similar to strdup but at most copies n bytes. if s longer than n only n bytes
copies and a \0 added at the end.
*/
// #include<stdio.h>
// #include<string.h>
 
// int main()
// {
//     char source[] = "GeeksForGeeks";
 
//     // 5 bytes of source are copied to a new memory
//     // allocated dynamically and pointer to copied
//     // memory is returned.
//     char* target = strndup(source, 5);
 
//     printf("%s", target);
//     return 0;
// }



/*
strpbrk() finds first character in string that matches given parameter
char *strpbrk(const char *s1, const char *s2)
- s1 string to be scanned
- s2 chars to match
- returns pointer to character in s1 that matches else NULL
*/
// #include <stdio.h>
// #include <string.h>
  
// // Driver function
// int main()
// {
//     // Declaring three strings
//     char s1[] = "geeksforgeeks";
//     char s2[] = "app";
//     char s3[] = "kite";
//     char* r, *t;
  
//     // Checks for matching character
//     // no match found
//     r = strpbrk(s1, s2); 
//     if (r != 0)
//         printf("First matching character: %c\n", *r);
//     else
//         printf("Character not found");
  
//     // Checks for matching character
//     // first match found at "e"
//     t = strpbrk(s1, s3);
//     if (t != 0)
//         printf("\nFirst matching character: %c\n", *t); //value of pointer t
//     else
//         printf("Character not found");
  
//     return (0);
// }

/*
strcoll() compares 2 string  using LC_COLLATE rules.
declared in string.h
int strcoll(const char *str1, const char *str2)
- takes 2 strings
- returns <0 if str1<str2
- returns 0 if str1=str2
- returns >0 if str1>str2
*/
// C program to illustrate strcoll()
// #include <stdio.h>
// #include <string.h>
  
// int main()
// {
//     char str1[10];
//     char str2[10];
//     int ret;
  
//     strcpy(str1, "geeksforgeeks");
//     strcpy(str2, "GEEKSFORGEEKS");
  
//     ret = strcoll(str1, str2);
  
//     if (ret > 0) {
//         printf("str1 is greater than str2");
//     } else if (ret < 0) {
//         printf("str1 is lesser than str2");
//     } else {
//         printf("str1 is equal to str2");
//     }
  
//     return (0);
// }

/*
ispunct() checks whether a character is an punctuation or not
includes all printable characters that are not alphanumeric/space.
! " # $ % & ' ( ) * +, - . / : ;  ? @ [ \ ] ^ _ ` { | } ~
int ispunct(int ch)
- ch is character to be checked
- returns nonzero if punctuation else returns 0
*/
// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     // The puncuations in str are '!' and ','
//     char str[] = "welcome! to GeeksForGeeks, ";
  
//     int i = 0, count = 0;
//     while (str[i]) {
//         if (ispunct(str[i]))
//             count++;
//         i++;
//     }
//     printf("Sentence contains %d punctuation"
//            " characters.\n", count);
//     return 0;
// }

/*
strspn() returns length of initial substring of the string pointed to by str1
that is made up of only characters contained in str2
size_t strspn(const char *str1, const char *str2)
- str1 string to be scanned
- str2 strings containing matching characters
- returns no of characters in initial segment of str1 which only consists of str2

*/

// #include <stdio.h>
// #include <string.h>
  
// int main () {
//    int len = strspn("geeks for geeks","geek");
//    printf("Length of initial segment matching : %d\n", len );    
//    return(0);
// }

/*
isalpha() checks if character is in alphabet or not
isdigit() checks if characer is number or not
doesn't cover strings. only c strings.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "12abc12";
 
    int alphabet = 0, number = 0, i;
    for (i = 0; str[i] != '\0'; i++)
    {
     
        // check for alphabets
        if (isalpha(str[i]) != 0)
            alphabet++;
 
        // check for decimal digits
        else if (isdigit(str[i]) != 0)
            number++;
    }
 
    printf("Alphabetic_letters = %d, "
           "Decimal_digits = %d\n",
           alphabet, number);
 
    return 0;
}