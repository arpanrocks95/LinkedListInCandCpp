#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node * returnNodeAtPosition(struct node ** start, int pos);
int lenOfCircularLinkedList(struct node ** start,struct node ** end);
void insertAtLast(struct node ** start,struct node ** end,int data);
void display(struct node **s);
void insertAtFirst(struct node ** start,struct node **end,int data);
void insertAtPosition(struct node ** start,struct node **end,int data,int pos);
void deleteNodeAtPosition(struct node ** start,struct node **end,int data);
int main()
{   struct node * start =NULL;
    struct node * end= NULL;

    insertAtFirst(&start,&end, 44);
    insertAtLast(&start,&end, 1);
    insertAtLast(&start,&end, 2);
    insertAtLast(&start,&end, 3);
    insertAtLast(&start,&end, 4);
    insertAtLast(&start,&end, 5);
    insertAtFirst(&start,&end, 545);
    insertAtPosition(&start,&end, 100,1);
    insertAtPosition(&start,&end, 1000,9);
    insertAtPosition(&start,&end, 2000,4);


    printf("%s","Elements In The Linked List One \n");

    display(&start);
    printf("\n\n");
    printf("%d is the length of this circular linked list \n",lenOfCircularLinkedList(&start,&end));
    printf("Data in  Node At Position 5 Is %d \n",returnNodeAtPosition(&start,5)->data);
    deleteNodeAtPosition(&start,&end,1000);


    printf("%s","Elements In The Linked List One \n");

    display(&start);

    return 0;
}


void insertAtLast(struct node ** start,struct node **end,int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    if (*end == NULL){
        *start = *end = p;
    }
    else{
        (*end)->next = p;
        *end = p;
    }
    (*end)->next = *start;
}
void insertAtFirst(struct node ** start,struct node **end,int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    if (*end == NULL){
        *start = *end = p;

    }
    else{
        p->next = (*start);
        *start = p;
    }
    (*end)->next = *start;
}
void insertAtPosition(struct node ** start,struct node **end,int data , int pos){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    struct  node * temp  = *start;

    if(pos >1){
        for (int i = 1; i < pos -1 ; ++i) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        if (pos == lenOfCircularLinkedList(&*start,&*end)){
            * end = p;
        }
    }
    else{
        if (*end == NULL){
            *start = *end = p;
        }
        else{
            p->next = (*start);
            *start = p;
        }
        (*end)->next = *start;
    }


}

void display(struct node **s){
    struct node *temp = *s;
    int i = 1;
    do{
        printf("Data in %d node is %d \n",i,temp->data);
        i++;
        temp = temp->next;
    }while (temp != *s);

}
int lenOfCircularLinkedList(struct node ** start,struct node ** end){
    int count =0;
    struct node * temp = *start;
    if (*end ==NULL){
        return 0;
    }
    do{
        count++;
        temp = temp->next;
    }while (temp != *start);
    return count;
}
struct node * returnNodeAtPosition(struct node ** start,int pos){
    struct node * temp = *start;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }
    return temp;
}
void deleteNodeAtPosition(struct node ** start,struct node **end,int data){
    struct node * temp1 = *start;
    struct node * temp2 = (*start)->next;
    if (temp1->data == data){
        *start = temp2;
        free(temp1);
        (*end)->next = *start;
        return;
    }
    else{
        while (temp2->data != data){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        free(temp2);
        if (*end == NULL){
            *end = temp1;
        }
    }
    // printf("%d is the data in end ",(*end)->next->data);

}