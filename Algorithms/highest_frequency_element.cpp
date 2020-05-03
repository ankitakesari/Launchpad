// find the most frequent element in the array

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map <int ,int> mp;
    int highest_key=INT_MIN;
    int highest_val;
    int n;
    cin>>n;

    int arr[n];

    for(int i=0 ; i<n ;i++){
        cin>> arr[i];
    }

     for(int i=0 ; i<n ;i++){
        if(mp.count(arr[i])){
            mp[arr[i]]++;
        }

        else{
            mp[arr[i]]=1;
        }
    }

    for (auto i : mp) { 
        if (highest_val < i.second) { 
            highest_key = i.first; 
            highest_val = i.second; 
        } 
    } 

    cout<<highest_key;
    
}
