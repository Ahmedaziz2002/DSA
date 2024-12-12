#include<stdio.h>

void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];//TH epivot elemet
    int i=(low-1);
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;//partition index
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int arr[]={9,2,3,5,1,7,8,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array\n");
    for(int i=0;i<n;i++){
        printf("Index [%d] is %d\n",i,arr[i]);
    }

    printf("\n");
    printf("Sorted array\n");
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("Index [%d] is %d\n",i,arr[i]);
    }
    return 0;
}