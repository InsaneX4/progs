// 2. Write a program to find out the largest difference between two
// elements A[i] and A[j] ( A[j]-A[i]) of the array of integers A in O(n)
// time such that j > i. For example: Let A is an array of integers:
#include <stdio.h>

int largestdiff(int a[], int n){
    int result = a[1] - a[0];
    int min = a[0];

    for(int i = 1; i<n; i++){
       if(a[i] - min > result){
        result = a[i] - min;
       }
       if(a[i] < min){
        min = a[i];
       }
    }
    return result;

    
}

int main(){
    int a[] = {10, 3, 6, 8, 9, 4, 3};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d\n",largestdiff(a,n));
    return 0;
}