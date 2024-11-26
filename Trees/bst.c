#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct Node* insert(struct Node* node,int value){
    if(node==NULL){
        return createNode(value);
    }
    if(value<node->data){
        node->left=insert(node->left,value);
    }
    else if(value>node->data){
        node->right=insert(node->right,value);
    }
    return node;
}

struct Node* search(struct Node* node,int value){
    if(node==NULL || node->data==value){
        return node;
    }
    if(value<node->data){
        return search(node->left,value);
    }
    else if(value>node->data){
        return search(node->right,value);
    }
}

struct Node* minvalue(struct Node* node){
    struct Node* current=node;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct Node* delete(struct Node* node,int value){
    if(node==NULL){
        return node;
    }
    if(value<node->data){
        node->left=delete(node->left,value);
    }
    else if(value>node->data){
        node->right=delete(node->right,value);
    }
    else{
        if(node->left==NULL){
            struct Node* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==NULL){
            struct Node* temp=node->left;
            free(node);
            return temp;
        }
        else{
            struct Node* temp=minvalue(node->right);
            node->data=temp->data;
            node->right=delete(node->right,temp->data);
        }
    }
    return node;
}

void inorder(struct Node* node){
    if(node==NULL)return;
    inorder(node->left);
    printf("%d",node->data);
    inorder(node->right);
}

void preorder(struct Node* node){
    if(node==NULL)return;
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node){
    if(node==NULL)return;
    postorder(node->left);
    postorder(node->right);
    printf("%d",node->data);
}

int main(){
    struct Node* root=NULL;
    int r,b,s,d;
    printf("Enter the root node\n");
    scanf("%d",&r);
    root=insert(root,r);

    for(int i=1;i<=r;i++){
        printf("Enter the branches of the tree\n",i+1);
        scanf("%d",&b);
        insert(root,b);
    }

    printf("The tree traversal in the order of inorder,preorder,postorder\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    printf("What node do you want to search?\n");
    scanf("%d",&s);

    struct Node* result=search(root,s);
    if(result!=NULL){
        printf("Node %d found in bst\n",s);
    }else{
        printf("Node %d not found in bst\n");
    }

    printf("What node do you wish to delete?\n");
    scanf("%d",&d);
    root=delete(root,d);
    printf("The tree traversal in the order of inorder,preorder,postorder\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}