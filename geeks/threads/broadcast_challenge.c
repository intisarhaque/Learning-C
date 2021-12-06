#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

#define NTHREADS 20

/*GLOBALS*/
int counter = 0;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;
/*GLOBALS*/


void * thread_function(void *ptr){
    int message = *((int*)ptr);

    pthread_mutex_lock(&lock1);
    if ((message%2)==0){      
        counter++;
    }
    else if ((message%2)!=0){
        //need if statement because some odd threads get to this bit after the broadcast
        if (counter<(NTHREADS/2)){
            printf("Thread %d waiting...\n", message);
            pthread_cond_wait(&condition_cond, &lock1);
        }
        counter++;
    }
    printf("Thread number %ld\t Message is %d\t Modified counter to %d\n", pthread_self(), message, counter);
    printf("Thread number %ld\t Message is %d\t Read counter as %d\n", pthread_self(), message, counter);
    if(counter==(NTHREADS/2)){
        printf("Now broadcasting...\n");
        pthread_cond_broadcast(&condition_cond);
    }
    pthread_mutex_unlock(&lock1);

    return (NULL);
}


int main(){
    pthread_t thread_id[NTHREADS];
    int i, j;

    //create threads
    for (int i=0; i<NTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id[i], NULL, &thread_function, (void*)arg);
    }

    sleep(1);

    //join theads
    for (int j=0; j<NTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }

    printf("Final counter value: %d\n", counter);
    pthread_exit(NULL);
    
    return 0;
}