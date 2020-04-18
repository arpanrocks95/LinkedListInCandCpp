#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;

void insert(struct node ** s,int data);
void display(struct node **s);


int main()
{
    insert(&start, 1);
    insert(&start, 2);
    insert(&start, 3);
    insert(&start, 4);
    insert(&start, 5);


    printf("%s","Elements In The Linked List One \n");

    display(&start);
    printf("\n\n");


    return 0;
}
void insert(struct node ** s,int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));

    p->data = data;
    p->next = *s;
    struct node * temp = *s;
    if (*s != NULL){
        while (temp->next != *s){
            temp = temp->next;
        }
        temp->next = p;
    }
    else{
        p->next = p;   //when its first node
    }
    start = p;

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

