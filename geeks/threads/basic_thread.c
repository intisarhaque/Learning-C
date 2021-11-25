#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
	return NULL;
}

int main()
{
	pthread_t thread_id;//an integer used to identify the thread in the system
	printf("Before Thread\n");
    /*4 args: 
    pointer to thread_id; 
    specifies attributes; 
    name of function to be executed when thread created;
    pass arguments to myThreadfunctions*/
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
    /*equivalent of wait() for processes. 
     A call to pthread_join blocks the calling thread until the thread with 
     identifier equal to the first argument terminates.*/
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}


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
                - sockets
                    - communicate over a network between a client and server
                - signals
                    - comms between multiple processes by way of signalling
                    - source process will send a signal and destination process will handle
        - communication seen as cooperation. 2 types
            - parent child
            - between unrelate/separate processes
    






*/