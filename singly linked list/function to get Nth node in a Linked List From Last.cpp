#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
struct node *  returnNodeAtPosFromLast(struct node **s,int pos );
int  LengthLinkedListIterative(struct node **s);
int main()
{   struct node * varnode;
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    varnode = returnNodeAtPosFromLast(&start,2);
    printf("data in the returned node is %d",varnode->data);
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

struct node *  returnNodeAtPosFromLast(struct node **s,int pos ){
    pos = LengthLinkedListIterative(&*s)-pos;
    printf("%d",pos);
    struct node * temp = *s;
    for (int i =0 ;i<pos;i++){
            temp = temp->next;
        }
    return  temp;
}
int  LengthLinkedListIterative(struct node **s){
    struct node *temp = *s;
    int count = 0;
    while (temp!=NULL){
        count++;
        temp = temp->next;
    }
    return  count;
}