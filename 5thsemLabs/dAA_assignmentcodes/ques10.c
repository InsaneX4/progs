#include<stdio.h>

int powr(int x , int y){

    if(y == 0) return 1;
    else{
    return x * powr(x, y-1);
    }
    
}


int main(){

    int x = 3;
    int y = 2;
    printf("%d Power of %d: %d\n",y,x,powr(x,y));
    return 0;
}