#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int largest(int a[], int n){

    if(n == 1) return a[0];

    return max(a[n-1], largest(a, n-1));
    

}

int main(){
    int a[] = {0,1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    printf("largest element of array %d\n", largest(a,n));
    return 0;
}