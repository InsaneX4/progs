#include <stdio.h>
int Sum(int arr[], int n, int s){
 if (n==0){
return s;
 }
else {
 return Sum(arr, n-1, s+arr[n-1]);
 }
}
int main(){
 printf("Enter range of array: ");
 int n;
 scanf("%d", &n);
 int arr[n];
 printf("Enter %d elements for the array: ", n);
 for (int i=0; i<n; i++){   
    scanf("%d", &arr[i]);
     }
    printf("The sum of all numbers using recursion = %d.", Sum(arr, n, 0));
}
