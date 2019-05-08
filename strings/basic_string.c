#include <stdio.h>
#include <string.h>

int main()
{
  printf("This is a string\n");
  printf("For \" you write \\\"\n");//double escape
  //strings end in a \0 so the length of a string is one greater than char's in a string.
  //printf("Look at how \0 fucks up\n");
  char myString[20]; //  this is now a string that can be 19 chars long.
  char word1[] = {'h','e','r','r','o','\0'}; //holds 6 spaces for characters
  char word2[60] = {"hello"};//have to remember the extra characters, best to leave it out.
  char word3[] = "hello";
  //cannot declare then initialize, cannot assign one array of characters to another
  char word4[100];
  word4[0]='h'; word4[1]='e'; word4[2]='l'; word4[3]='l'; word4[4]='p';word4[5]='\0';
  char word5[10];
  printf("What?\n");
  scanf("%s", word5);
  const char word6[] = "Hewoo";
  printf("\nThe words are %s\n%s\n%s\n%s\n%s\n%s\n", word1, word2, word3, word4, word5, word6);
  printf("The length of all these words are %lu\n%lu\n%lu\n%lu\n%lu\n%lu\n", strlen(word1),strlen(word2),strlen(word3),strlen(word4),strlen(word5),strlen(word6));
  const int months = 12;
  char word7[40];
  strncpy(word7, word6, sizeof(word7)-1);
  printf("%s\n", word7);
  printf("%s\n", strcat(word2, word1));//permanently changes destination.
  printf("%s\n", strncat(word2, word1, 2));
  printf("%s\n", word2);

  printf("%d\n", strcmp("A", "A"));
  printf("%d\n", strcmp("A", "B"));
  printf("%d\n", strcmp("B", "A"));
  printf("%d\n", strcmp("a", "A"));
  printf("%d\n", strcmp("A", "a"));
  printf("%d\n", strcmp("Z", "a"));//"Z" before "a"
  // printf("%d\n", strcmp("apples", "apple"));//strncmp compares until words differ or until no of chars reached

  char str[] = "The quick brown fox is a prick"; //string to be searched
  char ch  = 'h';                                //character we're looking for
  char *p_got_char = NULL;                       //pointer initialized to null
  p_got_char = strchr(str,ch);                   //stores address where ch is found
  char che  = 'x';                                //character we're looking for
  char *p_got_chare = NULL;                       //pointer initialized to null
  p_got_chare = strchr(str,che);                   //stores address where ch is found
  printf("%s \n", p_got_char);
  printf("%s \n", p_got_chare);
  //printf("%c \n", p_got_char);              //doesnt work
  //printf("%c \n", p_got_chare);
  printf("%c char \n", *p_got_char);          //dereference
  printf("%c char \n", *p_got_chare);
  printf("%d char(in ascii) \n", *p_got_char);          //dereference as int
  printf("%d char(in ascii) \n", *p_got_chare);
  printf("%p address \n", p_got_char);
  printf("%p address \n", p_got_chare);

  p_got_char = strrchr(str,ch);
  printf("%s \n", p_got_char);
  printf("%d address \n", *p_got_char);
  char text[] = "Every dog has its day";
  char word[] = "";
  char *p_found = NULL;
  p_found = strstr(text, word);
  printf("%s\n", p_found);
  printf("%d\n", *p_found);

  char stre[80] = "Hello - my name is - Intisar";
  const char s[2] = "-";
  char *token;

  token  = strtok(stre, s); //get the first token

  while(token != NULL)//exits when token reaching the null terminator
  {
    printf("%s\n", token);
    token = strtok(NULL, s);
  }




  /*
    length of string - strlen -
    copying one string to another - strcpy  strncpy
    concatenating two strings - strcat  strncat
    determining if two character strings are equal - strcmp  strcnmp

    How to convert a string into upper characters.
    for(int i=0;(buf[i]tosupper(buf[i]!))='\0') cast of type char because toupper returns type int
  */


}
