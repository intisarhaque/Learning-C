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
//#define SEM_NAME_1 "/sem_1"
#define SEM_NAME_2 "/sem_2"

/*GLOBALS*/
int db;
int writerAccess; 
int readerCount;
//sem_t *sem1;
sem_t *sem2;
pthread_mutex_t mutex;
pthread_mutex_t mutex2;
pthread_cond_t cond;

void * reader_function(void *ptr){
    while(1)
    {
        int threadNum = *((int*)ptr);
        int sleepTime = (rand() % 4) + 1;
        //printf("ThreadNum %d  sleeping for %d...\n", threadNum, sleepTime);
        //sleep(1);
        while (writerAccess==1){
            sleep(1);
        }
        pthread_mutex_lock(&mutex2);

        readerCount +=1;

        pthread_mutex_unlock(&mutex2);


        printf("ThreadNum %d reading db: %d\n", threadNum, db);

        pthread_mutex_lock(&mutex2);

        readerCount -=1;

        pthread_mutex_unlock(&mutex2);
        
        if (readerCount==0){
            printf("reader signalling\n");
            pthread_cond_signal(&cond);
        }
        
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
        writerAccess=1;//signals readerdeload
        pthread_mutex_lock(&mutex);
        printf("Writing phase &&&&&\n");

        pthread_mutex_lock(&mutex2);
        while (readerCount!=0){
            printf("Writer waiting...");
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex2);

        db +=randNumber;
        printf("Writer writing to db %d\n", db);
        writerAccess=0;//signals reader starting
        pthread_mutex_unlock(&mutex);
        printf("Read phase *****\n");
    }
    return(NULL);
}




int main(){
    pthread_t thread_id[READERTHREADS];
    pthread_t thread_id2[WRITERTHREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_cond_init(&cond, NULL);

    int errnum;
    db = 0;
    writerAccess = 0;
    //sem1 = sem_open(SEM_NAME_1, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 4);
    sem2 = sem_open(SEM_NAME_2, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);

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