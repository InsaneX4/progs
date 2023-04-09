#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

            double x = 15;
            double p = 20;
            double y = 10;
            //cin >> x >> p;
            double mp = (p*100)/(100-x);
            //mp = round((mp*100))/100;
         cout << fixed << setprecision(2) << mp;
    return 0;
}