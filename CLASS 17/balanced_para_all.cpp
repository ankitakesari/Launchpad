#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }

        else if (str[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }

            else
                return false;
        }
        else if (!st.empty() && str[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }

            else
                return false;
        }
        else if (!st.empty() && str[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }

            else
                return false;
        }
    }

    return (st.empty());
}

int main()
{

    string exp = "(a+b)+{(c+d)*(E+f)}+[g+h]";

    if (is_balanced(exp))
    {
        cout << exp << " is balanced";
    }

    else
    {
        cout << exp << " is not balanced";
    }
}