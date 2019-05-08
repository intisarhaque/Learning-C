#include <stdio.h>

#define OVERTIMEHOURS 40
#define BASETAXRATE 0.85
#define MIDTAXRATE 0.8
#define UPPERTAXRATE 0.75
int main()
{
  int payrate = 12;
  int overtimerate = 18;
  int hoursworked;
  int paybeforetax;
  double payaftertax;
  printf("How many hours did you work this week, moterhfucekr?\n");
  scanf("%d", &hoursworked);
  printf("You worked %d hours\n", hoursworked);
  if (hoursworked<=OVERTIMEHOURS){
    int basepay = hoursworked*payrate;
    paybeforetax = basepay;
  }else{
    int overtimehours  = hoursworked-OVERTIMEHOURS;
    int basepay = OVERTIMEHOURS*payrate;
    int overtimepay = overtimehours*overtimerate;
    paybeforetax = basepay+overtimepay;
  }
  printf("Your pay before tax is: %d\n", paybeforetax);

  if(paybeforetax<=300){
    payaftertax = (double)(paybeforetax*BASETAXRATE);
  }
  else if(paybeforetax<=450){
    double middletaxpay = (double)(paybeforetax-300)*MIDTAXRATE;
    double basetaxpay = (300*BASETAXRATE);
    payaftertax= basetaxpay+middletaxpay;
  }
  else{
    double uppertaxpay=(double)(paybeforetax-450)*UPPERTAXRATE;
    double middletaxpay = (double)150*MIDTAXRATE;
    double basetaxpay = 300*BASETAXRATE;
    payaftertax= basetaxpay+middletaxpay+uppertaxpay;
  }
  printf("Your pay after tax is: %.2f\n", payaftertax);

}
