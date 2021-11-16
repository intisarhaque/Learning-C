#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <stdlib.h>


/*
datatypes start
*/
typedef enum scoreType {Exam, Coursework, Practical} scoreType_t;

struct subject
{
    char subjectTitle[15];
    scoreType_t examType;
    char teacher[15];

};
typedef struct subject subject;
/*
datatypes end 
*/

/*
function prototype start
*/
void test();
char* getScoreType(scoreType_t typea);
subject createSubject(char* subjectTitle, scoreType_t typea, char* teacher);
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


subject createSubject(char* subjectTitle, scoreType_t typea, char* teacher){
    printf("***\n%s\n%s\n%s", subjectTitle, teacher, getScoreType(typea));
    subject newSubject = {.subjectTitle=*subjectTitle, .examType=typea, .teacher=*teacher};
    printf("***\n%s\n%s\n%s", newSubject.subjectTitle, newSubject.teacher, getScoreType(newSubject.examType));
    return newSubject;
}

void printSubject(subject * subjectToPrint){
    printf("%s\n%s\n%s", *subjectToPrint->subjectTitle, *subjectToPrint->teacher, getScoreType(subjectToPrint->examType));
}


#endif
/*
structs/enums/function prototype go in H
c will have all the function implementations

*/