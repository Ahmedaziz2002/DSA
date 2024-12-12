#include<stdio.h>
#include<stdlib.h>

struct Double{
    int data;
    struct Double* next;
    struct Double* prev;
};

void insertAtBeginning(struct Double** head,int newdata){
    struct Double* doublelist=(struct Double*)malloc(sizeof(struct Double));
    if(doublelist==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    doublelist->data=newdata;
    doublelist->next=*head;
    doublelist->prev=NULL;
    if(*head!=NULL){
        (*head)->prev=doublelist;
    }
    (*head)=doublelist;
}

void deleteNode(struct Double** head,int key){
    struct Double* temp=*head;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        if(*head!=NULL){
            (*head)->prev=NULL;
        }
        free(head);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found!\n");
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    free(temp);
}

struct Double* reverseList(struct Double* head){
    struct Double* prev=NULL;
    struct Double* next=NULL;
    struct Double* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int searchList(struct Double* node,int key){
    struct Double* temp=node;
    while(temp!=NULL){
        if(temp->data==key){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void displayList(struct Double* node){
    while(node!=NULL){
        printf("%d <->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Double* head=NULL;
    int n,data,key;
    printf("Enter the number of nodes for your List\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data for your list\n",i+1);
        scanf("%d",&data);
        insertAtBeginning(&head,data);
        displayList(head);
    }
    printf("\n");
    printf("Enter the key you want to delete\n");
    scanf("%d",&key);
    deleteNode(&head,key);
    displayList(head);

    int input;
    printf("Do you want to reverse your list\n1.Yes\n2.No\n");
    scanf("%d",&input);


    switch(input){
        case 1:
        printf("List in reverse\n");
        head=reverseList(head);
        displayList(head);
        break;
        case 2:
        printf("The list remains as it was then\n");
        displayList(head);
    }

    int search;
    printf("What element do you want to search?\n");
    scanf("%d",&search);

    int result=searchList(head,search);
    if(result!=0){
        printf("Key found\n");
    }else{
        printf("Key not found\n");
    }
    while(head!=NULL){
        struct Double* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}