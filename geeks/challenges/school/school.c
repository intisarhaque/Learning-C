/*
    School Management Project:
    - The program must be written in C and must compile with gcc
    - The program should use a command line interface (CLI) to add new information
    - The CLI can be used to add students and the subjects they study
    - The CLI can be used to add teachers and the subject they teach (1 subject per teacher)
    - The CLI can be used to assign grades to students per subject
    - The CLI can be used to find which students study a specified subject
    - The CLI can be used to find which teacher teaches a specified subject
    - The CLI can be used to find the grades a specified student has achieved in a specified subject
    - [Bonus] The CLI can be used to find which teachers teach a specified student
    - [Bonus] The CLI can be used to find which students are taught by a specified teacher
    - [Bonus] Student/teacher data should be loaded from files when the program starts up

    - Should be able to search for different things:
        - what grade did X get
        - who teaches maths
        - who studies english
        - etc
        add libarries and make files
*/

#include <stdio.h>
#include "headers/student.h"//h files currently contain functions

//student.c to have the functions
//student.h to have the declarations > import this
#include "headers/subject.h"

int main(){
    add(4, 6);
    multiply(5, 5);
    subtract(20,10);
    test();
    printf("Cya\n");
    scoreType_t a = Exam;
    char * typeofexam = getScoreType(a);
    //printf("scoretype is %s\n", typeofexam);
    subject newSubject = createSubject("maths", Exam, "Mr. Glasses");
    subject newSubject1 = createSubject("english", Coursework, "Miss Book");
    subject newSubject2 = createSubject("science", Practical, "Dr. Octopus");
    //printSubject(&newSubject);
    //printf("---\n%s\n%s\n%s", newSubject.subjectTitle, newSubject.teacher, getScoreType(newSubject.examType));
    addSubject(&newSubject);
    addSubject(&newSubject1);
    addSubject(&newSubject2);
    printSubjectList();
    whichTeacher("english");




    return 0;

}



