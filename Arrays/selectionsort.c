#include<stdio.h>

void selectionsort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int smallest=i;//Assume the first element is the smallest
        for(int j=i+1;j<size;j++){//Check if there is a smallet element than the first 
            if(arr[j]<arr[smallest]){
                smallest=j;//If there exist make it the smallest
            }
        }
        if(smallest!=i){//Swap the element to the first element if it is smaller
            int temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
        }
    }
    //TC is O(n^2) and SC is O(1).
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
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("Index [%d] is %d\n",i,arr[i]);
    }
    return 0;
}