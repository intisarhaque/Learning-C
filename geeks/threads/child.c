#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>


void child()
{
	printf("child \n");
}
void parent()
{
    printf("parent\n");
}

int main()
{
	// pthread_t thread_id;//an integer used to identify the thread in the system
    pid_t _pid;
    _pid = fork();
    if (_pid==0){
        child();
    }else{
        parent();
    }
	printf("After Thread\n");
	exit(0);
}

