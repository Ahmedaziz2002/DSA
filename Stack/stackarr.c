#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack{
    int top;
    int items[MAX];
}Mystack;

Mystack* createStack(){
    Mystack* stack=(Mystack*)malloc(sizeof(Mystack));
    if(stack==NULL){
        printf("Mmemory allocation failed\n");
        return NULL;
    }
    stack->top=-1;//Initialize top to -1 to indicate an empty stack
    return stack;
}

int isFull(Mystack* stack){
    return stack->top==MAX-1;//if full then top=max-1
}

int isEmpty(Mystack* stack){
    return stack->top==-1;//if empty top=-1;
}

void push(Mystack* stack,int item){
    if(isFull(stack)){
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top]=item;//increment top while adding item to it
    printf("%d pushed onto the stack\n",item);
}

int pop(Mystack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];//decrement top
}

int peek(Mystack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top];//return top most element
}

int main(){
    Mystack* newstack=createStack();

    push(newstack,10);
    push(newstack,30);
    push(newstack,40);

    printf("%d popped\n",pop(newstack));
    printf("%d peeked\n",peek(newstack));

    return 0;
}