#include<stdio.h>

void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];//Make the second index to be key
        int j=i-1;
        //Move elements of arrays[0..i-1],that are greater then key
        //To one position ahead of their current position
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;//MOve to prev element
        }
        arr[j+1]=key;//Insert the key at its correct position
    }
}

int main(){
    int arr[]={3,5,1,2,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array\n");
    for(int i=0;i<n;i++){
        printf("Index [%d] is element %d\n",i,arr[i]);
    }

    printf("Sorted array\n");
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("index [%d] is %d\n",i,arr[i]);
    }
    return 0;
    //TC is O(n) in best case if array is sorted and O(n^2) for a random based array
    //SC is O(1)
}