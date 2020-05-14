#include <iostream>
#include <string>
using namespace std;

int longest_common_subseq(string str1, string str2)
{
    if (str1.length() == 0 || str2.length() == 0)
    {
        return 0;
    }

    if (str1[0] == str2[0])
    {
        return 1 + longest_common_subseq(str1.substr(1), str2.substr(1));
    }

    else
    {
        return max(longest_common_subseq(str1, str2.substr(1)), longest_common_subseq(str1.substr(1), str2));
    }
}

int dp[100][100] = {0};

int longest_common_subseq_top_down(string str1, string str2)
{
    if (str1.length() == 0 || str2.length() == 0)
    {
        return 0;
    }

    if (dp[str1.size()][str2.size()] != -1)
    {
        return dp[str1.size()][str2.size()];
    }

    int ans = 0;
    if (str1[0] == str2[0])
    {
        ans = 1 + longest_common_subseq_top_down(str1.substr(1), str2.substr(1));
    }

    else
    {
        ans = max(longest_common_subseq_top_down(str1, str2.substr(1)), longest_common_subseq_top_down(str1.substr(1), str2));
    }

    dp[str1.size()][str2.size()] = ans;

    return ans;
}

int longest_common_subseq_bottom_up(string str1, string str2)
{
    int dp[100][100] = {0};

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

    return dp[str1.length()][str2.length()];
}

int main()
{
    string str1 = "acfgh";
    string str2 = "bcdegf";

    cout << longest_common_subseq(str1, str2) << endl;

    for (int i = 0; i <= str1.length(); ++i)
    {
        for (int j = 0; j <= str2.length(); ++j)
        {
            dp[i][j] = -1;
        }
    }

    cout << longest_common_subseq_top_down(str1, str2) << endl;
    cout << longest_common_subseq_bottom_up(str1, str2);

    return 0;
}