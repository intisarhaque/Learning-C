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
#include "headers/teacher.h"


int main(){
 
    scoreType_t a = Exam;
    char * typeofexam = getScoreType(a);
    //printf("scoretype is %s\n", typeofexam);
    teacher_t defaultTeacher = {.teacherName = "Unassigned", .salary=10000};
    teacher_t m = {.teacherName = "Mr Math", .salary=50000};
    teacher_t e = {.teacherName = "Miss book", .salary=235325};
    teacher_t s = {.teacherName = "Dr Octopus", .salary=345424};
    subject newSubject = createSubject("maths", Exam, defaultTeacher);
    subject newSubject1 = createSubject("english", Coursework, e);
    subject newSubject2 = createSubject("science", Practical, s);
    addSubject(&newSubject);
    addSubject(&newSubject1);
    addSubject(&newSubject2);
    setTeacherToSubject(&newSubject, &m);
    printSubjectList();
    whichTeacher("science");
    student st = createStudent("jonhamm", 9, subjects);
    printStudent(&st, subjects);
    subject newSubject3 = createSubject("PE", Practical, s);
    addSubject(&newSubject3);
    printSubjectList();
    printStudent(&st, subjects);
    setGrade(&newSubject1, &st, 50);
    printStudent(&st, subjects);


    return 0;

}



