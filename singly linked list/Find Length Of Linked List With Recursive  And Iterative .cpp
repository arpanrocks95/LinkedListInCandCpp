#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
int LengthLinkedListIterative(struct node **s);
int LengthLinkedListRecursive(struct node **s);
int main()
{   int leni,lenr;
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    leni = LengthLinkedListIterative(&start);
    lenr = LengthLinkedListRecursive(&start);
    printf("%d is the length of the linked list with iterative function \n",leni);
    printf("%d is the length of the linked list with recursive function \n",lenr);
    printf("%d ",start->data);
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
int  LengthLinkedListIterative(struct node **s){
    struct node *temp = *s;
    int count = 0;
    while (temp!=NULL){
        count++;
        temp = temp->next;
    }
    return  count;
}
int LengthLinkedListRecursive(struct node **s){

    if (*s == NULL){
        return 0;
    }
    else{
        return 1+LengthLinkedListRecursive(&(*s)->next);
    }
}