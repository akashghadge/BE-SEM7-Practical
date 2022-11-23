
#include<bits/stdc++.h>
using namespace std;

int ZeroOneKnapsack(int W,vector<int> vals,vector<int> wts){
  int n = vals.size();
  vector<vector<int>> dp(n+1,vector<int>(W+1));

  for(int i=0;i<vals.size()+1;i++){
    for(int j=0;j<W+1;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else{
        // if curr wt of bag is more or equal than wt of item then only take come in picture
        if(j>=wts[i-1]){
          // in take remaining wt value + curr value || cricket match if player play condition
          int take = dp[i-1][j-wts[i-1]]+vals[i-1];
          // previous value || if player not play
          int notTake = dp[i-1][j];
          dp[i][j]=max(take,notTake);
        }else{
          // else previous value
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  // loop for printing dp
  // for(auto row : dp){
  //   for(auto col : row){
  //     cout<<col<<" ";
  //   }
  //   cout<<endl;
  // }
  return dp[n][W];
}

int main(){
int W = 50;
vector<int> weight = {10,20,30};
vector<int> values = {60,100,120};
// ans = 220
cout<<ZeroOneKnapsack(W,values,weight);
  return 0;
}