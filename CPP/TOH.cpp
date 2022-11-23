 
 //Recursive cpp function to solve the tower of hanoi
#include<bits/stdc++.h>
using namespace std;
           
void TowerOfHanoi(int n ,char source,char destination,char auxiliary){
	if(n==0){
		cout<<"Move disk 1 from source "<<source<<" to destination "<<destination<<endl;
		return;
    }
	TowerOfHanoi(n-1, source, auxiliary, destination);
	cout<<"Move disk "<<n<<" from source "<<source<<" to destination "<<destination<<endl;
	TowerOfHanoi(n-1, auxiliary, destination, source);
}
int main(){
      int n = 4;
      TowerOfHanoi(n,'A','B','C');
      //A, C, B are the name of rods
  return 0;
}


