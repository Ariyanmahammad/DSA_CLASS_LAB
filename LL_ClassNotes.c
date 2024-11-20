#include<stdio.h>
#include<stdlib.h>
typedef struct node
    {
        int data;
        struct node* next;

    }node;
    void append(node**,int item);//insert at end
    void insertFront(node**,int item);
    void deleteKey(node**,int item);
    void display(node**);
    
int main(){
    int ch,item,key;
    node*head=NULL;
    while (1)
    {
        printf("enter your choice\n 1.Append\n 2.InsertFront\n 3.deleteKey\n 4.display\n 5.exit\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
    
            switch (ch)
            {
            case 1:printf("enter data to be inserted : \n");
                scanf("%d",&item);
                append(&head,item);
                break;
            case 2:printf("enter data to be inserted : \n");
                scanf("%d",&item);
                insertFront(&head,item);
                break;
            case 3:printf("enter data to be deleted : \n");
                scanf("%d",&item);
                deleteKey(&head,item);
                break;
            case 4:display(&head);
                break;
            case 5:exit(0);
            
            default:printf("invalid number");
                break;
            }
    }
    

    return 0;
}
void append(node**p,int item){
    node*temp=*p,*r=(node*)malloc(sizeof(node));
    r->data=item;
    r->next=NULL;
    if(*p==NULL){
        *p=r;
    }
    else{
        // temp=*p;
    
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=r;
    
}
}
void insertFront(node**p,int item){
    node*r=(node*)malloc(sizeof(node));
    r->data=item;
    r->next=*p;
    *p=r;
}

void deleteKey(node** p, int item) {
    node* temp = *p;  // current node
    node* prev = NULL;  // previous node (to link nodes)

    while (temp != NULL) {
        if (temp->data == item) {
            if (temp == *p) {  // if it's the head node
                *p = temp->next;  // move the head to the next node
                free(temp);
                temp = *p;  // move temp to the new head
            } else {  // for non-head nodes
                prev->next = temp->next;  // skip the current node
                free(temp);
                temp = prev->next;  // move temp to the next node
            }
        } else {
            prev = temp;  // update prev to the current node
            temp = temp->next;  // move temp to the next node
        }
    }
}



void display(node**p){
    node*temp;
    temp=*p;
    while (temp!=NULL)
    {
        printf(" %d ",temp->data);
        printf("->");
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
    
}