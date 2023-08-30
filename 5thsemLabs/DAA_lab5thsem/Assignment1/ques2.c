// Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
// sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
// // arr[0] + arr[1] + arr[2] . . . arr[i].
#include <stdio.h>
#include <stdlib.h>
void prefixsum (int arr[], int n, int newarr[]){

    newarr[0] = arr[0];
    for(int i=1; i<n; i++){
        newarr[i] = arr[i-1] +  arr[i];
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int newarr[n];

    prefixsum(arr,n,newarr);
    printf("Prefix Sum: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", newarr[i]);
    }
    printf("\n");
    


    return 0;
}