#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start1 = NULL;
struct node* start2 = NULL;

void insertStart(struct node ** s,int data);
void display(struct node **s);
void intersectionNode(struct node ** s1,struct node ** s2);
struct node *  returnNodeAtPos(struct node **s,int pos );
int main()
{
    insertStart(&start1,30);
    insertStart(&start1,15);
    insertStart(&start1,9);
    insertStart(&start1,6);
    insertStart(&start1,3);
    printf("%s","Elements In The Linked List One \n");
    display(&start1);


    struct node * temp = returnNodeAtPos(&start1,4);
    insertStart(&start2,10);
    start2->next = temp;


    printf("%s","Elements In The Linked List Two \n");
    display(&start2);

    intersectionNode(&start1,&start2);

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

void intersectionNode(struct node ** s1,struct node ** s2){
    struct node * temp1 = *s1;

    while(temp1->next != NULL){
        struct node  * temp2  = *s2;
        while(temp2->next != NULL ){
            if(temp2->next == temp1->next){
                printf("There exits an intersection node and that is %d",temp2->next->data);
                return;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

struct node *  returnNodeAtPos(struct node **s,int pos ){
    struct node * temp = *s;
    if(pos == 1){
        return temp;
    }
    else{
        for (int i =1 ;i<pos;i++){
            temp = temp->next;
        }
    }
    return  temp;
}