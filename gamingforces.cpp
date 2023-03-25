#include<iostream>
using namespace std;

void spell1(int *arr , int x,int *countZeros){
    int count = 0;
    for(int i = 0;i<x;i++){
        if(count != 2){
        if(arr[i] != 0){
            arr[i]--;
            count++;
            if(arr[i] == 0){
                countZeros++;
            }
        } 
        }
    }
    
}
void spell2(int *h, int n,int *countZeros){
    for(int i=0;i<n;i++){
        if(h[i] != 0){
        h[i] = 0;
        if(h[i] == 0){
            countZeros++;
        }
        break;
        } 
        
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
    int countZeros = 0;
    int n = 0;
    cout<<"Enter number of monster"<<endl;
    cin>>n;
    cout<<"n="<<n<<endl;
    int h[n]; 
    for(int i =0 ;i<n;i++){
       cin>>h[i];
    }
    int countspell = 0;
    while(countZeros != n){
        if(countZeros == n-1){
            spell2(h,n,&countZeros);
            countspell++;
        }
            spell1(h,n,&countZeros);
            spell2(h,n,&countZeros);
            countspell+2;
            
    }
    cout<<countZeros<<endl;

    }

    return 0;
}