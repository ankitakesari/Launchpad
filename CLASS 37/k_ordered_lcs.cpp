#include <iostream>
#include <string>
using namespace std;

int dp[100][100][100];

int k_ordered_lcs(string s1, string s2, int i, int j, int k, int len1, int len2)
{
    if (i == len1 || j == len2)
    {
        return 0;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    int ans = 0;

    if (s1[i] == s2[j])
    {
        ans = 1 + k_ordered_lcs(s1, s2, i + 1, j + 1, k, len1, len2);
    }

    else
    {
        int case1 = k_ordered_lcs(s1, s2, i + 1, j, k, len1, len2);
        int case2 = k_ordered_lcs(s1, s2, i, j + 1, k, len1, len2);

        int case3 = -1;
        if (k > 0)
        {
            case3 = 1 + k_ordered_lcs(s1, s2, i + 1, j + 1, k - 1, len1, len2);
        }

        ans = max(case1, max(case2, case3));
    }

    dp[i][j][k] = ans;
    return ans;
}

int main()
{
    int k = 2;
    // string str1 = "abcde";
    // string str2 = "bleg";

    string str1 = "abcdgh";
    string str2 = "cgjkhlo";

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << k_ordered_lcs(str1, str2, 0, 0, k, str1.length(), str2.length());
}