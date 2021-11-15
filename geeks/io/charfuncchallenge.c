#include <stdio.h>
#include <stdlib.h>

//reading character by character
int main(int argc, char * argv[]){
    FILE *fp = NULL;
    char ch;
    int counter1 = 0;
    printf("number of args is %d\n", argc);
    printf("%s\n", argv[1]); //0 is name of file
    int wrd = 1;
    int charctr = 1;
    if (argc == 1){
        fp = stdin;
    }else{
        if ((fp = fopen(argv[1], "r")) ==NULL){
            fprintf(stderr, "cant open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    while ((ch = fgetc(fp))!=EOF){
        printf("%c",ch );
        if (ch=='\n'){
            counter1 +=1;
        }
        if(ch==' '||ch=='\n') {
            wrd++;
        }
        else {
            charctr++;
        }
    }
    counter1 +=1;
    printf("\nnumber of lines %d", counter1);
    printf("\nThe number of words in the file are : %d\n",wrd);
    printf("The number of characters in the file is : %d\n\n",charctr);



    return 0;
}