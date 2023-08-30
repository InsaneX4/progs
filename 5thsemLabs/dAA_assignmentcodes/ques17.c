#include<stdio.h>

int sumdigits(int n){
    if(n == 0) return 0;
    return n%10 + sumdigits(n/10);

}

int main(){
    int n = 35178;
    printf("%d\n", sumdigits(n));
    return 0;
}