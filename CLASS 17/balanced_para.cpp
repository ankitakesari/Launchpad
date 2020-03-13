#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
        }

        if (str[i] == ')')
        {
            st.pop();
        }
    }

    if (st.empty())
    {
        cout << "balanced";
    }
    else
    {
        cout << "not balanced";
    }
}