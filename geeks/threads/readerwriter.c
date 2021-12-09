#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <dispatch/dispatch.h>
#define READERTHREADS 4
#define WRITERTHREADS 1


/*GLOBALS*/
int db;
extern int errno;
dispatch_semaphore_t semaphoreRead;
dispatch_semaphore_t semaphoreWrite;
int writerAccess;
pthread_mutex_t lock1;
/*GLOBALS*/

void * reader_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {
        while (writerAccess==1){
            sleep(1);
            //dispatch_semaphore_wait(semaphoreWrite, DISPATCH_TIME_FOREVER);
        }
        int sleepTime = (rand() % 4) + 1;
        printf("ThreadNum %d  sleeping for %d...\n", threadNum, sleepTime);
        sleep(sleepTime);
        dispatch_semaphore_wait(semaphoreRead, DISPATCH_TIME_FOREVER);

        printf("ThreadNum %d reading db: %d\n", threadNum, db);

        dispatch_semaphore_signal(semaphoreRead);
        sleep(1);

    }
    return (NULL);
}

void * writer_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {
        printf("Read phase *****\n");
        dispatch_semaphore_wait(semaphoreWrite, DISPATCH_TIME_FOREVER);
        writerAccess = 1;//signal to threads to deload and wait
        int sleepTime = (rand() % 4) + 1;
        int randNumber = (rand() % 10) + 1;
        printf("writer function sleeping for %d\n", sleepTime);
        sleep(sleepTime);
        printf("Writing phase &&&&&\n");
        db +=randNumber;
        printf("Writer writing to db %d\n", db);
        writerAccess = 0;
        sleep(1);
        dispatch_semaphore_signal(semaphoreWrite);
    }
    
    return (NULL);
}

int main(){
    pthread_t thread_id[READERTHREADS];
    pthread_t thread_id2[WRITERTHREADS];
    int errnum;
    db = 0;
    writerAccess = 0;
    semaphoreRead = dispatch_semaphore_create(4);
    semaphoreWrite = dispatch_semaphore_create(1);
    time_t t;
    srand((unsigned) time(&t));

    //create writer threads
    for (int i=0; i<WRITERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id2[i], NULL, &writer_function, (void*)arg);
    }
   

    //create reader threads
    for (int i=0; i<READERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id[i], NULL, &reader_function, (void*)arg);
    }
    sleep(1);

    //join writer theads
    for (int j=0; j<WRITERTHREADS; j++){
        pthread_join(thread_id2[j], NULL);
    }
    //join reader theads
    for (int j=0; j<READERTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }



    dispatch_release(semaphoreRead);
    dispatch_release(semaphoreWrite);
    return 0;

}