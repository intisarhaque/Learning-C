#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#define READERTHREADS 30
#define WRITERTHREADS 1


/*GLOBALS*/
int db;
int readerCount;
pthread_mutex_t writer;
pthread_mutex_t reader;

void * reader_function(void *ptr){
    while(1)
    {
        int threadNum = *((int*)ptr);
        //int sleepTime = (rand() % 4) + 1;
        //printf("ThreadNum %d  sleeping for %d...\n", threadNum, sleepTime);
        //sleep(1);

        pthread_mutex_lock(&reader);
        readerCount +=1;
        if (readerCount==1){
            pthread_mutex_lock(&writer);
        }
        pthread_mutex_unlock(&reader);


        printf("ThreadNum %d reading db: %d\n", threadNum, db);


        pthread_mutex_lock(&reader);
        readerCount -=1;
        if (readerCount==0){
            pthread_mutex_unlock(&writer);
        }
        pthread_mutex_unlock(&reader);
        

        
    }

    return(NULL);
}

void * writer_function(void *ptr){
    while(1)
    {
        int threadNum = *((int*)ptr);
        int randNumber = (rand() % 10) + 1; 
        int sleepTime = (rand() % 4) + 1;
        printf("writer function sleeping for %d\n", sleepTime);
        sleep(sleepTime);

        //printf("Writing phase &&&&&\n");

        pthread_mutex_lock(&writer);
        db +=randNumber;
        printf("Writer writing to db %d\n", db);
        pthread_mutex_unlock(&writer);
        //printf("Read phase *****\n");
    }
    return(NULL);
}




int main(){
    pthread_t thread_id[READERTHREADS];
    pthread_t thread_id2[WRITERTHREADS];
    pthread_mutex_init(&writer, NULL);
    pthread_mutex_init(&reader, NULL);

    db = 0;


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



    return 0;

}