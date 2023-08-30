#include<stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(int argv,char *argc[]){
	int dig1=atoi(argc[1]);
	int dig2=atoi(argc[2]);
	printf("Values before Swapping is a=%d , b=%d\n",dig1,dig2);
	swap(&dig1,&dig2);
	printf("Values after Swapping is a=%d , b=%d\n",dig1,dig2);
	return 0;
}


