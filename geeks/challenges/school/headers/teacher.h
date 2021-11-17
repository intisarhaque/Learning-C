#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "student.h"

struct student_college_detail
{
    int college_id;
    char college_name[50];
};
struct student_detail 
{
    int id;
    char name[20];
    float percentage;
    // structure within structure
    struct student_college_detail clg_data;
}stu_data;


struct teacher
{
    char teacherName[15];
    int salary;
};

typedef struct teacher teacher_t;




#endif