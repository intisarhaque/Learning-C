#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <dispatch/dispatch.h>
#define READERTHREADS 16

/*GLOBALS*/
extern int errno;
dispatch_semaphore_t semaphore1;
/*GLOBALS*/

//QUESTION: void * do_process()  vs void do_process()
void * thread_function(void *ptr){
    // dispatch_semaphore_wait(semaphore1, DISPATCH_TIME_FOREVER);
    // sleep(1);
    int message = *((int*)ptr);
    // printf("Thread number %ld: %d\n", pthread_self(), message);
    printf("%d waiting to log in...\n", message);
    dispatch_semaphore_wait(semaphore1, DISPATCH_TIME_FOREVER);
    printf("%d logged in\n", message);
    sleep(5);
    printf("%d logged out\n", message);
    dispatch_semaphore_signal(semaphore1);
    return (NULL);
}

int main(){
    pthread_t thread_id[READERTHREADS];
    int errnum;

    semaphore1 = dispatch_semaphore_create(10);
    errnum = errno;
    //printf("error %d", seminit);
    // fprintf(stderr, "Value of errno: %d\n", errno);
    // perror("Error printed by perror");
    // fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

    //create threads
    for (int i=0; i<READERTHREADS; i++){
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
    for (int j=0; j<READERTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }

    dispatch_release(semaphore1);
    return 0;

}