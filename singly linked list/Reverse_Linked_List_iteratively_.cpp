#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;

void insertStart(struct node ** s,int data);
void display(struct node **s);
void reverseIterative(struct node ** s1);

int main()
{
    insertStart(&start, 1);
    insertStart(&start, 2);
    insertStart(&start, 3);
    insertStart(&start, 4);
    insertStart(&start, 5);


    printf("%s","Elements In The Linked List One \n");
    display(&start);
    printf("\n\n");
    reverseIterative(&start);
    printf("%s","Elements In The Linked List One after reversing \n");
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

void reverseIterative(struct node ** s1){
    struct node * prev = NULL;
    struct node * current = *s1;
    struct node * next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    start = prev;
}

0