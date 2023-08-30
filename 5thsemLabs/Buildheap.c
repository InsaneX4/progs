#include <stdio.h>
void heapify(int a[], int n, int i){
    int lc = 2*i+1;
    int rc = 2*i+2;
    int gt = i;
    if(lc < n && a[lc] > a[gt])
        gt = lc;
    if(rc < n && a[rc] > a[gt])
        gt = rc;
    if(gt != i){
        int temp = a[i];
        a[i] = a[gt];
        a[gt] = temp;
        heapify(a,n,gt);
    }

}
void buildheap(int a[], int n){
   for(int i = n/2-1; i >= 0; i--)
        heapify(a,n,i);
}

void showheap(int a[], int n){
    int i;
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

int delete_element(int a[], int n, int target){
    int temp = a[0];
    a[0] = a[n-1];
    n--;
    heapify(a,n,0);
}

void insert_element(int a[], int n, int target){
    a[n] = target;
    n++;
    int j = 0;
    int i = n -1;
    
    while(i > j){
        j = (i+1)/2 - 1;
        if(a[j] < a[i]){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i = j;
        }
        else
            break;
    }
}

void heapsort(int a[], int n){
    while(n>1){
        int temp = a[0];
        a[0] = a[n-1];
        a[n-1] = temp;
        n--;
        heapify(a,n,0);
    }
}

int main(){

    int a[] = {0,1,2,3,4,5,6,7};
    int n = sizeof(a) / sizeof(a[0]);
    buildheap(a, n);
    showheap(a, n);
    delete_element(a, n, 3);
    showheap(a, n);
    insert_element(a, n, 3);
    showheap(a, n);
    heapsort(a, n);
    showheap(a, n);
}
// why it is -169559696 number in the end?

