#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

#define NTHREADS 10

/*GLOBALS*/
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
/*GLOBALS*/

//QUESTION: void * do_process()  vs void do_process()
void * thread_function(){
    printf("Thread number %ld, counter is %d\n", pthread_self(), counter);
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
}


int main(){
    pthread_t thread_id[NTHREADS];

    int i, j;
    for (int i=0; i<NTHREADS; i++){
        pthread_create(&thread_id[i], NULL, &thread_function, NULL);
    }
    for (int j=0; j<NTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}