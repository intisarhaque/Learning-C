#include <stdio.h>

/*
  For user to enter data. Can be handles by requesting data from the user printf
  or supplying the information to the program at the time the program is executed(cli args)

*/


int main(int argc, char *argv[])
{
  int noOfArgs = argc;
  char *argument1 = argv[0];
  char *argument2 = argv[1];

  printf("No of args is %d\n", noOfArgs);
  printf("Argument 1 is the program name: %s\n", argument1);
  printf("Argument 2 is the cli arg: %s\n", argument2);
  return 0;
}
