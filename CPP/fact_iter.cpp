//Cpp program to find the factorial of a number provided by the user.

//num = 7

//To take input from the user

#include<bits/stdc++.h>
using namespace std;
           
void fact_iterative(int n){
    int fact = 1;
     if(n<0) {
        cout<<"Sorry, factorial does not exist for negative numbers"<<endl;
     }
     else if(n==0){
        cout<<"The factorial of 0 is 1"<<endl;
     }
     else{
        for(int i=1;i<=n;i++){
            fact = fact*i;
        }
     }
     cout<<"The factorial of "<<n<<" is "<<fact<<endl;
}
           
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    fact_iterative(n);
  return 0;
}

