#include<stdio.h>

int main(){
int a=258;
char *c=(char *)&a;
printf("Byte 1 is %d \n",(int)*c);
printf("Byte 2 is %d \n",(int)*(c+1));
printf("Byte 3 is %d \n",(int)*(c+2));
printf("Byte 4 is %d \n",(int)*(c+3));
return 0;
}
