#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


// The function to be executed by all threads
void *myThreadFunction(void *vargp)//void pointer?
{
	// Store the value argument passed to this thread
	int *myid = (int *)vargp;//creating pointer after typecasting void pointer?

	// Print the argument, static and global variables
	printf("Thread ID: %d\n", *myid);//dereferencing void pointer
}

int main()
{
	int i;
    int NTHREAD = 4;
	pthread_t thread[NTHREAD];
    int *taskIDs[NTHREAD];

	for (i = 0; i < NTHREAD; i++){
        taskIDs[i] = (int *) malloc(sizeof(int));      
        *taskIDs[i] = i;
        pthread_create(&thread[i], NULL, myThreadFunction, taskIDs[i]);//all threads have the same id? what if &i
    }
    
	pthread_exit(NULL);
	return 0;
}
