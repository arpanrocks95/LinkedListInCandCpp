#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

int lenOfCircularLinkedList(struct node ** start,struct node ** end);
void insertAtLast(struct node ** start,struct node ** end,int data);
void display(struct node **s);

void createTwoSubCircularLinkedList(struct node ** start1,struct node **end1 ,struct node ** start2,struct node ** end2 ,struct node ** start3 ,struct node ** end3);
int main()
{   struct node * start1 =NULL;
    struct node * end1= NULL;
    struct node * start2 = NULL;
    struct node * end2 = NULL;
    struct node * start3 = NULL;
    struct node *end3 = NULL;

    insertAtLast(&start1,&end1, 1);
    insertAtLast(&start1,&end1, 2);
    insertAtLast(&start1,&end1, 3);
    insertAtLast(&start1,&end1, 4);
    insertAtLast(&start1,&end1, 5);

    printf("%s","Elements In The Linked List One \n");

    display(&start1);
    createTwoSubCircularLinkedList(&start1,&end1,&start2,&end2,&start3,&end3);
    printf("%s","Elements In The Linked List Two \n");
    display(&start2);

    printf("%s","Elements In The Linked List three \n");
    display(&start3);
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

void createTwoSubCircularLinkedList(struct node ** start1,struct node **end1 ,struct node ** start2,struct node ** end2 ,struct node ** start3 ,struct node ** end3){
    int len = (lenOfCircularLinkedList(&*start1,&*end1)) ;
    if (len % 2 == 1){
        len = len/2;
        len++;
    }
    else{
        len = len/2;
    }
    printf("%d is the len /",len);
    struct node * temp1start = *start1;
    for (int i = 1; i < len; ++i) {
        printf("%d is data in temp1start \n",temp1start->data);
        temp1start = temp1start->next;
    }
    *start2 = *start1;
    *end2  = temp1start;
    *start3 = temp1start->next;
    (*end2)->next = *start2;
    *end3 = *end1;
    (*end3)->next = *start3;

}
