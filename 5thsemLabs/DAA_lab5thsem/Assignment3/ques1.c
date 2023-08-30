#include <stdio.h>

void binarys(int a[], int l, int r, int x){
    int ans = 0;
    int count = 0;
    while(l<= r){
        int mid = l + (r-l)/2;
        if(a[mid] == x) ans = mid;
        
        if(a[mid] < x) l = mid +1;
        
        else r = mid -1;
        
        count++;
    }
    printf("%d found at index position %d\n",x,ans);
    printf("Number of comparisons: %d",count);
}

int main()
{
    int a[] = {2, 3, 7, 7, 7, 11, 12, 12, 20 ,50 };
    
    int n = sizeof(a)/sizeof(a[0]);
    int x = 7;
    binarys(a,0,n-1,x);
    

    return 0;
}