#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertCase(FILE *fptr, const char *path){
    printf("%s\n", path);
    FILE *dest = NULL;
    char ch;
    dest = fopen("temp.txt", "w");
    if (dest == NULL){
        printf("cant create file");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }


    while((ch = fgetc(fptr))!=EOF){
        if (isupper(ch)){
            ch = tolower(ch);
        }else if (islower(ch)){
            ch = toupper(ch);
        }
        fputc(ch, dest);
    }

    fclose(fptr);
    fclose(dest);

    remove(path);
    rename("temp.txt", path);




}

//reading character by character
int main(int argc, char * argv[]){
    FILE *fptr = NULL;
    char path[100];
    printf("Enter path for file\n");
    scanf("%s", path);
    fptr = fopen(path, "r");
    if (fptr  ==NULL){
        fprintf(stderr, "cant open %s\n", path);
        exit(EXIT_FAILURE);
    }
    convertCase(fptr, path);
    


    return 0;
}