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
#define SEM_NAME_1 "/sem_1"
#define SEM_NAME_2 "/sem_2"

/*GLOBALS*/
int db;
extern int errno;
// dispatch_semaphore_t semaphoreRead; //allows multiple access 
// dispatch_semaphore_t semaphoreWrite; //allows 1 access
int writerAccess; //
int readerCount;
pthread_mutex_t lock1;
sem_t *sem1;
sem_t *sem2;
/*GLOBALS*/

void * reader_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {
        while (writerAccess==1){
            sleep(1);
        }
        int sleepTime = (rand() % 4) + 1;
        printf("ThreadNum %d  sleeping for %d...\n", threadNum, sleepTime);
        sleep(sleepTime);
        //reader wakes up here and gets in regardless of writer function
        //dispatch_semaphore_wait(semaphoreRead, DISPATCH_TIME_FOREVER);
        sem_wait(sem1);
        sem_wait(sem2);
        readerCount +=1;
        sem_post(sem2);
        printf("ThreadNum %d reading db: %d\n", threadNum, db);

        //dispatch_semaphore_signal(semaphoreRead);
        sem_wait(sem2);
        printf("Reader count is %d \n", readerCount);
        readerCount -=1;
        sem_post(sem2);
        sem_post(sem1);
        // sem_getvalue(&sem1, &readerCount);
        
        sleep(1);

    }
    return (NULL);
}

void * writer_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {
        printf("Read phase *****\n");
        //dispatch_semaphore_wait(semaphoreWrite, DISPATCH_TIME_FOREVER); //sem_wait
        //sem_wait(sem2);
        writerAccess = 1;//signal to threads to deload and wait
        //check if semaphore read is  a
        int sleepTime = (rand() % 4) + 1;
        int randNumber = (rand() % 10) + 1;
        printf("writer function sleeping for %d\n", sleepTime);
        sleep(sleepTime);
        sem_wait(sem2);
        while(readerCount!=0){
            sem_post(sem2);
            sleep(0.1);
        }
        sem_post(sem2);
        printf("Writing phase &&&&&\n");
        db +=randNumber;
        printf("Writer writing to db %d\n", db);
        writerAccess = 0;
        sleep(1);
        //dispatch_semaphore_signal(semaphoreWrite);//sem_post
        //sem_post(sem2);
        //broadcast(condition)
    }
    
    return (NULL);
}

int main(){
    pthread_t thread_id[READERTHREADS];
    pthread_t thread_id2[WRITERTHREADS];

    int errnum;
    db = 0;
    writerAccess = 0;
    sem1 = sem_open(SEM_NAME_1, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 4);
    sem2 = sem_open(SEM_NAME_2, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
    // semaphoreRead = dispatch_semaphore_create(4);
    // semaphoreWrite = dispatch_semaphore_create(1);
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



    // dispatch_release(semaphoreRead);
    // dispatch_release(semaphoreWrite);
    return 0;

}