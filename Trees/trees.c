#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->left=newnode->right=NULL;
    return newnode;
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
    struct Node* root=createTree(10);
    root->left=createTree(2);
    root->right=createTree(3);

    printf("Inorder traversal\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal\n");
    postorder(root);
    printf("\n");

    return 0;
    
}