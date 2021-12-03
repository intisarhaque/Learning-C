#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

#define NTHREADS 10

/*GLOBALS*/
int counter = 0;
/*GLOBALS*/

//QUESTION: void * do_process()  vs void do_process()
void * thread_function(void *ptr){
    int message = *((int*)ptr);
    //sleep(message);
    counter++;
    //QUESTION why does modify sometimes print same number? 
    printf("Thread number %ld\t Message is %d\t Modified counter to %d\n", pthread_self(), message, counter);
    printf("Thread number %ld\t Message is %d\t Read counter as %d\n", pthread_self(), message, counter);
    

    return (NULL);
}


int main(){
    pthread_t thread_id[NTHREADS];

    int i, j;

    //create threads
    for (int i=0; i<NTHREADS; i++){
        //QUESTION why have to do this?
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        //QUESTION why doesn't it work if just i
        pthread_create(&thread_id[i], NULL, &thread_function, (void*)arg);
    }
    sleep(3);
    //join theads
    for (int j=0; j<NTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }

    printf("Final counter value: %d\n", counter);

    //QUESTION what is this doing now
    pthread_exit(NULL);
    
    return 0;
}