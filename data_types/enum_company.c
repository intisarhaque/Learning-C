#include <stdio.h>

int main()
{
  enum company {GOOGLE, FACEBOOK=3, XEROX, YAHOO, EBAY, MICROSOFT};
  printf("%d \n%d \n%d\n", XEROX, GOOGLE, EBAY );
  enum company xerox = XEROX;
  enum company google = GOOGLE;
  enum company ebay = EBAY;
  printf("%d \n%d \n%d\n", xerox, google, ebay );


}
