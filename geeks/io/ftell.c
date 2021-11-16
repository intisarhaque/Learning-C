#include <stdio.h>


//reading character by character
int main(){
    FILE *fp = NULL;
    int len;

    fp = fopen("file1.txt", "r");

    if(fp==NULL){
        perror("no file as file1.txt");
        return(-1);
    }
    printf("%p \n", fp);
    fseek(fp, 0, SEEK_END);
    printf("%p \n", fp);
    len = ftell(fp);
    printf("%p \n", fp);
    fclose(fp);
    fp = NULL;

    printf("total size of file.txt = %d bytes",  len);
    return 0;
}

//