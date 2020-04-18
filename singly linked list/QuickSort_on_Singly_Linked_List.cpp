#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * next;
};

struct node* start = NULL;
int  LengthLinkedListIterative(struct node **s);
struct node *  returnNodeAtPos(struct node **s,int pos );
void insertStart(struct node ** s,int data);
void display(struct node **s);

void quickSort( int low, int high);
int partitionwithpivotatlast (int arr[], int low, int high);
int main()
{
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,10);
    insertStart(&start,1777);
    insertStart(&start,10);
    insertStart(&start,155);
    display(&start);
    int higho = LengthLinkedListIterative(&start);
    quickSort(1,higho);
    printf("%s","after sorting \n");
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



int partitionwithpivotatlast (int low, int high)
{
    struct node * pivot = returnNodeAtPos(&start,high);    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (returnNodeAtPos(&start,j)->data < pivot->data)
        {
            i++;    // increment index of smaller element
            int temp = returnNodeAtPos(&start,i)->data;
            returnNodeAtPos(&start,i)->data = returnNodeAtPos(&start,j)->data;
            returnNodeAtPos(&start,j)->data = temp;
        }
    }
    int temp2 = returnNodeAtPos(&start,i+1)->data;
    returnNodeAtPos(&start,i+1)->data = returnNodeAtPos(&start,high)->data;
    returnNodeAtPos(&start,high)->data = temp2;
    return (i + 1);
}

void quickSort(int low, int high)
{
    if (low < high)
    {

        int pi = partitionwithpivotatlast(low, high);

        quickSort( low, pi - 1);
        quickSort( pi + 1, high);
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