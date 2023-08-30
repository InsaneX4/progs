#include<stdio.h>

int fact(int n){

    if(n == 0){
        return 1;
    }else{
    return n * fact(n-1);
    }
}
int main(){
    int n = 5;
    printf("The fact of the number is: %d\n", fact(n));

    return 0;
}