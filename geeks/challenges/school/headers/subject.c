
#include <stdio.h>
#include <stdlib.h>

enum scoreType {Exam, Coursework, Practical};


struct subject
{
    char subjectTitle[15];
    char examType;
};

void test(){
    enum scoreType a = Exam;
    printf("scoretype is %d", a);

}

char* getScoreType(enum ScoreType type){
    switch(type){
        case Exam: return "Exam";
        case Coursework: return "Coursework";
        case Practical: return "Practical";
    }
}

