#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <dispatch/dispatch.h>
#define CONSUMERTHREADS 4
#define PRODUCERTHREADS 1
#define BUFFERSIZE 10


/*GLOBALS*/
int count = 0;
int db[10];
extern int errno;
dispatch_semaphore_t semaphoreRead;
dispatch_semaphore_t semaphoreWrite;
int writerAccess;
pthread_mutex_t lock1;
/*GLOBALS*/

void * consumer_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {


    }
    return (NULL);
}

void * producer_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {

    }
    
    return (NULL);
}

int main(){
    pthread_t thread_id[CONSUMERTHREADS];
    pthread_t thread_id2[PRODUCERTHREADS];
    int errnum;
    writerAccess = 0;
    semaphoreRead = dispatch_semaphore_create(4);
    semaphoreWrite = dispatch_semaphore_create(1);
    time_t t;
    srand((unsigned) time(&t));

    //create writer threads
    for (int i=0; i<PRODUCERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id2[i], NULL, &producer_function, (void*)arg);
    }
   

    //create reader threads
    for (int i=0; i<CONSUMERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id[i], NULL, &consumer_function, (void*)arg);
    }
    sleep(1);

    //join writer theads
    for (int j=0; j<PRODUCERTHREADS; j++){
        pthread_join(thread_id2[j], NULL);
    }
    //join reader theads
    for (int j=0; j<CONSUMERTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }



    dispatch_release(semaphoreRead);
    dispatch_release(semaphoreWrite);
    return 0;

}