#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
int returnAGivenDataOccurences(struct node **s, int data);
int main()
{   int i=0;
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,17);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    printf("%d is the no. of occurences of 17",returnAGivenDataOccurences(&start,17));
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

int returnAGivenDataOccurences(struct node **s, int data) {
    int count= 0;
    if (*s == NULL){
        printf("%s\n","Its and Empty LinkedList ");
        return 0;
    }
    struct node *temp = *s;
    while (temp != NULL){
        if (temp->data == data){
            count++;
        }
        temp = temp->next;
    }
    return count;
}