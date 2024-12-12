#include<stdio.h>
int main(){
    //An array is a contiguous block of memory that store element of the same type
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        printf("array element [%d] is %d\n",i,arr[i]);
        printf("Address of %d is %p\n",i,(void*)&arr[i]);
    }
    printf("Base address of the address is %p\n",(void*)&arr);
    //The space complexity of an array is O(n) where n represent the number of elements.
    //Time complexity is O(1) for accessing an element,O(n) in search in linear and O(log n) in binary.
    return 0;
}