#include <stdio.h>

int main()
{
  int grades[10];
  int count = 10;
  long sum = 0;
  float average = 0.0f;
  printf("Enter 10 numbers\n");
  for (int i=0; i<count; i+=1)
  {
    printf("Enter number %d\n", i+1);
    scanf("%d", &grades[i]);
    sum += grades[i];
  }
  average = (float)sum/count;
  printf("Sum %ld\nAverage %.2f", sum, average);


}
