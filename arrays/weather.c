#include <stdio.h>

int main()
{
  int totayYearRain = 0;
  double averageYearRain = 0;
  int rainfallByYear[5]={0,0,0,0,0};
  int rainfallByMonth[12]={0,0,0,0,0,0,0,0,0,0,0,0};
  int rainfall[5][12] = {
                   {1,2,3,4,5,6,7,8,9,10,11,12},
                   {2,2,3,4,5,6,7,8,9,10,11,12},
                   {3,2,3,4,5,6,7,8,9,10,11,12},
                   {4,2,3,4,5,6,7,8,9,10,11,12},
                   {5,2,3,4,5,6,7,8,9,10,11,12}
                        };



  for (int i=0;i<5;i+=1)
  {
    for (int j=0;j<12;j+=1)
    {
      printf("%d  ",rainfall[i][j]);
      totayYearRain+=rainfall[i][j];
      rainfallByYear[i]+=rainfall[i][j];
    }
    printf("\n");
  }

  for (int k=0; k<12;k+=1)
  {
    for (int i=0;i<5;i+=1)
    {
      rainfallByMonth[k]+=rainfall[i][k];
    }
  }


  averageYearRain = (double)totayYearRain/5;
  printf("total rain = %u\n", totayYearRain);
  printf("average yearly rain = %.2f\n", averageYearRain);


  printf("Year\train\n");
  for (int i=0; i<5;i+=1)
  {
    printf("201%d\t%d\n",i, rainfallByYear[i]);
  }

  for (int k=0; k<12;k+=1)
  {
    rainfallByMonth[k]/=5;
    printf("Month %d rain %d\n", k+1, rainfallByMonth[k]);
  }







}
