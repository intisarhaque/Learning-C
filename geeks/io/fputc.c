#include <stdio.h>


//reading character by character
int main(){
    FILE *fp = NULL;
    int c;
    char str[61];

    fp = fopen("file2.txt", "w+");

    if(fp==NULL){
        perror("no file as file1.txt");
        return(-1);
    }else{
        fprintf(fp, "%s %s %s %s %d", "hi", "my", "number", "is", 5353 );
    }


    fclose(fp);
    fp = NULL;
    return 0;
}

//