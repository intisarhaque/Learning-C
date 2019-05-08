#include <stdio.h>

int commonDivisor(int x, int y);
float absoluteValue(float x);
int squareRoot(int x);
#define HOWMANYNUMBERS 1000


int main()
{
  int a = commonDivisor(24,84);
  int b = absoluteValue(-12);
  int c = squareRoot(998001);
  printf("%d\t%d\t%d\n",a, b, c);
}

int commonDivisor(int x, int y)
{
  int loopSize = x<y?x:y;
  int divisor;
  for(int i=1; i<=loopSize; i+=1)
  {
    if (x%i==0 && y%i==0)
    {
      divisor =i;
    }
  }
  return divisor;
}

float absoluteValue(float x)
{
  if (x<0)
  {
    x*=-1;
  }
  return x;
}

int squareRoot(int x)
{
  int squareRootReturned = 0;;
  int squareNumbers[HOWMANYNUMBERS];
  for (int i=0; i<HOWMANYNUMBERS; i+=1)
  {
    squareNumbers[i] = i*i;
  }
  if (x<0)
  {
    printf("Invalid number\n");
    return -1;
  }
  for (int j=0; j<HOWMANYNUMBERS; j+=1)
  {
    if (x==squareNumbers[j])
    {
      squareRootReturned = j;
    }
  }
  return squareRootReturned;
}
