// Write a C program to find the sum of contiguous sub-array within a
// one dimensional (1-D) array of numbers which has the largest sum.
// Find the time complexity of your program.
#include <stdio.h>
#include <math.h>

int sumlargestsub(int a[], int n){ 
    int maxsum = a[0];
    int currentsum = a[0];
    for(int i = 1; i< n; i++){
       if(currentsum < 0){
        currentsum = a[i];

       }else{
            currentsum += a[i];
       }
       if(currentsum > maxsum){
        maxsum = currentsum;
       }
    }

    

    return maxsum;
    
}

int main(){
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(a)/sizeof(a[0]);
    int result = sumlargestsub(a,n);
    printf(" largest sum : %d",result);

    return 0;
}