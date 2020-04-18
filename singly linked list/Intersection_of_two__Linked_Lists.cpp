#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* startIntersection = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void createIntersetedLinkedList(struct node ** s1,struct node ** s2, struct node **sIntersection);
int main()
{
    insertStart(&start1,1);
    insertStart(&start1,23);
    insertStart(&start1,3);
    insertStart(&start1,2);
    insertStart(&start1,6);
    printf("%s","Elements In The Linked List One \n");
    display(&start1);

    insertStart(&start2,2);
    insertStart(&start2,4);
    insertStart(&start2,6);

    printf("%s","Elements In The Linked List Two \n");
    display(&start2);

    createIntersetedLinkedList(&start1,&start2,&startIntersection);


    printf("%s","Elements In The Linked List Intersected \n");
    display(&startIntersection);
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

void createIntersetedLinkedList(struct node ** s1,struct node ** s2, struct node **sIntersection){
    struct node * temp1 = *s1;

    while(temp1->next != NULL){
        struct node  * temp2  = *s2;
        while(temp2->next != NULL ){
            if(temp2->data == temp1->data){
                break;
            }
            temp2 = temp2->next;
        }
        if(temp1->data == temp2->data){
            insertStart(&*(sIntersection),temp2->data);
        }
        temp1 = temp1->next;
    }
}