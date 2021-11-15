#include <stdio.h>




int main(){
    char ch;
    FILE *fp = NULL;
    if (fp = fopen("file1.txt", "rw"));

    ch = getc(fp);
    while (ch != EOF){
        putc(ch, stdout);
        ch = getc(fp);
    }

    fclose(fp);


    return 0;



}