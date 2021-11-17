#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "student.h"
#include "teacher.h"


/*
datatypes start
*/
typedef enum scoreType {Exam, Coursework, Practical} scoreType_t;

struct subjecta
{
    char subjectTitle[15];//char star or use memcopy
    scoreType_t examType;
    teacher_t teacher;
    //int modulecode;
    //Student students[30];//list of pointers to structures
    //char teacher[15];
};
typedef struct subjecta subject;

subject *subjects[10];//can be malloced because it is persistent
int subjectTracker = 0;//eventually static instead of global when in C
/*
datatypes end 
*/

/*
function prototype start
*/
void test();
char* getScoreType(scoreType_t typea);
subject createSubject(char subjectTitleGiven[15], scoreType_t typea, teacher_t teacherGiven);
void printSubjectList();
void whichTeacher(char* subjectTitleGiven);
/*
function prototype end
*/

void test(){
    scoreType_t a = Exam;
}
char* getScoreType(scoreType_t typea){
    switch(typea){
        case Exam: return "Exam";
        case Coursework: return "Coursework";
        case Practical: return "Practical";
    }
}

subject createSubject(char subjectTitleGiven[15], scoreType_t typea, teacher_t teacherGiven){
    subject newSubject;
    memcpy(newSubject.subjectTitle, subjectTitleGiven, 15);
    newSubject.teacher  = teacherGiven;
    newSubject.examType = typea;
    return newSubject;
}

void printSubject(subject * subjectToPrint){
    //check pointer
    //subject c = *subjectToPrint;
    printf("subject: %s\nteacher: %s\nexam type: %s\n", subjectToPrint->subjectTitle, subjectToPrint->teacher.teacherName, getScoreType(subjectToPrint->examType));
}

void addSubject(subject * subjectToAdd){
    //check pointer -> if error print to console
    subjects[subjectTracker] = subjectToAdd; //was adding value instead of reference
    subjectTracker +=1;
    printf("subject tracker is %d\n", subjectTracker);
}

void setSubjectTracker(int totalCurrentSubjects){
    subjectTracker = totalCurrentSubjects;
}

void printSubjectList(){
    int i;
    for (i = 0; i<subjectTracker; i+=1){
        printf("Subject %d\n", i+1);
        subject temp = *subjects[i];
        printSubject(&temp);
    }
}

void setTeacherToSubject(subject * subjectToAdd, teacher_t * TeacherToAdd){
    subjectToAdd->teacher=*TeacherToAdd;
}

void whichTeacher(char* subjectTitleGiven){
    int i;
    for (i = 0; i<subjectTracker; i+=1){
        subject temp = *subjects[i];
        if (!strcmp(temp.subjectTitle, subjectTitleGiven)){
            printf("match found %s\n", temp.teacher.teacherName);
        }
    }
}

// void addStudentToSubject(student * studentToAdd){
    
// }


#endif
/*
structs/enums/function prototype go in H
c will have all the function implementations
*/

