#include <stdio.h>
#include <stdlib.h>

int sumofnum(int n){

    if(n==0) return n;
    else
    return n + sumofnum(n-1);
}

int main(){
    int n = 10;
    printf("Sum of th numbers: %d\n",sumofnum(n));
    return 0;
}