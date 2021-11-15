#include <stdio.h>




int main(){
    char ch = '\0';
    int ch1 = 0;
    //ch = getc(stdin);// getc just takes in file. getchar only stdin
    //printf("read in character \n %c", ch);
    //printf("another char %c\n", getchar());
    while ((ch=getchar())!=EOF){
        printf("%c\n", ch);
    }




    return 0;



}