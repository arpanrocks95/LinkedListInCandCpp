#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;

void insertStart(struct node ** s,int data);
void display(struct node **s);
int  LengthLinkedListIterative(struct node **s);
void segragateEvenAndOddNodesInOriginalOrderOfOddElements(struct node ** s1);
struct node *  returnNodeAtPos(struct node **s,int pos );
int main()
{
    insertStart(&start, 6);
    insertStart(&start, 7);
    insertStart(&start, 1);
    insertStart(&start, 4);
    insertStart(&start, 5);
    insertStart(&start, 10);
    insertStart(&start, 12);
    insertStart(&start, 8);
    insertStart(&start, 15);
    insertStart(&start, 17);

    printf("%s","Elements In The Linked List One \n");
    display(&start);
    printf("\n\n");
    segragateEvenAndOddNodesInOriginalOrderOfOddElements(&start);
    printf("%s","Elements In The Linked List One after segragating even and odd nodes\n");
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

void segragateEvenAndOddNodesInOriginalOrderOfOddElements(struct node ** s1){
    int len = LengthLinkedListIterative(&*s1);

    for(int i=0;i<len;i++){
        int kl = 0;
        struct node * temp = *s1;
        while((temp->data)%2 == 0){
            temp = temp->next;
            kl++;
        }

        if((temp->data)%2 == 1){
            struct node * tempLastNode = returnNodeAtPos(&*s1,len);
            if(temp == start){
                start = start->next;
                temp->next = NULL;
                tempLastNode ->next = temp;
            }
            else{
                struct node * tempNode  = returnNodeAtPos(&*s1,kl);
                tempNode->next = temp->next;
                temp->next = NULL;
                tempLastNode ->next = temp;
            }


        }
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
int  LengthLinkedListIterative(struct node **s){
    struct node *temp = *s;
    int count = 0;
    while (temp!=NULL){
        count++;
        temp = temp->next;
    }
    return  count;
}