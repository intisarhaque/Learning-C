#include <stdio.h>


//reading character by character
int main(){
    FILE *fp;
    int c;
    char str[61];

    fp = fopen("file.txt", "r");

    if(fp==NULL){
        perror("no file as file.txt");
        return(-1);
    }

    // //read single character
    // while((c=fgetc(fp))!=EOF){
    //     printf("%c-", c);
    // }

    //reads line by line
    if (fgets(str,60,fp)!=NULL){
        printf("%s", str);
    }

    fclose(fp);
    fp = NULL;
    return 0;
}

//