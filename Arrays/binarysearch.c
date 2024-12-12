#include<stdio.h>

int binarysearch1(int arr[],int size,int target){
    //Iterative method
    int high=size-1;
    int low=0;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}


int binarysearch2(int arr[],int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid==target]){
        return mid;
    }else if(arr[mid]<target){
        return binarysearch2(arr,mid+1,high,target);
    }else{
        return binarysearch2(arr,low,mid-1,target);
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        printf("Array element at [%d] is %d\n",i,arr[i]);
    }
    printf("\n");


    int input;
    printf("What binary search algorithm do you want to use?\n1.Iterative\n2.Recursive\n");
    scanf("%d",&input);

    switch(input){
        case 1:
        printf("What element do you want to search?");
        int target;
        scanf("%d",&target);

        int result=binarysearch1(arr,n-1,target);
        if(result!=-1){
            printf("Array element found at index %d\n",result);
        }else{
            printf("Array element not found\n");
        }
        break;
        case 2:
        printf("What element do you want to search?");
        target;
        scanf("%d",&target);

        result=binarysearch2(arr,0,n-1,target);
        if(result!=-1){
            printf("Array element found at index %d\n",result);
        }else{
            printf("Array element not found\n");
        }
        break;
    }
    return 0;
}