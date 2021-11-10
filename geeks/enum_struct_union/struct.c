#include<stdio.h>

typedef struct address
{
    int doorNumber;
    char roadName[20];
    char *city;
    char postCode[20];
};
typedef struct address address;//why this?

address copyStruct(address * toCopy){
    struct address c = *toCopy;
    c.doorNumber = 100;
    c.city = "manchesterwegewgwg";
    return c;
}

int main()
{
    struct address myHouse = {20, "main street", "london", "e1 4ay"};
    address myNewHouse = {.doorNumber=25,.roadName="big street", .city="manchester", .postCode="m4 5ns"};
    myNewHouse.doorNumber = 40;
    address a[2];
    a[0] = myHouse;
    a[1] = myNewHouse;
    // Accessing members of point p1
    //printf ("Address:\n%d,\n%s,\n%s,\n%s\n", a[0].doorNumber, myHouse.roadName,myHouse.city,myHouse.postCode);
    //printf ("Address:\n%d,\n%s,\n%s,\n%s\n", myNewHouse.doorNumber, myNewHouse.roadName,myNewHouse.city,myNewHouse.postCode);

    //pointer to struct variable
    //contains variable of type struct address
    struct address *ptr = &myHouse;
    //printf("%d", ptr->doorNumber);
    //ptr>doorNumber = (*ptr).doorNumber
    //can replace ptr with (*&myHouse).doorNumber
    //which equals myHouse.doorNumber (accessing member of )
    //printf("%d", *ptr.doorNumber);

    address copied = copyStruct(ptr);
    printf("original door number is %d\n", myHouse.doorNumber);
    printf("original door number is %s\n", myHouse.city);
    printf("new door number is %d\n", copied.doorNumber);
    printf("new door number is %s\n", copied.city);


    return 0;

}
