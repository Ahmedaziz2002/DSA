#include<stdio.h>
#include<stdlib.h>

struct List{
    int data;
    struct List* next;
};

void insertAtBeginning(struct List ** head,int newdata){
    struct List* newList=(struct List*)malloc(sizeof(struct List));
    if(newList==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newList->data=newdata;
    newList->next=*head;
    (*head)=newList;
}

void deleteNode(struct List** head,int key){
    struct List* temp=*head;
    struct List* prev=NULL;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found!\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

struct List* reverseList(struct List* head){
    struct List* next=NULL;
    struct List* prev=NULL;
    struct List* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int searchList(struct List* node,int key){
    struct List* current=node;
    while(current!=NULL){
        if(current->data==key){
            return 1;//key found
        }
        current=current->next;
    }
    return 0;//key  not found
}

void printList(struct List* node){
    while(node!=NULL){
        printf("%d ->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    struct List* head=NULL;
    int n,data,key;
    printf("Enter the number of nodes in your list\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the data for your list\n",i+1);
        scanf("%d",&data);
        insertAtBeginning(&head,data);
        printList(head);
    }

    printf("\n");
    printf("Enter the node you want to delete\n");
    scanf("%d",&key);
    deleteNode(&head,key);
    printList(head);


    int input;
    printf("Do you want to reverse your list?\n1.Yes\n2.No\n");
    scanf("%d",&input);

    switch(input){
        case 1:
        printf("List in reverse\n");
        head=reverseList(head);
        printList(head);
        break;
        case 2:
        printf("The list remeins as it was then\n");
        printList(head);
        exit(0);
    }

    int search;
    printf("What element do you want to search?\n");
    scanf("%d",&search);

    int result=searchList(head,search);

    if(result!=0){
        printf("Key found at linked list\n");
    }else{
        printf("Key not found\n");
    }
    while(head!=NULL){
        struct List* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}