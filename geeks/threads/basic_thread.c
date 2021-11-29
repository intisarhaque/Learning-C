/*

    process does one thing at a time. can switch between tasks. but what if theres a blockage
    main() is single path of execution
    each process has its own address space and one thread of control
    can have multiple processes executing same program but each copy has its own address space
    and executes it independantly of other copies.
    organised heirarchically, each process has parent process 
    called parent child process and child inherits attributes from parent

    program does a system call which is request for service of the kernal (brain of OS)
    - generally something only kernel has privelege to do
    - kernal calls
    
    functions in GNU C library do do virtually everything that system calls do
    - they make system calls (such as creating/reading files)

    each process has a unique integer called a PID

    process can be of two types:
    - independent
        - not effected by execution of other processes
        - doesn't interact with other programs
    - co-operating
        - affected by other executing processes
        - can be used for increasing computation speed, convenience, modularity
    - good if different programmes can communicate with one another
        - but difficult because they share address space
        - therefor requires interprocess communication (IPC)
            - can communicate in many ways:
                - pipes (anonymous; same process)
                    - unidirectional comms(half duplex)
                - named pipes (different processes, FIFO)
                    - bidirectional (full duplex)
                - message queues
                    - processes communicate with eachother using messages in a queue
                - shared memory
                    - communicateween through shares piece of memory
                    - share same address space. ß
                    - create segment in memory other processes can access.
                    - write into queue; read from queue; perform operations on queue.
                - sockets
                    - communicate over a network between a client and server
                - signals
                    - comms between multiple processes by way of signalling
                    - source process will send a signal and destination process will handle
        - communication seen as cooperation. 2 types
            - parent child
            - between unrelate/separate processes
    
    creating process for each task not easy. Don't want processes for multiple tasks.
    threads divide a single process into sub-runnable chunks
        - separate path of execution
        - can be scheduled independantly of its larger program.
        - threads have same address space so can share memory. (global variables changed)
        - each thread can have its own path and run in parralel
        - less overheard than forking; faster context switching; faster termination
        - thread synchronisation is an issue (if they effect same variable at same time)
        - POSIX threads (pthreads) are the standard

    pthread functions
    can be grouped in 3 categories
        - thread management
            - works directly on threads: creating, detaching, joining, etc
            - set/query thread attributes: joinable, scheduling, etc
        - synchronizastion
            - manages read/write locks and barriers, deals with sync
            - mutex functions for creating, destroying, locking, and unlocking mutexes (mutual exclusion)
                - to ensure 2 resources dont access data at same time
        - condition variables
            - address communication between threads that share a mutex
            - based upon programmer specified conditions

    operations to perform on threads:
        - thread creation, termination, synchronization, scheduling, data management, process interaction

    creating a thread:
        - threads not forked but created with starting function as entry point
        - 3 functions: pthread_create, pthread_exit, pthread_join
    
    pthread_create():
        - called to create a new thread and make it executable
        - all threads must be explicitly created
        - no hierarchy or dependancy
        - threads are peers; can create other threads
        - 4 arguments in int pthread_create(
            pthread_t *thread, 
                - integer used to identify thread in system
                - upon completion stores ID of created thread in the location referenced by thread
            const pthread_attr_t *attr,
                - specifies thead attributes objects (or NULL)
                - examples: detached state, scheduling policy, scope, stack address, stack size
            void *(*start_routine)(*void),
                 - name of function (via function pointer) that thread will execute once created
            void *arg)
                - pass arguments to function
                - pointer cast of type void
                - NULL if no arguments
                - struct if multiple
    
    pthread_join()
        - useful to identify when thread completed or exited
        - like the wait() call
        - used when you want to wait for a thread to finish 
            - link current thread process to another thread
            - thread calling routine may launch multiple threads then wait for them to finish to get results
        - blocks calling thread until thread with identifier equal to first argument terminates 
        - makes program stop in order to wait for end of selected thread
        - typically only called by main() but other threads can also join eachother
        - all threads auto joined when main() terminates 
        - recieves return value of thread functions and stores in void pointer variable
        - 2 arguments in int pthread_join(
                - pthread_t thread, 
                    - thread ID of thread you're waiting for 
                - void **value_ptr)
                    - if not NULL, value is passed to pthread_exit()
    
    pthread_exit()
        - threads can be terminated in number of ways
            - explicitly calling pthread_exit
            - letting thread function return
            - call to function exit which will terminate process including any threads
        - typically called after thread has completed its work
        - not explicitally required to call but good practise to incase you need to return data
        - void pthread_exit(
                - void *value_ptr)
                    - makes value_ptr available to any successful join with terminating thread
        - sometimes desirable for thread not to terminate 
            - solved by placing thread code in an infinitely loop using condtional variables    

*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.



// A normal C function that is executed as a thread when its name is specified in pthread_create()
void * hello_fun(){
    printf("Hello World\n");
    return NULL;
}

int main(int argc, char * argv[]){

    //an integer used to identify the thread in the system
    pthread_t thread = 0;

    /* 4 args: 
    pointer to thread_id; 
    specifies attributes; 
    name of function to be executed when thread created;
    pass arguments to myThreadfunctions */
    pthread_create(&thread, NULL, hello_fun, NULL);

    /* will wait till thread is finished
    will block main from completing till thread finishes */
    pthread_join(thread, NULL);


    /*equivalent of wait() for processes. 
    A call to pthread_join blocks the calling thread until the thread with 
    identifier equal to the first argument terminates.
    If no join then thread created, main exits and no time for thread function to run*/
    pthread_exit(NULL);
    return 0;
}