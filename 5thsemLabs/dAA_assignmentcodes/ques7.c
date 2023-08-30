#include<stdio.h>

int revesNum(int num1, int num2) {
    if(num1 == 0){
        return num2;
    }
    num2 *= 10;
    num2 += (num1 % 10);
    num1 = num1/10;
    return revesNum(num1, num2);
}

int main(){
    
   int Num = 1345431;
   int Num2 = revesNum(Num, 0);
   if(Num == Num2){
    printf("%d is plindrome!",Num);
   }else{
    printf("%d is not a plindrome!",Num);
   }


    return 0;
}