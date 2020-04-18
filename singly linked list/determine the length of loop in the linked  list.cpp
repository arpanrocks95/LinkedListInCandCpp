#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;
void insertStart(struct node ** s,int data);
void display(struct node **s);
struct node *  returnNodeAtPos(struct node **s,int pos );
int  determinethelengthofloopinthelinkedlist(struct node **s,int len);
int LengthLinkedListRecursive(struct node **s);
int main()
{   struct node * varnodelast ;
    struct node * varnodeanother;
    struct node * loopStart;
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,177);
    insertStart(&start,17);
    insertStart(&start,10);
    display(&start);
    int len = LengthLinkedListRecursive(&start);
    //here we will make a l;oop by assinging
    varnodelast = returnNodeAtPos(&start,5);
    varnodeanother = returnNodeAtPos(&start,3);
    printf("data in the varnodelast and  varnodeanother node is %d and %d\n",varnodelast->data,varnodeanother->data);
    varnodelast ->next = varnodeanother;
    printf("data in the varnodelast next node isand  varnodeanother  %d\n",varnodelast->next->data);

    //now we will detect loop in the linkedlist since last node dont have null anymore we have to rethink of various algorithims
    int loopLength = determinethelengthofloopinthelinkedlist(&start,len);
    printf("%d is length of the loop",loopLength);


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

int  determinethelengthofloopinthelinkedlist(struct node **s , int len){
    int desc = 0;
    int lengthOf1stNodeToStartNodeOfLoop = 0;
    struct node * temp = *s;
    struct node * fasttemp = *s;
    while (temp && fasttemp && fasttemp->next){
        if(desc == 0){
            temp = temp->next;
            fasttemp = fasttemp->next->next;
        }
        else{
            temp  = temp->next;
            fasttemp = fasttemp->next;
            lengthOf1stNodeToStartNodeOfLoop++;
        }

        if (temp == fasttemp){

            if(desc == 0){
                temp = *s;
                desc++;
            } else{
                printf("%s","there is a loop \t ");
                return (len-lengthOf1stNodeToStartNodeOfLoop);
            }


        }

    }
    printf("%s","There is no loop present in the linked list");

}

int LengthLinkedListRecursive(struct node **s){

    if (*s == NULL){
        return 0;
    }
    else{
        return 1+LengthLinkedListRecursive(&(*s)->next);
    }
}