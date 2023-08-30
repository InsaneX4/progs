#include <stdio.h>


int fibno(int n){
    if(n == 0) return 0;

    else if(n == 1) return 1;

    else{
        return (fibno(n-1) + fibno(n-2));
    }

}

int main(){
    int n = 8;
    printf("%d\n", fibno(n));

    return 0;
}