#include <stdio.h>

int add(int x, int y);

int main()
{
  int z = add(5, 9);
  printf("%d\n", z);
}

int add(int x, int y)
{
  return x+y;
}
