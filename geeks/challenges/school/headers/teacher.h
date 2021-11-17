#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <stdlib.h>
#include "student.h"


struct teacher
{
    //int teacherId;
    char teacherName[15];
    int salary;
};

typedef struct teacher teacher_t;

#endif