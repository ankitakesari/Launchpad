//Inverting digit t means replacing it with digit 9 - t.
//transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits.
//The decimal representation of the final number shouldn't start with a zero.

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int x = str[0] - '0';
    if ((9 - x < x) && (9 - x != 0))
    {
        char ch = '0' + (9 - x);
        str[0] = ch;
    }

    for (int i = 1; i < str.length(); i++)
    {
        int x = str[i] - '0';

        if ((9 - x) < x)
        {
            char ch = '0' + (9 - x);
            str[i] = ch;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
}
