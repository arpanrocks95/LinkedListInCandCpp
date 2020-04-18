#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void isPalindrome(struct node **s);
int LengthLinkedListIterative(struct node **s);
struct node *  returnNodeAtPos(struct node **s,int pos );
int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);//replace it with any other no.
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
void isPalindrome(struct node **s) {

    int desc = 0;
    int mid = ((LengthLinkedListIterative(&start)/2)+1);
    int len = LengthLinkedListIterative(&start);
    for (int i = 1; i < mid; ++i) {
        if (returnNodeAtPos(&start,i)->data == returnNodeAtPos(&start,len - i + 1)->data){
            desc = 1;
        }
        else{
            desc = 0;
            break;
        }
    }
    if (desc == 1) {
        printf("%s", "The given linked is  a palindrome ");

    }
    else {
        printf("%s", "The given linked list is not a palindrome");
    }
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