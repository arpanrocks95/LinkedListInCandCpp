#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};
struct stackNode{
    int data;
    struct stackNode * next;
};
struct stackNode * top = NULL;
void  push(struct stackNode ** top , int data);
int peek(struct stackNode ** top);
void pop(struct stackNode ** top);
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void isPalindrome(struct node **s);

int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,1777);
    insertStart(&start,10);
    display(&start);
    isPalindrome(&start);
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
void isPalindrome(struct node **s){
    struct node  * temp = *s;
    int topData;
    while(temp){
        push(&top,temp->data);
        topData = peek(&top);
        printf("%d is data at top\n",topData);
        temp = temp->next;
    }
    temp = *s;
    while (temp){

        if (temp->data == peek(&top)){
            pop(&top);
        }
        temp = temp->next;
    }
    if(top == NULL){
        printf("%s","The given linked list is a palindrome" );
    }
    else{
        printf("%s","The given linked is not a palindrome ");
    }
}

//methods for stack

void  push(struct stackNode ** top , int data){
    struct stackNode * tempNode = (struct stackNode *)malloc(sizeof(struct stackNode));
    tempNode->data = data;
    tempNode->next = *top;
    *top = tempNode;
}

void pop(struct stackNode ** top){
    if (!top){
        printf("%s","Stack Is Empty");
    }
    else{
        struct stackNode * tempNode = *top;
        *top = (*top)->next;
        printf("%d is popped succesfully\n",(tempNode)->data);
        free(tempNode);
    }
}

int peek(struct stackNode ** top){
    return (*top)->data;
}


