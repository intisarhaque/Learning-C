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
struct address myHouse = {20, "main street", "London", "E1 4AY"};
struct address *myHouseMem = &myHouse;

// Accessing members of point p1
printf ("Address:\n%d %s,\n%s,\n%s", myHouse.doorNumber, myHouse.roadName,myHouse.city,myHouse.postCode);

return 0;
}
