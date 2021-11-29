/*
    program will raise, catch, alarm signal
    program to test users multiplication skills keeping track of how many answers correct
    program runs forever until user presses ctrl C or takes >5seconds to answer question
    when program ends display final score

    need to handle user pressing ctrl C using signal or sighandle which sents interrpt signal-> display final score-> exit
    raise signal if 5 seconds without answer (alarm); function to catch alarm

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

int main() {

   srand (time(0));
   
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];
    
      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
    }

    return 0;
} 
