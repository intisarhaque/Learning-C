#include<stdio.h>

struct address
{
    int doorNumber;
    char roadName[20];
    char city[20];
    char postCode[20];
};

int main()
{
struct address myHouse = {20, "main street", "london", "e1 4ay"};

// Accessing members of point p1
printf ("Address:\n%d,\n%s,\n%s,\n%s", myHouse.doorNumber, myHouse.roadName,myHouse.city,myHouse.postCode);

return 0;
}
