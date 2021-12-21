#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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
        printf("List not instantialized, nothing to print\n");
        return;
    }
    intObj_t* iterator;// = (intObj_t* )malloc(sizeof(intObj_t*));//just an address that points to a node
    if(iterator==NULL){
        printf("No space to iterate\n");
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
    if (head==NULL){
        printf("head is null");
        return;
    }
    if ((*head)->id==0){
        (*(*head)).id = id;
        (*head)->next = NULL;
    }else{
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

void addToTail(int id, intObj_t *head){ 
    if ((head)->id==0){//null
        (*head).id = id;
        head->next = NULL;
    }
    else{
        intObj_t* newTail = (intObj_t* )malloc(sizeof(intObj_t));//memory for new node
        if (newTail==NULL){
            printf("No memory for new node in tail");
            return;
        }
        intObj_t* iterator;
        iterator = head;//address of iterator points to address of head

        while(iterator->next!=NULL){
            iterator = iterator->next;
        }//iterator now at the tail
        newTail->id=id;
        newTail->next=NULL;
        iterator->next=newTail;
        //free(iterator);

    }
    
}

void removeNode(int idToRemove, intObj_t **head){
    if (head==NULL){//null
        printf("List not instantialized; nothing to remove\n");
        return;
    }
    intObj_t* iterator;//= (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    intObj_t* prev;// = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    intObj_t* temp;// = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    // if(iterator==NULL || prev==NULL){
    //     printf("No space to iterate from remove");
    //     return;
    // }

    //clear heads of ID;
    while((*head)->id==idToRemove){
        iterator = *head;
        *head = (*head)->next;
        free(iterator);
    }

    //printStruct(*head);
    //can start on one node after head
    iterator = *head;
    prev = iterator;
    while(iterator!=NULL){
        if(iterator->id==idToRemove){
            if (iterator->next==NULL){//if tail
                prev->next=NULL;
                free(iterator);//free last node
                break;
            }else{
                prev->next=iterator->next;
                temp = iterator;
                free(temp);
                iterator = iterator->next;
                printStruct(temp);//
            }
        }else{
            prev = iterator;
            iterator = iterator->next;
        }
    }

}

void swapPointers(intObj_t **left, intObj_t **right){
    if (left==NULL || right==NULL){
        printf("node not found");
        return;
    }
    intObj_t* tempNodeHolder;// = (intObj_t** )malloc(sizeof(intObj_t*));
    intObj_t** tempAddressHolder;// = (intObj_t** )malloc(sizeof(intObj_t*));
    printf("wrapc\n");
    //free(temp);
}

void positionElement (intObj_t **newHead, intObj_t *nodeToInsert){
    printf("test ");
    printStruct(nodeToInsert);
    printf("test ");

    if (*newHead == NULL){
        printf("gwinegwe");
        *newHead=nodeToInsert;
        (*newHead)->next=NULL;
        printf("gwinegwe2\n");
        return;
    }
    if (nodeToInsert->id <= (*newHead)->id){
        printf("HMM?");
        nodeToInsert->next=*newHead;
        *newHead=nodeToInsert;
        printf("HMM2\n");
        return;
    }
    intObj_t* iterator = *newHead;
    intObj_t* temp;
    while(iterator->next!=NULL){
        if (nodeToInsert->id<iterator->next->id){
            printf("qqqq");
            printStruct(iterator->next);
            printStruct(iterator);
            printf("qqqq1");
            temp = iterator->next;
            iterator->next=nodeToInsert;
            nodeToInsert->next=temp;
            printf("qqqq2\n");
            return;
        }
        else{
            iterator=iterator->next;
        }
    }
    printf("tail is ");
    printStruct(iterator);
    iterator->next=nodeToInsert;
    printf("newtial\n");
    return;
}

void insertionSortList(intObj_t **head){
    intObj_t* newHead=NULL;
    intObj_t* temp;
    intObj_t* iterator = *head;
    while (iterator!=NULL){
        if (iterator->next==NULL){
            //tail
            positionElement(&newHead, iterator);
            break;
        }
        else{
            temp = iterator->next;
            positionElement(&newHead, iterator);
            iterator = temp;
            //printList(newHead);
            //  temp = iterator->next;
            // positionElement(&newHead, iterator);
            // iterator = temp;
        }
    }

    *head = newHead;


}


int main(){
    time_t t;
    srand((unsigned) time(&t));
    intObj_t* head = (intObj_t*) malloc(sizeof(intObj_t*));
    if (head==NULL){
        printf("No memory for head");
        return 0;
    }

    // for(int i = 0; i<50; i+=1){
    //     int randNumber = (rand() % 5) + 1;
    //     addToHead(randNumber, &head);
    // }
    addToHead(1, &head);
    addToHead(2, &head);
    addToHead(1, &head);
    addToHead(4, &head);
    addToHead(5, &head);
    addToHead(6, &head);
    addToHead(1, &head);
    addToTail(2, head);
    addToTail(4, head);
    addToTail(1, head);
    addToTail(2, head);
    printList(head);
    // removeNode(2, &head);
    // printf("\nAfter removing:\n");
    // printList(head);
    addToTail(1, head);
    insertionSortList(&head);
    printf("\nAfter sorting:\n");
    //printList(head);
    printStruct(head);
    printStruct(head->next);
    printStruct(head->next->next);
    printStruct(head->next->next->next);
    printStruct(head->next->next->next->next);
    // addToTail(2, head);
    //printList(head);






    return 0;
}