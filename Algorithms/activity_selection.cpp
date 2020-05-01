//activity selection using greedy approach
#include <bits/stdc++.h>
using namespace std;
vector <int> result;

int main() {
    
    int testcase;
    cin>> testcase;
    
    while(testcase>0){
    int n;
    cin>>n;
    vector < pair <int, int> > v;

    int x,y ;
    for(int i=0 ; i<n ; i++){
        // x is start time and y is end time
        cin>> x;
        cin>>y;
        v.push_back(make_pair(y,x));
    }
    
    //sorted according to end time
    sort(v.begin(), v.end());

    int time_comp=v[0].first;
    int activity=1;

    for( int i=1 ; i< v.size(); i++){
        if(v[i].second >= time_comp){
            time_comp=v[i].first;
            activity++;
        }
    }
    result.push_back(activity);

   testcase--;
    
    }
    
    for(int i=0 ; i< result.size(); i++){
        cout<<result[i]<<endl;
    }
}
