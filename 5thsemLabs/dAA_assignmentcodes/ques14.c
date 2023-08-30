#include<stdio.h>

int length(char a[], int i){

    static int l = 0;


    if(a[i] == '\0'){
        return l;
    }else{
        l++;
        length(a,i+1);
    }
    
   
}

int main(){

    char a[] = "Helloworld";
    
    printf("%d\n", length(a,0));
    return 0;
}