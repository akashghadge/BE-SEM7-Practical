//Cpp code to demonstrate naive
//method to compute gcd ( recursion )

#include<bits/stdc++.h>
using namespace std;

int hcfnaive(int a,int b){
    if(b==0) return abs(a);
    else return hcfnaive(b, a % b);
}
           
int main(){
    cout<<"The gcd of 60 and 48 is : ";
    cout<<hcfnaive(60,48)<<endl;
  return 0;
}