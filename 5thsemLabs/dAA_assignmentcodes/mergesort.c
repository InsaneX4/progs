#include <stdio.h>

void merge(int a[], int l , int m, int h){
    int i = l;
    int j = m+1;
    int k = 0;
    int b[h-l+1];
    while(i <= m && j <= h){
    if(a[i] < a[j]){
        b[k] = a[i];
        i++; 
    }else{
        b[k] = a[j];
        j++; 
    }
    k++;
    }
    while(i <= m){
        b[k] = a[i];
        i++; k++;
    }
    while(j <= h){
        b[k] = a[j];
        k++;
         j++;
    }
     for (int x = 0; x < k; x++) {  // Copy elements from b[] back to a[]
        a[l + x] = b[x];
    }
}



void mergesort(int a[], int l, int h){

    if(l< h){
        int m = (h+l)/2;
        mergesort(a, l, m);
        mergesort(a, m+1,h);
        merge(a,l,m,h);
    }

}

int main(){

    int a[] = {5, 87, 99, 43, 35 , 18};
    int n = sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);

     for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}