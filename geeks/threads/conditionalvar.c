/*
    conditional variables another way for threads to synchronize without having to constantly poll
    like in a while loop.
    conditional cvariable allows suspending of execution and relenquish processor until a certain condition is true
        - used with approprtiate function for waiting and later, thread continuation.
    conditional variable must always be associated with mutex
        - to avoid deadlock by one thread waiting for another thread to signal before first thread starts waiting
            - thread will be perpetually waiting for signal that is never sent
    any mutex can be used with condition variable
        - no link between mutex and condition variable

    condition variable like a pillow.
        - thread can fall asleep on it and be woken from it
        - for example
            - tommy the thread wants to access shared information
                - he has the lock but information not ready to view yet
                - he decides to sleep on a nearby conditional variable until another thread updated
                  shared information and woke him up
            - jon the thread finally updates shared information while tommy asleep on conditional var
                - jon noticed tommy asleep, so signal tommy to wake up off conditional variables
                - jon went on his way and tommy can now place with information
        - above analogy missing that tommy initially had lock. and had to release lock before jon can edit
            - when tommy wakes up he needs the lock back
            - conditional var semantics guarantee that thread sleeping on conditional var not awake until
                - receieves wake up signal
                - can reaquire lock it had before sleeping
    
    cond variable: tpye pthread_cond_t
        - initialized before use
        - creating
            - dynamically created: pthread_cond_init(condition, attr) 
            - statically created: pthread_cond_t cond = PTHREAD_COND_INITLIAZER
        - desroying 
            - pthread_cond_destroy(condition)
        - waiting
            - pthread_cond_wait(pthead_cond_t *cond, pthear_mutex_t *mutex)
                - puts caller thread to sleep on conditioan variable and releases mutex lock
                    - guarantees when subsequent line executed after caller awaken, caller has lock
                    - thread that waits, releases mutex
                         - puts itself on wait queue associated with condition variable
                         - when thread woken up, aquirex mutex again.
            - pthread_cond_timewait
                - limit on how long it will block
        - waiting thread based on condition
            - pthread_cond_signal(pthread_cond_t *cond)
                - notify one thread waiting on condition variable
            - pthread_cond_broadcast(pthread_cond_t *cond)
                 - wake up all threads blocked by specified condition variable
        - for all functions, caller must hold lock associated with cond variable

*/


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_MUTEX_INITIALIZER;


int count = 0;
#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

void *functionCount1(){
    for(;;){
        pthread_mutex_lock(&condition_mutex); //enter conditional mutex

        //wait for count between HALT1 and HALT2
        while (count>=COUNT_HALT1 && count<=COUNT_HALT2){
            pthread_cond_wait(&condition_cond, &condition_mutex);//release mutex lock until called
            //get cond_mutex lock back
        }

        pthread_mutex_unlock(&condition_mutex); //unlock conditional mutex

        pthread_mutex_lock(&count_mutex);//enter counter mutex
        count ++;
        printf("Counter value from function1 is %d\n", count);
        pthread_mutex_unlock(&count_mutex);//release counter mutex

        if (count >=COUNT_DONE){
            return(NULL);
        }
    }
}

void *functionCount2(){
    for (;;){
        pthread_mutex_lock(&condition_mutex);

        if(count<COUNT_HALT1 && count>COUNT_HALT2){
            //when you send signal need to ensure the other thread is in waiting state
            pthread_cond_signal(&condition_cond);
        }
        pthread_mutex_unlock(&condition_mutex);

        pthread_mutex_lock(&count_mutex);
        count ++;
        printf("Counter value from function2 is %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        if (count >=COUNT_DONE){
            return(NULL);
        }
    }

}


int main(){
    pthread_t t1, t2;
    pthread_create(&t1,NULL, &functionCount1, NULL);
    pthread_create(&t2,NULL, &functionCount2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    exit(0);
}