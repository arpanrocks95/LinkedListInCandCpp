#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
void  SearchLinkedListIterative(struct node **s,int data );
void  SearchLinkedListRecursive(struct node **s,int data);
int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    display(&start);
    SearchLinkedListIterative(&start,10);
    SearchLinkedListRecursive(&start,17);
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


void SearchLinkedListIterative(struct node **s, int data) {
    if (*s == NULL){
        printf("%s\n","Its and Empty LinkedList ");
        return ;
    }
    struct node *temp = *s;
    while (temp != NULL){
        if (temp->data == data){
            printf("%d %s\n",temp->data," Found In LinkedList ");
            return;
        }
        temp = temp->next;
    }
}
void SearchLinkedListRecursive(struct node **s,int data ){
    if (*s == NULL){
        printf("%s\n","Its and Empty LinkedList ");
        return ;
    }
    else if ((*s)->data == data){
        printf("%d %s\n",(*s)->data," Found In LinkedList ");
        return;
    }
    else{
        SearchLinkedListRecursive(&(*s)->next,data);
    }
}
