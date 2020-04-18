#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};


void insertAtLast(struct node ** start ,int data);
void display(struct node ** start);
void insertAtStart(struct node ** start,int data);
void insertAtPosition(struct node ** start,int data,int pos);
int lenOfDoublyLinkedList(struct node ** start);
void deleteNodeWithData(struct node ** start,int data);
struct node * returnNodeAtPointer(struct node ** start,int pos);
int main()
{   struct node * start =NULL;
    insertAtLast(&start,10);
    insertAtLast(&start,11);
    insertAtLast(&start,12);
    insertAtStart(&start,9);
    insertAtLast(&start,13);
    insertAtPosition(&start,8,1);
    insertAtPosition(&start,15,7);
    insertAtPosition(&start,14,7);
    display(&start);
    printf("%d is the len of linked list \n",lenOfDoublyLinkedList(&start));
    deleteNodeWithData(&start,13); //try data at position 1 and last
    display(&start);
    printf("%d is data at node at posotion last",returnNodeAtPointer(&start,lenOfDoublyLinkedList(&start))->data);
    return 0;
}

void insertAtLast(struct node ** start ,int data){
    struct node * temp = (struct node *) malloc(sizeof(struct node ));
    temp->data = data;
    if(*start == NULL){
        temp->prev = * start;
        temp->next = NULL;
        *start = temp;
        return;
    }
    else{
        struct node * iter = *start;
        while(iter->next != NULL){

            iter = iter->next;
        }
        iter->next = temp;
        temp->prev = iter;
        temp->next = NULL;

    }


}
void display(struct node ** start){
    struct node * temp = *start;
    int i = 1;
    while(temp != NULL)
    {
        printf("data in node %d is %d \n",i,temp->data);
        i++;
        temp = temp->next;
    }
}
void insertAtStart(struct node ** start,int data){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *start;
    (*start)->prev = temp;
    *start = temp;
    temp->prev = *start;
}
void insertAtPosition(struct node ** start,int data,int pos){
    struct node * temp = (struct node *) malloc(sizeof(struct node ));
    temp->data = data;

    if (pos == 1){
        temp->next = *start;
        (*start)->prev = temp;
        *start = temp;
        temp->prev = *start;
    }
    else{
        struct node * iter = *start;
        for (int i = 1; i <pos-1 ; ++i) {
            iter = iter->next;
        }
        if(pos == lenOfDoublyLinkedList(&*start)+1){
            temp->next = NULL;
            temp->prev = iter;
            iter->next = temp;
        }
        else{
            temp->prev = iter;
            temp->next = iter->next;
            iter->next->prev = temp;
            iter->next = temp;
        }

    }
}
int lenOfDoublyLinkedList(struct node ** start){
    if((*start) == NULL){
        return 0;
    }
    int count =1;
    struct node * temp = *start;
    while(temp->next != NULL){
        temp = temp->next;
        count ++;
    }
    return count;
}
void deleteNodeWithData(struct node ** start,int data){
    struct node * temp1 = *start;
    if (temp1->data == data){
        temp1->next->prev = *start;
        *start = temp1->next;
        free(temp1);
        return;

    }
    struct node * temp2 = (*start)->next;
    while(temp2->data != data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    free(temp2);
}
struct node * returnNodeAtPointer(struct node ** start,int pos){
    struct node * temp = *start;
    for (int i = 0; i <pos-1 ; ++i) {
        temp = temp->next;
    }
    return temp;
}