#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void deleteLinkedList(struct node **s);
int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    deleteLinkedList(&start);
    return 0;
}
void insertStart(struct node ** s,int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = *s;
    *s = p;

}
void deleteLinkedList(struct node **s){
    struct node * temp = *s;
    struct node* temp1 = *s;
    temp1 = temp1->next;
    while(temp != NULL){
        free(temp);
        temp = temp1;
        temp1 = temp1->next;

    }

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