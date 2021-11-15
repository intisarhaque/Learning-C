/*
    gets reads from STDIO into buffer until new line or EOF found.
    tkaes one argument, a pointer to where array of chars stores
    returns str on success or NULL on error/EOF
    char *gets(chat *str)
    dont use it??? doesn't have buffer overflow.
    use fgets or getchar

    fgets to read entire line of data from stream
    2 arguments, number of chars, and input stream
    char *fgets(char *buffer, int n, FILE *stream)
    buffer pointer to array where line that is read in will be stored
    n is max number of chars into buffer including null character
    stream is pointer to object where chars read from, file/stdio etc
    reads until /n or n-1 chars read in. 
    returns value of buffer if successful, null if failure or reading past EOF
    not recommended for performance reasons.
    dont use unless certain chars wont contain null character

*/
// #include <stdio.h>
// #include <string.h>
// int main(){
//     char buf[255];
//     int ch;
//     char *p = NULL;
//     if (fgets(buf, sizeof(buf), stdin)){ //reads all the way to line feed
//         p = strchr(buf, '\n');
//         if (p){
//             *p = '\0'; //if linefeed found set to null terminator
//         }
//     }
//     printf("Our buffer contains %s\n", buf);
// }

/*
    getline is preferred method for reading lines of text from stream upto and including \n
    ssize_t getline(char **buffer, size_t *size, FILE *stream);
    - first param is pointer to block allocated with malloc/calloc (type char**)
        - address of first char position where input string will be stored
        - will auto enlarge block of memory as needed (realloc)
        - will contain line read by getline when it returns
    - second param is pointer to a variable ot type size_t
        - specifies the size in bytes of block of memory pointed to by first parameter
        - address of variable that holds size of input buffer, another pointer
    - third param is stream from whcih to read the line
    
    if error then returns -1, else returns number of characters stored
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define __USE_GNU
#define  _XOPEN_SOURCE
#define _POSIX_C_SOURCE
#define _GNU_SOURCE

int main(){
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;
    buffer = (char *)malloc(bufsize*sizeof(char));
    if (buffer==NULL){
        exit(1);
    }
    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);
    printf("%zu characters were read\n", characters);
    printf("you typed %s \n", buffer);



}