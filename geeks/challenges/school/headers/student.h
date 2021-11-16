#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
void add(int a, int b)
{
    printf("Added value=%d\n", a + b);
}
void multiply(int a, int b)
{
    printf("Multiplied value is %d \n", a * b);
}
void subtract(int a, int b)
{
    printf("subtracted value is %d \n", a-b);
}
//extern subject subjects;

struct student
{
    char studentName[15];
    subject studentSubjects[10];
    //grade grades[10];
};