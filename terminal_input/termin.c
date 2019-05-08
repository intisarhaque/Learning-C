#include <stdio.h>

int main()
{
  char str[100];
  int i;

  printf("enter a value: \t");
  scanf("%d %s", &i, str);
  printf("\n you entered: %d::%s \n ", i, str );
  return 0;


}
