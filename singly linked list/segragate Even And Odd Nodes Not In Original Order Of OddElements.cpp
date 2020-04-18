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
void segragateEvenAndOddNodesNotInOriginalOrderOfOddElements(struct node ** s1);
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

void segragateEvenAndOddNodesNotInOriginalOrderOfOddElements(struct node ** s1){
    struct node * tempEven = *s1;
    struct node * tempOdd = *s1;
    while(tempEven != NULL){

        if ((tempEven->data)%2 == 0){
            if((tempOdd->data)%2 == 1){
                int temp = tempOdd->data;
                tempOdd->data = tempEven->data;
                tempEven->data = temp;
                tempOdd = tempOdd->next;
            }


        }
        tempEven = tempEven->next;
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