#include<stdio.h>
/*
when we want to print long string we can break in middle using 2 " in the middle.



*/

int main()
{
   // We can put two double quotes anywhere in a string
   char *str1  = "geeks""quiz"; 
  
   // We can put space line break between two double quotes
   char *str2  = "Qeeks"     "Quiz";
   char *str3  = "Qeeks"     
                 "Quiz";

    char *str4 = "These are reserved words in C language are int, float, "
        "if, else, for, while etc. An Identifier is a sequence of"
        "letters and digits, but must start with a letter. "
        "Underscore ( _ ) is treated as a letter. Identifiers are "
        "case sensitive. Identifiers are used to name variables,"
        "functions etc.";
        
   puts(str1);
   puts(str2);
   puts(str3);
   puts(str4);
   puts("Geeks"        // Breaking string in multiple lines
        "forGeeks");
   return 0;
}