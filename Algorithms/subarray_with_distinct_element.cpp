//Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct


#include <iostream>
#include<unordered_map>
using namespace std;

int distinct_subarray(int* arr, int n){
    int till_now[n];
    till_now[0]=-1;
    unordered_map<int,int> mp;
    mp[arr[0]]=0;

    for(int i=1; i<n ; i++){
        till_now[i]=till_now[i-1];

          if(mp.find(arr[i])!=mp.end()){
              till_now[i]=max(till_now[i],mp[arr[i]]);
          }

          mp[arr[i]]=i;
    }

    int total=0;

    for(int i=0 ; i<n ; i++){
       // cout<<till_now[i]<<",";
        int count= i-till_now[i];
        int r= (count *( count+1))/2;
        total+=r;
        total%=1000000007;
    }

    return total;
}

int main() {
    long long int n;
    cin>>n;
    int arr[n];

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
// int n=6;
// int arr[n]={5, 2, 3, 5, 4, 3};
    int total_length=distinct_subarray(arr, n);
    cout<<total_length;
}
