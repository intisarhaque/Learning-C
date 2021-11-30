/*
    pthread_create allows sending one argument
    to pass more than one send an argument and pass pointer to structure
    all arguments must be cast to (void *)
ß

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h>

void *print_message_function( void *ptr);

int main(){
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    /*creating threads that will execute function*/
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    /*wait until threads are complete before continuing*/
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Thread 1 returns %d\n", iret1);
    printf("Thread 2 returns %d\n", iret2);
    pthread_exit(NULL);
    //exit(0);

//e21110071807
//print label. hermes picking up tomorrow 8am-8pm    

}

void *print_message_function( void *ptr){
    char *message;
    //typecast void pointer into string
    message = (char *)ptr;
    printf("%s\n", message);
}
