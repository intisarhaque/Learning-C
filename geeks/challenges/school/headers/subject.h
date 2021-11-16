#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


/*
datatypes start
*/
typedef enum scoreType {Exam, Coursework, Practical} scoreType_t;

struct subject
{
    char subjectTitle[15];//char star or use memcopy
    scoreType_t examType;
    char teacher[15];
};
typedef struct subject subject;

subject subjects[10];    
int subjectTracker = 0;//eventually static instead of global when in C
/*
datatypes end 
*/

/*
function prototype start
*/
void test();
char* getScoreType(scoreType_t typea);
subject createSubject(char* subjectTitle, scoreType_t typea, char* teacher);
void printSubjectList();
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

subject createSubject(char subjectTitleGiven[15], scoreType_t typea, char teacherGiven[15]){
    //printf("***\n%s\n%s\n%s", subjectTitle, teacher, getScoreType(typea));
    subject newSubject;// = {memcpy(subjectTitle,subjectTitle, 15), .examType=typea, .teacher=*teacher};//currently deferencing and shouldnt be
    memcpy(newSubject.subjectTitle, subjectTitleGiven, 15);
    memcpy(newSubject.teacher, teacherGiven, 15);
    newSubject.examType = typea;
    //printf("***\n%s\n%s\n%s", newSubject.subjectTitle, newSubject.teacher, getScoreType(newSubject.examType));
    return newSubject;
}

void printSubject(subject * subjectToPrint){
    //check pointer
    //subject c = *subjectToPrint;
    printf("subject: %s\nteacher: %s\nexam type: %s\n", subjectToPrint->subjectTitle, subjectToPrint->teacher, getScoreType(subjectToPrint->examType));
}

void addSubject(subject * subjectToAdd){
    //check pointer -> if error print to console
    subjects[subjectTracker] = *subjectToAdd;
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
        subject temp = subjects[i];
        printSubject(&temp);
    }
}

void whichTeacher(char* subjectTitleGiven){
    int i;
    for (i = 0; i<subjectTracker; i+=1){
        subject temp = subjects[i];
        if (!strcmp(temp.subjectTitle, subjectTitleGiven)){
            printf("match found %s\n", temp.teacher);
        }

    }
}


#endif
/*
structs/enums/function prototype go in H
c will have all the function implementations
*/

