//Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

#include <iostream>
#include <string>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    unordered_map<char, int> mp;

    for (int i = 0; i < str.length(); i++)
    {
        if (mp.find(str[i]) != mp.end())
        {
            mp[str[i]]++;
        }

        else
        {
            mp[str[i]] = 1;
        }
    }
    pair<char,int> p;
    p=make_pair('a',0);
    
    for(auto i= mp.begin() ; i!=mp.end(); i++){
        if(i->second> p.second){
            p.first=i->first;
            p.second=i->second;
        }
    }
    
    cout<<p.first;
}
