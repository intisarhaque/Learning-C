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

void positionElement (intObj_t **head, intObj_t *nodeToInsert){
    printf("test ");
    printStruct(nodeToInsert);
    printf(" ");
    printList(*head);
    printf(" ");
    intObj_t* finder=(*head)->next;
    intObj_t* temp;
    if (nodeToInsert->id < (*head)->id){
        printf("changinghead\n");
        temp = nodeToInsert->next;
        nodeToInsert->next=*head;
        (*head)->next = temp;
        *head = nodeToInsert;
        printList(*head);
        return;
    }
    // else{
    //     printf("changingbody\n");
    //     while(finder->next!=NULL){
    //         if(nodeToInsert->id<finder->next->id){
    //             nodeToInsert->next=finder->next;
    //             finder->next=nodeToInsert;
    //         }else{
    //             finder = finder->next;
    //         }
    //     }
    //     //check tail
    // }
}

void insertionSortList(intObj_t **head){
    //insertion sort

    if (*head==NULL){
        printf("list not instantialized to sort");
        return;
    }
    intObj_t* iterator;// = (intObj_t** )malloc(sizeof(intObj_t*));//just an address that points to an address of a node
    intObj_t* temp;
    iterator = (*head);
    printf("sorting...\n");
    // while(iterator!=NULL){
    //     // do tail check
    //     temp = iterator->next;
    //     printf("temp is ");
    //     printStruct(temp);
    //     printf("\n");
    //     positionElement(head, iterator);
    //     iterator=temp;
    // }
    while(iterator->next!=NULL){
        if (iterator->next->next==NULL){
            printf("gwgweg");
            printStruct(iterator->next);
            positionElement(head, iterator->next);
            iterator->next=NULL;
        }else{
            temp = iterator->next->next;
            positionElement(head, iterator->next);
            iterator = temp;
        }
    }
    // insertElement(head, iterator);
    //printf("sorting done!\n");
    //*iterator = *head;
}

//search a sorted list



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
    addToHead(3, &head);
    addToHead(4, &head);
    addToHead(5, &head);
    addToHead(6, &head);
    addToHead(7, &head);
    // addToTail(2, head);
    // addToTail(2, head);
    // addToTail(2, head);
    // addToTail(2, head);
    //printList(head);
    // removeNode(2, &head);
    // printf("\nAfter removing:\n");
    // printList(head);
    // addToTail(5, head);
    insertionSortList(&head);
    printf("After sorting:\n");
    printList(head);





    return 0;
}