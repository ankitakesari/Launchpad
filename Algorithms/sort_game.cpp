//arrange the list in such a manner that the list is sorted in decreasing order of salary. 
//And if two employees have the same salary, they should be arranged in lexicographical manner 
//the list should contain only names of those employees having salary greater than or equal to a given number x.

#include <bits/stdc++.h>
using namespace std;

bool myfunc(pair< string ,int > p1, pair <string ,int > p2){
    if (p1.second != p2.second){
        return p1.second > p2.second;
    }

    else {
        return p1.first< p2.first;
    }
}


int main() {
  //limit is x 
    int limit;
    cin>>limit ;
    int n;
    cin>> n;

    vector < pair< string , int > > v;

    for( int i =0 ; i< n; i++){
        string name;
        cin>> name;
        int salary;
        cin>> salary;

        v.push_back( make_pair(name, salary));

    }

    sort(v.begin(), v.end(), myfunc);

    int i=0;
    while(v[i].second >=limit){
        cout<<v[i].first <<" "<< v[i].second;
        cout<<endl;
        i++;
    }

}
