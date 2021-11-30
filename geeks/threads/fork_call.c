#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

/*
    - in multitasking OS need a way to create new processes
    - fork() system call is where a function creates a copy of itself
        - creates new process
        - defined in <unistd.h>//unixstandard.h
    - when a process calls a fork it is deemed the parent and new process is child
        - child has COPY of everything parent has but its in a separate address space (there's a flag to show which line it's on)
            - updating variable in one won't effect the other
    - fork() often used with exec() in order to start execution of a different program
    - typical use case is if you want to create a copy of itself
        - copy (child) calls exec system call to overlay itself with the other program
            - ceases execution of its former program in favour of the other
    - after fork called, both continue on line it was called at and runs in paralel
    - can distinguish parent from child using return of fork value (process ID)
    - pid = fork();
        - returned PID is of type pid_t defined in sys/types.h
        - PID is an integer
        - process can use getpid() to retreive the process ID
        - need to check value of PID return in next block of code
            - <0 means child creation unsuccessful
            - 0 to newly created child
            - >0 process ID of child process to parent
    - kill function to send signal to child

*/

#include <unistd.h>
#define MAX_COUNT 10
#define BUF_SIZE 100

void main(void){
    pid_t pid;
    char buf[BUF_SIZE];
    fork();
    pid = getpid();
    for (int i = 1; i<=MAX_COUNT; i++){
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i );
        //write system call instead of printf bc printf is buffered meaning it will group output of process together
        write(1, buf, strlen(buf));
    }
    return;
}