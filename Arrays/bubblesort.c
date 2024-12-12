#include<stdio.h>

void bubblesort(int arr[],int n){
    int i,j,temp,swapped;
    //loop through each element in the array
    for(i=0;i<n-1;i++){
        swapped=0;//flag to check if the swap occured
        for(j=0;j<n-i-1;j++){//last i elements are already sorted
            if(arr[j]>arr[j+1]){//check if the next element is less than current
                temp=arr[j];//swap them
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;//indicate swapped to be true if swap occured
            }
        }
        if(swapped==0){//if no swap occured break
            break;
        }
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Element [%d] is %d\n",i,arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={2,6,1,8,9,5,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array\n");
    printarray(arr,n);

    printf("Sorted array\n");
    bubblesort(arr,n);
    printarray(arr,n);

    return 0;
    //Tc is O(n^2) and space complexity is O(1).
}