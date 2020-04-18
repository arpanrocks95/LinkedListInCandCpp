#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void deleteDuplicatesInSortedLinkedList(struct node **s);

int main()
{
    insertStart(&start,10);
    insertStart(&start,10);
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,1777);
    insertStart(&start,155);
    display(&start);
    deleteDuplicatesInSortedLinkedList(&start);
    display(&start);
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
void deleteDuplicatesInSortedLinkedList(struct node **s) {
    struct node * current = *s;
    struct node * temp = *s;
    if(current == NULL){
        return;
    }
    while(current->next!=NULL){
        if(current->data == current->next->data){
            temp = current->next->next;
            free(current->next);
            current->next = temp;
        }
        else
        {
            current = current->next;
        }
    }

}

