#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};


void insertAtLast(struct node ** start ,struct node ** end ,int data);
void display(struct node ** start,struct node ** end);
void insertAtStart(struct node ** start,struct node ** end ,int data);
void insertAtPosition(struct node ** start,struct node ** end ,int data,int pos);
int lenOfDoublyCircularLinkedList(struct node ** start,struct node ** end );
void deleteNodeWithData(struct node ** start,struct node ** end ,int data);
struct node * returnNodeAtPosition(struct node ** start,int pos);
int main()
{   struct node * start =NULL;
    struct node * end = NULL;
    insertAtStart(&start,&end,8);
    insertAtLast(&start,&end,9);
    insertAtLast(&start,&end,10);
    insertAtLast(&start,&end,11);

    display(&start,&end);
    insertAtStart(&start,&end,7);
    printf("%s","this is  display after inserting\n");
    display(&start,&end);
    printf("%d is the length of this doubly circular linked list \n",lenOfDoublyCircularLinkedList(&start,&end));
    insertAtPosition(&start,&end,3,1);

    printf("%s","this is  display after insertatposition\n");
    display(&start,&end);

    printf("%s","this is display after deleting the data 3\n");
    deleteNodeWithData(&start,&end,11);
    display(&start,&end);

    printf("%d is node at pos 1",(returnNodeAtPosition(&start,1))->data);
    return 0;
}

void insertAtLast(struct node ** start ,struct node ** end ,int data){
    struct node * temp = (struct node *) malloc(sizeof(struct node ));
    temp->data = data;
    if(*end == NULL){
        temp->prev = * start;
        temp->next = *start;
        *start = temp;
        *end = temp;
        return;
    }
    else{
        struct node * iter = *start;
        while(iter!= *end){
            iter = iter->next;
        }

        iter->next = temp;
        temp->prev = iter;
        temp->next = *start;
        *end = temp;
        (*start)->prev = *end;

    }


}
void display(struct node ** start,struct node ** end){
    struct node * temp = (*start)->next;
    printf("data in node %d is %d \n",1,(*start)->data);
    int count = 2;
    while (temp != *end){
        printf("data in node %d is %d \n",count,temp->data);
        temp = temp->next;
        count = count + 1;
    }
    printf("data in node %d is %d \n",count,temp->data);
}
void insertAtStart(struct node ** start,struct node ** end ,int data){
    struct node *  temp = (struct node *)malloc(sizeof(struct node ));
    temp->data = data;
    if (*start == NULL){
        temp->next = *start;
        temp->prev = *start;
        *end = temp;
        *start = temp;
    }

    temp->next = *start;
    (*start)->prev = temp;
    *start = temp;
    temp->prev = *end;
    (*end)->next = *start;

}
void insertAtPosition(struct node ** start,struct node ** end ,int data,int pos){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    if (pos == 1){
        temp->next = *start;
        (*start)->prev = temp;
        *start = temp;
        temp->prev = *end;
        (*end)->next = *start;
    }
    else{
        struct  node * iternode = *start;
        for (int i = 1; i <pos-1 ; ++i) {
            iternode = iternode->next;
        }
        if(pos == lenOfDoublyCircularLinkedList(&*start,&*end) + 1){
            iternode->next = temp;
            temp->prev = iternode;
            temp->next = *start;
            *end = temp;
            (*start)->prev = *end;
        }
        temp->prev = iternode;
        temp->next = iternode->next;
        iternode->next->prev = temp;
        iternode->next = temp;


    }
}
int lenOfDoublyCircularLinkedList(struct node ** start,struct node ** end){
    struct node * temp = (* start)->next;
    if (*start == NULL){
        return 0;
    }
    int count = 1;
    while (temp != *start){
        temp = temp->next;
        count = count + 1;
    }
    return count;
}

void deleteNodeWithData(struct node ** start,struct node ** end ,int data){
    struct node * temp1 = *start;
    if(temp1->data ==  data){
        *start = temp1->next;
        (*start)->prev = *end;
        (*end)->next= *start;
        return;
    }
    struct node * temp2 = (*start)->next;
    while(temp2->data != data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next->prev = temp1;
    if (temp2 == *end){
        *end = temp1;
    }

}

struct node * returnNodeAtPosition(struct node ** start,int pos){
    struct node  * temp = * start;

    for (int i = 0; i < pos-2 ; ++i) {
        temp = temp->next;
    }
    return temp;
}