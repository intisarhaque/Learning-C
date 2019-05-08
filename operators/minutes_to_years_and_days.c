#include <stdio.h>

int main()
{
  int minutesInYear = 525600;
  int years = 0;
  double days = 0;
  int minutes = 0;

  printf("\n enter minutes: \t");
  scanf("%d", &minutes);
  printf("\n you entered: %d minutes\n ", minutes);

  years = minutes/minutesInYear;
  days = (double)(minutes%minutesInYear)/1440;

  printf("%d minutes account for %d years and %g days\n", minutes, years, days);



}
