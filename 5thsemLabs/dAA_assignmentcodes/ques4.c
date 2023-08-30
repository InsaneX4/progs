#include <stdio.h>
int mul(int a, int b) { 

    if(b == 0) return 0;

    else {
        return a + mul(a,b-1);
    }


}

int main(){
    int a = 2;
    int b = 10;
    printf("multplication: %d\n",mul(a,b));
    return 0;

}