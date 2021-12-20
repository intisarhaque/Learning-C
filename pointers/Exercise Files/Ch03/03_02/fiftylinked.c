#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct intObj{
    int id;
    struct intObj* next;
};
struct intObj* head;
struct intObj* current;

void printStruct(struct intObj* temp){
    printf("%d, ", temp->id);
}

void addToHead(int x){
    
    current = (struct intObj* )malloc(sizeof(struct intObj));
    if (head==NULL){
        printf("list not instantialized");
        return;
    }
    current = head;
    struct intObj* temp = (struct intObj* )malloc(sizeof(struct intObj));
    if (temp==NULL){
        printf("No memory for temp in headadd");
        return;
    }
    temp->id=x;
    temp->next=current;
    head = temp;
    free(current);
}


//chekc if works
void addToTail(int randomNumber){
    // create a new block of merory that is a structure and copy the address of this block in current

    // 0x96    [id]
    // 0x97     [next] -> next = 0x43

    // 0x43 [id]
    // 0x44 [next]

    // 0x21[id] random value
    // 0x22 next random 
    // current = 0x21

    // curret = head
    // current = 0x96
    //but you need a variable that contain the address of the header, this variable is called pointer
    //current = struct intObj; // current contain -> 0x56 (new block of memory that you created)
    //int x = 2
    struct intObj* current = NULL;
    //check current 

    //probably don't need
    if (head==NULL){
        printf("list not instantialized");
        return;
    }
    //head address -> 0x96
    current = head;
    //current contain [0x96]
    struct intObj* newTail = (struct intObj* )malloc(sizeof(struct intObj));
    //    ==
    // struct intObj* newTail;
    // newTail = (struct intObj* )malloc(sizeof(struct intObj));
   
    if (newTail == NULL){
        printf("No memory for temp in tailadd");
        return;
    }
    while(current->next!=NULL){
        current = current->next;
    }
    //current should now be on current tail
    newTail->id=randomNumber;
    newTail->next=NULL;
    current->next=newTail;
}

void removeFromList(int x){
    if (head==NULL){
        printf("list not instantialized");
        return;
    }

    struct intObj* prev = NULL; //(struct intObj* )malloc(sizeof(struct intObj));
    //prev = 0
    // 0x43 addres of prev and cointain 0 
    // prev->      equivalent *prev    -> it will crash
    // 0x43 is just a pointer location of 32 bit that it can void* , int*, char*, struct hello *, all the pointers variable have the same size
    //*prev = struct intObj;
    // int *x;
    // int *y = (int *)malloc(sizeof(int));
    // *y = 10;
    // x = y;




    if (prev==NULL){
        printf("No memory for prev in remove");
        return;
    }
    while(head->id==x){
        //need to free the heads
        head = head->next;
    }
    current = head;
    prev = current;
    while(current!=NULL){
        if(current->id==x){
            //if tail
            if(current->next==NULL){
                prev->next=NULL;
                free(current);
                current = NULL;
            }else{
                //  DOESNT WORK
                //else if in middle 
                //current = 3
                current = current->next;
                //current = 4
                prev->next = current;
                //need to free the ditched
            }
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    free(prev);
    free(current);

}

void printList(){
    current = (struct intObj* )malloc(sizeof(struct intObj));
    if(current==NULL){
        printf("No space for current from print");
        return;
    }
    if (head==NULL){
        printf("list not instantialized");
        return;
    }
    current = head;

    while(current!=NULL){
        printStruct(current);
        current = current->next;
    }
    free(current);
    printf("\n");

}

void sortList(){
    struct intObj* prev = (struct intObj* )malloc(sizeof(struct intObj));
    if(prev==NULL){
        printf("No space for current from sort");
        return;
    }
    current = (struct intObj* )malloc(sizeof(struct intObj));
    if(current==NULL){
        printf("No space for current from print");
        return;
    }
    current=head->next;
    prev=head;
    while(prev->next!=NULL){
        while (current!=NULL){

        }
    }
    

}


int main(){
    time_t t;
    srand((unsigned) time(&t));
    head = (struct intObj*) malloc(sizeof(struct intObj*));
    if (head==NULL){
        printf("No memory for head");
        return 0;
    }
    head->id = 5;
    head->next = NULL;
    for(int i = 0; i<50; i+=1){
        int randNumber = (rand() % 5) + 1;
        addToTail(randNumber);
    }
    addToHead(1);
    addToHead(2);
    addToTail(4);
    addToHead(3);
    addToHead(4);
    addToTail(10);
    addToTail(4);
    addToTail(20);
    addToTail(12);
    addToTail(4);
    addToTail(4);
    addToHead(4);
    addToHead(4);
    addToHead(4);
    printList();
    removeFromList(4);
    printList();


    return 0;
}