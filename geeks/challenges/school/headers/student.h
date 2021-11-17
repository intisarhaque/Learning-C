#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"
#include "subject.h"

struct studenta
{
    //int studentid;
    char studentName[15];
    int year;
    int grades[10]; //using malloc later for flexible subject
};
typedef struct studenta student;
//listofstudents


void printStudent(student * studentToPrint, subject *subjects[10]){
    printf("name: %s\nyear: %d\n", studentToPrint->studentName, studentToPrint->year);
    printf("Grades\n");
    int i;
    for (int i =0; i<subjectTracker; i+=1){
        printf("%s: %d\n", subjects[i]->subjectTitle, studentToPrint->grades[i]);
    }

}

//currently makes 10 grades despite only 1 subject
student createStudent(char name[15], int year, subject *subjects[10]){
    student newStudent = { .grades={0}, .year=year};
    memcpy(newStudent.studentName, name, 15);
    return newStudent;
}

void setGrade(subject * subjectToGrade, student * studentToGrade, int grade){
    printf(" ");
}


#endif