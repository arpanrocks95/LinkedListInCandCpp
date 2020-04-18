#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;
void moveLastNodeToLast(struct node ** s);
void insertStart(struct node ** s,int data);
void display(struct node **s);

int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,14);
    insertStart(&start,19);
    insertStart(&start,155);
    display(&start);
    moveLastNodeToLast(&start);
    printf("%d is the data in first node ",start->data);
    return 0;
}
void insertStart(struct node ** s,int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = *s;
    *s = p;

}


void display(struct node **s){
    struct node *temp = *s;
    int i = 1;
    while (temp!=NULL){
        printf("Data in %d node is %d \n",i,temp->data);
        i++;
        temp = temp->next;
    }

}

void moveLastNodeToLast(struct node ** s){
    struct node * temp1 = *s;
    struct node * temp2 = *s;
    temp2 = temp2->next;
    while (temp2->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    temp2->next = *s;
    *s = temp2;

}