#include <stdio.h>

//reading character by character
int main(){
    FILE *fp = NULL;
    char str[61];
    char ch;

    fp = fopen("file2.txt", "r");

    if(fp==NULL){
        perror("no file as file2.txt");
        return(-1);
    }
    int counter = 0;
    int counter1 =0;
    // while (fgets(str,60,fp)!=NULL){
    //     counter +=1;
    //     printf("%s", str);
    // }
    while ((ch = fgetc(fp))!=EOF){
        printf("%c",ch );
        if (ch=='\n'){
            counter1 +=1;
        }
    }
    counter1 +=1;

    printf("\nnumber of lines in file2.txt is %d", counter1);
    fclose(fp);
    fp = NULL;
    return 0;
}