#include <stdio.h>

int main()
{
  int primeNumbers[100] = {2, 3};
  _Bool isIPrime = 0;
  int count=2;

  for (int i=5; i<=300; i+=2)
  {
    for (int j=1;j<count;j+=1)
    {
      if (i%primeNumbers[j]==0)
      {
        isIPrime=0;
      }
      else
      {
        isIPrime=1;
      }
      printf("i=%d\t j=%d\t isIPrime=%d \n", i, j, isIPrime);
      if (isIPrime==0)
      {
        break;
      }
    }
    if (isIPrime==1)
    {
      primeNumbers[count]=i;
      count+=1;
    }
  }


  for (int i=0; i<100; i+=1)
  {
    printf("%d: %d\n", i+1, primeNumbers[i]);
  }
}
