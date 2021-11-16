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
*/

#include <stdio.h>
#include "headers/student.h"

int main(){
    add(4, 6);
  
    /*This calls add function written in myhead.h  
      and therefore no compilation error.*/
    multiply(5, 5);
  
    // Same for the multiply function in myhead.h
    printf("BYE!See you Soon");
    return 0;




}



