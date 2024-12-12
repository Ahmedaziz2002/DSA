#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//structrure to represent a node in the adjacency list
struct Node{
    int vertex;
    struct Node* next;
};

//structure to represent a graph
struct Graph{
    int numVertices;
    struct Node** adjLists;
};

//Function to create a graph
struct Graph* createGraph(int vertices){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->adjLists=malloc(vertices* sizeof(struct Node*));

    for(int i=0;i<vertices;i++){
        graph->adjLists[i]=NULL;
    }
    return graph;
}

//Function to create a new adjacency list node
struct Node* createNode(int v){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}

//Function to add an edge to the graph
void addEdge(struct Graph* graph,int src,int dest){
    struct Node* newNode=createNode(dest);
    newNode->next=graph->adjLists[dest];
    graph->adjLists[dest]=newNode;
}

//Iterative DFS
void DFSIterative(struct Graph* graph,int startVertex){
    int visited[MAX]={0};
    struct Node* stack[MAX];
    int top=-1;
    stack[++top]=createNode(startVertex);

    while(top!=-1){
        struct Node* currentNode=stack[top--];
        int currentVertex=currentNode->vertex;

        if(!visited[currentVertex]){
            printf("%d",currentVertex);
            visited[currentVertex]=1;
        }
        for(struct Node* temp=graph->adjLists[currentVertex];temp!=NULL;temp=temp->next){
            if(!visited[temp->vertex]){
                stack[++top]=createNode(temp->vertex);
            }
        }
        free(currentNode);//free the popped node
    }
}

//Recursive DFS
void DFSRecursive(struct Graph* graph,int vertex,int visited[]){
    visited[vertex]=1;
    printf("%d",vertex);

    for(struct Node* temp=graph->adjLists[vertex];temp!=NULL;temp=temp->next){
        if(!visited[temp->vertex]){
            DFSRecursive(graph,temp->vertex,visited);
        }
    }
}

int main(){
    struct Graph* graph=createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,4);

    printf("DFSIterative\n");
    DFSIterative(graph,0);
    printf("\n");
    int visited[MAX]={0};
    printf("DFSRecursive\n");
    DFSRecursive(graph,0,visited);
    printf("\n");

    return 0;
}