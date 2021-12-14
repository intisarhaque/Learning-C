#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <dispatch/dispatch.h>
#include <time.h> 
#define CONSUMERTHREADS 6
#define PRODUCERTHREADS 6
#define BUFFERSIZE 10


/*GLOBALS*/
int count = 0;
extern int errno;
pthread_mutex_t lock1;
pthread_cond_t cond1;
pthread_cond_t cond2;
/*GLOBALS*/


/*LINKED LIST*/
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList(int threadNum) {
   struct node *ptr = head;
   printf("%d: \n[ ", threadNum);
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]\n");
}

void printCount(){
    printf(" count is %d\n", count);
}


//is list empty
bool isEmpty() {
   return head == NULL;
}


int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//insert link at the first location
void insertFirst(int data) {
    //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));

    printf("producing %d\n", data);
    link->data = data;

    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
}

//delete first item
struct node* deleteTail() {
    //save reference to first link
    struct node *tempLink = head;

    if(tempLink->next==NULL){
        printf("Consuming %d\n", head->data);
        head=NULL;
        return NULL;
    }

    //travel to secondlast link
    while(tempLink->next->next != NULL){
        tempLink = tempLink->next;
    }

    //free last node
    printf("Consuming %d\n", tempLink->next->data);
    free(tempLink->next);

    //make second last link point to null
    tempLink->next=NULL;

    

    //return new tail
    return tempLink;

}



void * consumer_function(void *ptr){
    int threadNum = *((int*)ptr);
    sleep(2);
    while(1)
    {
        //printf("%d: contest\n", threadNum);
        pthread_mutex_lock(&lock1);
        //printf("%d: connotwait\n", threadNum);


        while(count<1){
            //printf("%d: contest2\n", threadNum);
            pthread_cond_wait(&cond1, &lock1);
        }



        //printf("%d: conthread", threadNum);
        printList(threadNum);
        deleteTail();
        count-=1;
        printf("%d: count from consumer %d\n", threadNum, count);

        if (count==2){
            pthread_cond_broadcast(&cond2);
        }


        pthread_mutex_unlock(&lock1);
        sleep(2);
    }
    return (NULL);
}

void * producer_function(void *ptr){
    int threadNum = *((int*)ptr);
    while(1)
    {   
        //printf("%d: prodtest\n", threadNum);
        int randNumber = (rand() % 10) + 1;
        pthread_mutex_lock(&lock1);
        while(count>9){
            //printf("%d: prodtest2\n", threadNum);
            pthread_cond_wait(&cond2, &lock1);
        }


        //printf("%d: prodnotwait\n", threadNum);
        insertFirst(randNumber);
        count+=1;
        printf("%d: count from producer %d\n", threadNum, count);



        if (count==1){
            pthread_cond_broadcast(&cond1);
        }
        pthread_mutex_unlock(&lock1);
        sleep(2);
    }
    
    return (NULL);
}


int main(){
    pthread_t thread_id[CONSUMERTHREADS];
    pthread_t thread_id2[PRODUCERTHREADS];
    pthread_mutex_init(&lock1, NULL);
    pthread_cond_init(&cond1, NULL);
    pthread_cond_init(&cond2, NULL);

    time_t t;
    srand((unsigned) time(&t));


    //create writer threads 
    for (int i=0; i<PRODUCERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id2[i], NULL, &producer_function, (void*)arg);
    }
   

    //create reader threads
    for (int i=0; i<CONSUMERTHREADS; i++){
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&thread_id[i], NULL, &consumer_function, (void*)arg);
    }
    sleep(1);

    //join writer theads
    for (int j=0; j<PRODUCERTHREADS; j++){
        pthread_join(thread_id2[j], NULL);
    }
    //join reader theads
    for (int j=0; j<CONSUMERTHREADS; j++){
        pthread_join(thread_id[j], NULL);
    }
    printCount();

    return 0;

}