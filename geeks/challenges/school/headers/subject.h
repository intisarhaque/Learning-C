#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <stdlib.h>

//comments here
typedef enum scoreType {Exam, Coursework, Practical} scoreType_t;
//comments here
void test();
//comments here
char* getScoreType(scoreType_t typea);


struct subject
{
    char subjectTitle[15];
    char examType;
};

void test(){
    scoreType_t a = Exam;
    printf("scoretype is %s\n", getScoreType(a));
}


char* getScoreType(scoreType_t typea){
    switch(typea){
        case Exam: return "Exam";
        case Coursework: return "Coursework";
        case Practical: return "Practical";
    }
}

#endif

/*
structs/enums/function prototype go in H
c will have all the function implementations

*/