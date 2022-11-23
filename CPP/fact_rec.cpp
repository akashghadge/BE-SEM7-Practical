 
 
#include<bits/stdc++.h>
using namespace std;
           
int fact_rec(int n){
     if(n<0) return -1;
     else if(n==0) return 1;
     return n*fact_rec(n-1);
}
           
int main(){
    cout<<fact_rec(5);
  return 0;
}