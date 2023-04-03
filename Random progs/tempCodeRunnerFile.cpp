#include<iostream>
using namespace std;
class Test{
int *p;
public:
Test(){
p = new int(1);}
Test(int *k){
p = new int(*k);}
void Show(){
cout<<*p;}
};
int main(){
static int i;
Test t1, t2;
t1.Show();
cout<<"\n";
t2.Show();
return 0;
}