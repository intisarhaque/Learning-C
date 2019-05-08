#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t t;
  srand((unsigned) time(&t));
  printf("%lu\n", t);
  int randomNumber = rand() % 21;
  printf("%d\n", randomNumber);
  int theirGuess;
  int i=5;
  while(i>0)
  {
    printf("You have %d tr%s left\n", i, i==1?"y":"ies");
    printf("Guess a number between 0-20 I'll tell you if you're stupid\n");
    scanf("%d", &theirGuess);
    if (theirGuess == randomNumber)
    {
      printf("You have guessed %d and it is correct!\n", theirGuess);
      break;
    }
    else if (theirGuess>randomNumber)
    {
      printf("Idiot, my number is lower\n");
    }
    else
    {
      printf("Doofus, my number is higher\n");
    }
    i-=1;

  }
  if (i==0)
  {
    printf("You are out of tries\n");
  }
}
// for (int i=5; i>=1; i--)
// {
//   printf("You have %d tries left\n", i);
//   printf("Guess a number between 0-20 I'll tell you if you're stupid\n");
//   scanf("%d", &theirGuess);
//   if (theirGuess == randomNumber)
//   {
//     printf("You have guessed %d and it is correct!\n", theirGuess);
//     return;
//   }
//   else if (theirGuess>randomNumber)
//   {
//     printf("Idiot, my number is lower\n");
//   }
//   else
//   {
//     printf("Doofus, my number is higher\n");
//   }
// }
// printf("%d", i);
