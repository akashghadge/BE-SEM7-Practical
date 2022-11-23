 
 
#include<bits/stdc++.h>
using namespace std;
           
vector<vector<int>> matmult(vector<vector<int>> m1,vector<vector<int>> m2){
    int n = m1.size();
    int m = m2[0].size();
    vector<vector<int>> res(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m2.size();k++){
                res[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return res;
}
// [114, 160, 60, 27]
// [74, 97, 73, 14]
// [119, 157, 112, 23]
void print(vector<vector<int>> res){
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
           
int main(){
      vector<vector<int>> m1 = {{12,7,3},{4,5,6},{7 ,8,9}};
      vector<vector<int>> m2 = {{5,8,1,2},{6,7,3,0},{4,5,9,1}};
      vector<vector<int>> ans = matmult(m1,m2);
      print(ans);
  return 0;
}