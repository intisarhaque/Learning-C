#include <stdio.h>
#include <ctype.h> 

//reading character by character
int main(){
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    char ch;

    fp = fopen("file2.txt", "r");

    if(fp==NULL){
        perror("no file as file2.txt");
        return(-1);
    }
    //create temp file
    fp1 = fopen("filetemp.txt", "w");

    if(fp1==NULL){
        perror("cannot create file");
        return(-1);
    }

    while ((ch = fgetc(fp))!=EOF){
        if (islower(ch)){
            ch = ch-32;
           
        }
        fputc(ch, fp1);
        printf("%c", ch);
    }

    fclose(fp);
    fclose(fp1);


    rename("filetemp.txt", "file2.txt");
    // remove("filetemp.txt");

    fp = NULL;
    fp1 = NULL;
    return 0;
}