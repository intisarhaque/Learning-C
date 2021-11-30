/*
    pthread_self() gives current thread ID

    pthread_detach()
        - when a thread creatd one of its attributes defines whether it is joinable or detached
            - if NULL as second argument it is joinable
            - only threads created as joinable can be join()ed
            - detached cant be joined
        - 2 common cases when you want to detach
            - cancellation handler for pthread_join()
                - essential to have pthread_detach in order to detatch the thread pthread_join waiting on
            - to detach initial thread (desirable in processes that set up server threads)
        - can detach thread that was created as joinable

    pthread_attr_get/setstacksize(attr, stacksize)
        - POSIX doesn't dictate size of a threads stack
        - exceeding stack limit is often easy to do
        - safe/portable programs don't depend upon default stack limit
            - better to explicitly allocate enough stack for each thread

    pthread_equal(thread1, thread2)
        - if 2 ID's are different the 0 returned otherwise non-zero returned
        - dont use == to check

    pthread_once(once_control, init_routine)
        - initialization routine
        - once_contorl is a synchronization control structure that requries intialization prior to calling
            pthread_once
        - pthead_once_t once_control = PTHREAD_ONCE_INIT

    pthread_cancel(pthread_id)
        - sends cancellation request to thread ID
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h>

// //alter 25/38 to see differnece
// void *threadFn (void *arg){
//     pthread_detach(pthread_self);//main will not wait for thread to be done;
//     sleep(1);
//     printf("Thread Fn\n");
//     pthread_exit(NULL);
// }

// int main(int argc, char *argv[]){
//     pthread_t tid;
//     int ret = pthread_create(&tid, NULL, threadFn, NULL);
//     if (ret !=0){
//         perror("Thread creation error\n");
//         exit(1);
//     }
//     //pthread_join(tid, NULL);
//     printf("After thread created in main\n");
//     pthread_exit(NULL);
// }

pthread_attr_t attr;
void *dowork(void *threadid){
    long tid;
    size_t mystacksize;

    tid = (long)threadid;
    pthread_attr_getstacksize(&attr, &mystacksize);//size stored in latter
    printf("Thread %ld: with stacksize = %li bytes \n", tid, mystacksize);//should be 9000000

    pthread_exit(NULL);
}

int main(){
    pthread_t myThread;
    size_t stacksize;
    int myID;
    long t = 5;

    pthread_attr_init(&attr);//initalize attr global variable
    pthread_attr_getstacksize(&attr, &stacksize);//get stacksize for thread ID
    printf("default stack size is %li\n", stacksize);
    stacksize = 9000000;
    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);//set attr to 9MB
    //QUESTION: to verify if this works I want to print attr's attributes so how do i do that
    //QUESTION: steam-deck supports 8 thread multithreading. what does that really mean?
    printf("Creating thread with stacksize %li\n", stacksize);
    


    myID = pthread_create(&myThread, &attr, dowork, (void *) t);
    if (myID){
        printf("Error; return code from thread creation is %d\n",myID );
        exit(-1);
    }
    pthread_exit(NULL);


}