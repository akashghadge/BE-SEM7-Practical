 
 
#include<bits/stdc++.h>
using namespace std;
           
bool isPrime(int n){
     if(n>1){
        for(int i=2;i<=(n/2);i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
     }
     return 1;
}
           
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    if(isPrime(n)) cout<<n<<" is Prime Number"<<endl;
    else cout<<n<<" is Not Prime Number"<<endl;
  return 0;
}