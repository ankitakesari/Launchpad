#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void longest_common_subseq_bottom_up(string str1, string str2)
{
    int dp[1001][1001] = {0};

    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = str1.length();
    int j = str2.length();

    string op = "";
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            op += str1[i - 1];
            i--;
            j--;
        }

        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }

        else
        {
            i--;
        }
    }

    reverse(op.begin(), op.end());
    cout << op;
}

int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;

    longest_common_subseq_bottom_up(str1, str2);

    return 0;
}