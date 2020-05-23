//You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.
#include <iostream>
#include <vector>
using namespace std;

vector<int> results;

int count_binary_string(int n)
{
    if (n == 1)
    {
        return 2;
    }
    int dp[2][n + 1] = {0};

    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }

    return (dp[0][n] + dp[1][n]);
}

int main()
{
    int testcases;
    cin >> testcases;

    while (testcases > 0)
    {
        int n;
        cin >> n;

        results.push_back(count_binary_string(n));

        testcases--;
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}