#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

#define NTHREADS 10

/*GLOBALS*/
int counter = 0;
//INITIALIZE MUTEX IDIOT
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_MUTEX_INITIALIZER;
/*GLOBALS*/
//even message first then odd

void * thread_function(void *ptr){
    int message = *((int*)ptr);
    pthread_mutex_lock(&lock1);
    counter++;
    printf("Thread number %ld\t Message is %d\t Modified counter to %d\n", pthread_self(), message, counter);
    printf("Thread number %ld\t Message is %d\t Read counter as %d\n", pthread_self(), message, counter);
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
    //sleep(3);
    //join theads
    for (int j=0; j<NTHREADS; j++){
        pthread_join(thread_id[j], NULL);
        //pthread_exit(&thread_id[j]);
    }

    printf("Final counter value: %d\n", counter);

    pthread_exit(NULL);
    
    return 0;
}