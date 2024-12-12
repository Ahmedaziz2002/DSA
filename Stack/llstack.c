#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack* next;
};

struct Stack* createStack(int newdata){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    if(stack==NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    stack->data=newdata;
    stack->next=NULL;//inialize next to NULL to indicate an empty stack
    return stack;//return the created stack
}

int isEmpty(struct Stack* top){
    return top==NULL;//if empty top is NULL
}

void push(struct Stack** top,int data){
    struct Stack* stack=createStack(data);
    if(stack==NULL)return;
    stack->next=*top;
    *top=stack;//New top is the stack
    printf("%d pushed onto the stack\n",data);
}

int pop(struct Stack** top){
    if(isEmpty(*top)){
        printf("Stack underflow cannot pop any element\n");
        return -1;
    }
    struct Stack* temp=*top;
    int popped=temp->data;
    *top=(*top)->next;
    free(temp);
    return popped;
}

int peek(struct Stack* top){
    if(isEmpty(top)){
        printf("Stack underflow\n");
        return -1;
    }
    return top->data;
}

void printStack(struct Stack* node){
    if(node==NULL){
        printf("Stack is Empty!\n");
        return;
    }
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}

int main(){
    struct Stack* top=NULL;
    int n,data;

    printf("Enter the number of element to push:\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the data for element pushed\n",i+1);
        scanf("%d",&data);
        push(&top,data);
        printStack(top);
    }
    printf("Pushed elements are:\n");
    printStack(top);

    int poppedValue=pop(&top);
    if(poppedValue!=-1){
        printf("%d popped\n",poppedValue);
        printStack(top);
    }

    int peekedValue=peek(top);
    if(peekedValue!=-1){
        printf("%d peeked",peekedValue);
        printStack(top);
    }
    printf("New stack is\n");
    printStack(top);

    while(top!=NULL){
        struct Stack* temp=top;
        top=top->next;
        free(temp);
    }
    return 0;
}