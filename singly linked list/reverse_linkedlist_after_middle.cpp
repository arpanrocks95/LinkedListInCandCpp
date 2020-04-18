#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;

void insertStart(struct node ** s,int data);
void display(struct node **s);
void reverseIterativeAfterMiddle(struct node ** s1);

int main()
{
    insertStart(&start, 1);
    insertStart(&start, 2);
    insertStart(&start, 3);
    insertStart(&start, 4);



    printf("%s","Elements In The Linked List One \n");
    display(&start);
    printf("\n\n");
    reverseIterativeAfterMiddle(&start);
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

void reverseIterativeAfterMiddle(struct node ** s1){
    int length = 0;
    int mid =0;

    struct node * iter = *s1;

    while(iter != NULL)  {iter = iter->next; length++;}

    if(length % 2 == 0) mid = (length /2) ;

    else mid =( length / 2 )+ 1;

    struct node * current = *s1;

    printf("%d is mid",mid);
    
    int mid2 = mid -1;
    while(mid--) current = current->next;
    struct node * middle = *s1;
    while(mid2--) middle = middle->next ;

    printf("%d",current->data);

    struct node * prev = NULL;

    struct node * next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    middle->next = prev;

}

