/*
    3 synch mechanisms in pthread.h
        - mutex: locks, block access to variable by other threads
        - joins: make a thread wait till other complete
        - condition variables: a way to comm to other threads

    mutex basically a lock to synchronise access to resources
        - one thread can use the resource at a time using a "key" (maybe)
    
    typical mutex sequence:
        - create and initalize mutex var
        - several threads attempt to lock mutex
        - only one succeeds and that thread own smutex
        - thread owner performa soperations
        - owner unlocks mutex
        - another thread aquires mutex and repeats process
        - mutex destroyed

    when several threads compete for a mutex, the losers block at the call waiting
        - deadlock can occur when using a mutex lock; 
        - make sure threads aquite locks in agreed order

    creating muex
        - mutex variable must be decalared as pthread_mutex_t
            -   must be initialized/created before used
    2 ways to initalize mutex
        - statically when declared as default pthread mutex value
            - pthread_mutex_t lock = PTHREAD_MUTED_INITIALIZER;
        - dynamically calling a specific function (pthread_mutex_init()) 
            - int pthread_mutex_init(
                - pthread_mutex_t * mutex, //mutex_t variable to operate on as firs argument
                - const pthread_mutexattr_t *mutexattr); //attributes for mutex in second argument (or NULL)
                    - 3 attributes
                        - protocol: specifies protocll used to prevent priority inversions for mutex
                        - prioceiling: specifies priority ceiling of a mutex
                        - process-shared: specifies the process sharing of a mutex
    destroying mutex
        - pthread_mutex_destroy(mutex): function to free mutex object that is no longer needed
    locking
        - int pthread_mutex_lock(pthread_mutex_t *mutex)
            - used by a thread to aquire a lock on specified mutex variable
            - if mutex is already locked by another thread, this call will block the calling
              thread until mutex is unlocked
        - int pthread_mutex_trylock(pthread_mutex_t *mutex)
            - attempt to lock mutex but if already locked routine returns immediately with busy error code
            - useful in preventing deadlock conditions as in a priority-inversion situation
    unlocking
        - int pthread_mutex_unlock(pthread_mutex_t *mutex)
            - unlock mutex if called by owning thread
            - required to do after thread has completed its use of protected data for other threads to use it
            - error if: mutex already unlocked; mutex owned by another thread
    anytime global resource accessed by more than one thread it should be a mutex
        - above functions should be used to access "critical section" of code from other threads
        - upto programmer to ensure mutex works properly

    NAMED SEMAPHORE BEFORE READER/WRITERS

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

/*GLOBALS*/
pthread_mutex_t lock;//= PTHREAD_MUTEX_INITIALIZER;
int j = 0;
/*GLOBALS*/

//QUESTION: void * do_process()  vs void do_process()
void * do_process(){
    pthread_mutex_lock(&lock);
    /*no other thread can access this code*/
    int i = 0;
    j++;
    while (i<5){
        printf("%d", j);//QUESTION why does it wait for all prints before displaying on STDOUT?
        //can use fflush 
        sleep(1);
        i+=1;
    }
    printf("...Done\n");
    pthread_mutex_unlock(&lock);
    /*any other thread can access this code*/
}


int main(){
    int err = 0;
    pthread_t t1, t2;

    //dynamically make mutex
    if (pthread_mutex_init(&lock, NULL) !=0){
        printf("Mutex initalization failed");
        return 1;
    }

    j=0;

    //QUESTION changing this to reference or not doesnt alter
    pthread_create(&t1,NULL, &do_process, NULL);
    pthread_create(&t2,NULL, &do_process, NULL);

    //switch order
    pthread_join(t2, NULL);
    pthread_join(t1, NULL);
    

    return 0;
}