

typedef struct Node{
    int value;
    struct Node* nextNode;
}Node_t;

int deleteNum(int num){
    Node_t *temp = &head;
    
    0xffff



    while(*temp.nextNode!=NULL){
        Node_t *garbage = NULL
        if(*temp.nextNode.value==num){
            //to delete 2
            
            garbage = *temp.nextNode;
            *temp.nextNode = *temp.nextNode.nextNode;
            garbage.nextNode = NULL;
            free(garbage)

        }else{
            //nothing
        }
    }
    
}
//3
//1,2,3,4,5,3,6
/*
    1,
    2, 


*/

Node_t head;

int main()
{


}