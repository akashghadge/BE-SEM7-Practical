
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr,int lo,int mid,int hi){
// set i,j,k to lo,mid+1 and k to 0
int i=lo;
int j=mid+1;
int k=0;
// n size of array B
int n=(hi-lo)+1;
int b[n];
// use while loop until i<= mid and j<=hi
while(i<=mid && j<=hi){
    if(arr[i]<arr[j]){
        b[k]=arr[i];
        i++;
        k++;
    }
    else{
        b[k]=arr[j];
        j++;
        k++;
    }
}
while(i<=mid){
      b[k]=arr[i];
        i++;
        k++;
}
while(j<=hi){
      b[k]=arr[j];
        j++;
        k++;
}
for(int itr : b){
    // important only add from lo 
    arr[lo]=itr;
    lo++;
}
}

// main merge sort function
void MergeSort(vector<int> &arr,int lo,int hi){
    // divide the array into subarrays util array has single element by half -half
    if(lo<hi){
        int mid=(lo+hi)/2;
        MergeSort(arr,lo,mid);
        MergeSort(arr,mid+1,hi);
        Merge(arr,lo,mid,hi);
    }
}
           
int main(){
    vector<int> arr={1,5,3,4,2};
    int n=arr.size();
    MergeSort(arr,0,n);
    for(auto i:arr){
        cout<<i<<" ";
    }
  return 0;
}