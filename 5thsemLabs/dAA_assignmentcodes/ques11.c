#include<stdio.h>

int binarys(int a[], int l, int h, int x){
    if(h >= l){
        int m = l + (h-l)/2;

        if(a[m] == x) return m;

        if(a[m] > x) binarys(a, l, m-1, x);

        
        return binarys(a, m+1, h, x);
    }

    return -1;
}

int main(){

    int a[] = {10, 23, 50, 20, 40};
    int x = 50;

    int n = sizeof(a)/sizeof(a[0]);
    printf("%d found at index %d\n",x,binarys(a,0,n-1,x));

    return 0;
}