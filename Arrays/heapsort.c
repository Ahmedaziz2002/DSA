#include<stdio.h>
//Heap sort works by 
//Build a max heap
//Extract elements from the heap
//Repeat
//Example for an array={3,5,1,10,2}
//Build a max heap{10,5,3,1,2}
//Swap the root with the last element{2,5,3,1,10}
///Restore heap property{5,2,3,1}
//repeat until sorted{1,2,3,5,10}
//TC is O(n log n) and O(1).

void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Function to heapify a subtree rooted with node i
void heapify(int arr[],int n,int i){
    int largest=i;//Initialize largest to be root
    int left=2*i+1;//left child
    int right=2*i+2;//right child
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){//if largest is not root
        swap(&arr[i],&arr[largest]);//swap largest with the root
        heapify(arr,n,largest);//recursively heapify the subtree
    }
}

void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){//build max heap
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){//one by one extract elements from the heap
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Element at [%d] is %d\n",i,arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={5,1,2,9,3,4,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array\n");
    printarray(arr,n);

    heapsort(arr,n);
    printf("Sorted array\n");
    printarray(arr,n);

    return 0;
}