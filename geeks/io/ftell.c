#include <stdio.h>


//reading character by character
int main(){
    FILE *fp = NULL;
    int len;

    fp = fopen("file.txt", "r");

    if(fp==NULL){
        perror("no file as file1.txt");
        return(-1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    fp = NULL;

    printf("total size of file.txt = %d bytes",  len);
    return 0;
}

//