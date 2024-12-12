#include<stdio.h>

//Function to merge two sorted arrays
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;//Size of the left subarray
    int n2=right-mid;//Size of the right subarray
    int L[n1],R[n2];//create temporary arrays
    //copy data to temporay arrays L[n1] and R[n2]
    for(i=0;i<n1;i++)
        L[i]=arr[left+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    //Merge the temporary arrays back into arr[left...right]
    i=0;//Initial index of the first subarray
    j=0;//Initila index of the second subarray
    k=left;//Initial index of the merged array
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    //Copy the remaining elements of L[] if there are any
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    //Copy the remaining elements of R[] if there are any
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;//Find the mid point
        //Sort first and second halves
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        //merge the sorted halves
        merge(arr,left,mid,right);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Array element at [%d] is %d\t and its square is %d\n",i,arr[i],arr[i]*arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={3,1,2,8,9,5,4,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original array\n");
    printarray(arr,n);

    printf("Sorted array\n");
    mergesort(arr,0,n-1);
    printarray(arr,n);

    return 0;
}