#include<stdio.h>

void rev(char *a){
    if(*a){
        rev(a+1);
        printf("%c",*a);
    }
}


int main(){

    char a[] = "Helloworld";


        rev(a);
        printf("\n");
    

    return 0;
}