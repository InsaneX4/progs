// 3. Find the GCD and LCM of n numbers where (n&gt;=2).

#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(){
    
   int n;
   printf("number of elements: \n");
   scanf("%d",&n);
    if(n < 2){
        printf("n should be greater than 3");
        exit(1);
    }
    int arr[n];
    printf("Enter n number: of elements%d\n",n);
    for(int i = 0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    int result_gcd = gcd(arr[0],arr[1]);
    int result_lcm = gcd(arr[0],arr[1]);

    for(int i = 2; i<n; i++){
    int result_gcd = gcd(result_gcd,arr[i]);
    int result_lcm = gcd(result_lcm,arr[i]);
    }
    printf("GCD: %d\n", result_gcd);
    printf("LCM:  %d\n",result_lcm);

    return 0;
}