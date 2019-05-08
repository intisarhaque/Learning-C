#include <stdio.h>

int main()
{
  int i=100;
  float f=331.79;
  double d=8.44e+11;
  char c = 'W';
  _Bool b = 0;
  long l = 20000;

  printf("\ni = %d, f = %f, d = %e, d = %g, c = %c, b = %i, l=%ld\n", i, f, d, d, c, b, l);

}

/*
  Used when displaying variables as output
  printf is a function with 2 arguments:
  first argument is the character string to be displayed, data to print is after comma.

*/
