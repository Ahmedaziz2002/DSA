#include<stdio.h>

int linearsearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        printf("Array element at [%d] is %d\n",i,arr[i]);
    }
    printf("What element are ypu looking for\n");
    int target;
    scanf("%d",&target);

    int result=linearsearch(arr,n,target);
    if(target!=-1){
        printf("Array element found at index %d\n",result);
    }else{
        printf("Array element not found\n");
    }
    return 0;
}