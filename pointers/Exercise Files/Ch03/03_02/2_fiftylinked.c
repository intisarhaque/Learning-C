#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct intObj{
    int id;
    struct intObj* next;
}intObj_t;
//no global head

void printStruct(intObj_t* node){
    printf("%d, ", node->id);
}

void printList(intObj_t* head){
    if(head==NULL){
        printf("List not instantialized");
        return;
    }
    intObj_t* iterator = (intObj_t* )malloc(sizeof(intObj_t*));//just an address that points to a node
    if(iterator==NULL){
        printf("No space to iterate");
        return;
    }
    iterator = head;
    while(iterator!=NULL){
        printStruct(iterator);
        iterator = iterator->next;
    }
    printf("\n");
    free(iterator);
}

void addToHead(int id, intObj_t **head){ 
    if ((*head)->id==0){//null
        (*(*head)).id = id;
        (*head)->next = NULL;
    }
    else{
        intObj_t* newHead = (intObj_t* )malloc(sizeof(intObj_t));//memory for new node
        if (newHead==NULL){
            printf("No memory for new node in head");
            return;
        }
        newHead->id=id;
        newHead->next=*head;
        *head=newHead;
    }
}

void addToTail(int id, intObj_t **head){ 
    if ((*head)->id==0){//null
        (*(*head)).id = id;
        (*head)->next = NULL;
    }
    else{
        intObj_t* newTail = (intObj_t* )malloc(sizeof(intObj_t));//memory for new node
        if (newTail==NULL){
            printf("No memory for new node in tail");
            return;
        }
        intObj_t** iterator = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
        if(iterator==NULL){
            printf("No space to iterate");
            return;
        }
        *iterator = *head;//address of iterator points to address of head
        while((*iterator)->next!=NULL){
            *iterator = (*iterator)->next;
        }//iterator now at the tail
        newTail->id=id;
        newTail->next=NULL;
        (*iterator)->next=newTail;
        free(iterator);

    }
    
}


void removeNode(int idToRemove, intObj_t **head){
    if ((*head)->id==0){//null
        printf("List not instantialized to remove");
    }
    //dont
    intObj_t** iterator = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    intObj_t** prev = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    intObj_t** temp = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    if(iterator==NULL || prev==NULL){
        printf("No space to iterate from remove");
        return;
    }
    //clear heads of ID;
    while((*head)->id==idToRemove){
        *iterator = *head;
        *head = (*head)->next;
        free(*iterator);
    }
    *iterator = *head;
    *prev = *head;
    while (*iterator!=NULL){
        
        // printStruct(*iterator);
        // (*iterator) = (*iterator)->next;
        if ((*iterator)->id==idToRemove){
            if ((*iterator)->next==NULL){
                (*prev)->next=NULL;
                free(*iterator);//free last node
                break;
            }else{
                (*prev)->next=(*iterator)->next;
                *temp = *iterator;
                free(*temp);
                *iterator = (*iterator)->next;
            }
        }else{
            *prev = *iterator;
            *iterator = (*iterator)->next;
        }
    }
    free(temp);
    free(iterator);
    free(prev);
}

void swapPointers(intObj_t **left, intObj_t **right){
    intObj_t** temp = (intObj_t** )malloc(sizeof(intObj_t*));
    // printf("a\n");
    // *temp = (*right)->next;
    // printf("c\n");
    // (*left)->next = *temp;
    // printf("b\n");
    // (*right)->next = *left;
    // printf("h\n");
    free(temp);
}

void sortList(intObj_t **head){
    if (*head==NULL){
        printf("list not instantialized to sort");
        return;
    }
    intObj_t** iterator = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    int sorted = 0;
    if(iterator==NULL){
        printf("No space to iterate");
        return;
    }
    *iterator = *head;
    while (sorted==0){
        while((*iterator)->next!=NULL){
            if ((*iterator)->id < (*iterator)->next->id){
                //swapPointers();
            }

            *iterator = (*iterator)->next;
        }
        *iterator = *head;
    }


    //swapPointers(&((*head)->next), &((*head)->next->next));
    

}



int main(){
    time_t t;
    srand((unsigned) time(&t));
    intObj_t* head = (intObj_t*) malloc(sizeof(intObj_t*));
    if (head==NULL){
        printf("No memory for head");
        return 0;
    }

    for(int i = 0; i<50; i+=1){
        int randNumber = (rand() % 5) + 1;
        addToHead(randNumber, &head);
    }
    addToHead(2, &head);
    addToHead(2, &head);
    addToTail(2, &head);
    addToTail(2, &head);
    addToTail(2, &head);
    addToTail(2, &head);
    printList(head);
    removeNode(2, &head);
    printList(head);
    sortList(&head);
    printList(head);




    return 0;
}