// n is the amount , we have to reduce amount to one
// there are three operations
// divide by 3 , divide by 2, reduce 1
#include <iostream>
using namespace std;

int min_steps_to_one(int n)
{
    if (n == 1)
    {
        return 0;
    }

    int div_3 = INT_MAX;
    int div_2 = INT_MAX;
    int sub_1 = INT_MAX;

    if (n % 3 == 0)
    {
        div_3 = min_steps_to_one(n / 3);
    }

    if (n % 2 == 0)
    {
        div_3 = min_steps_to_one(n / 2);
    }

    sub_1 = min_steps_to_one(n - 1);

    int steps = 1 + min(sub_1, min(div_3, div_2));

    return steps;
}

//int memo[1000] = {0};
int min_steps_to_one_top_down(int n, int *memo)
{
    if (n == 1)
    {
        return 0;
    }

    if (memo[n] != 0)
    {
        return memo[n];
    }

    int div_3 = INT_MAX;
    int div_2 = INT_MAX;
    int sub_1 = INT_MAX;

    if (n % 3 == 0)
    {
        div_3 = min_steps_to_one_top_down(n / 3, memo);
    }

    if (n % 2 == 0)
    {
        div_3 = min_steps_to_one_top_down(n / 2, memo);
    }

    sub_1 = min_steps_to_one_top_down(n - 1, memo);

    int steps = 1 + min(sub_1, min(div_3, div_2));

    memo[n] = steps;

    return memo[n];
}

int min_steps_to_one_bottom_up(int n)
{
    int dp[n + 1] = {0};

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        int div_3 = INT_MAX;
        int div_2 = INT_MAX;
        int sub_1 = INT_MAX;

        if (i % 3 == 0)
        {
            div_3 = dp[i / 3];
        }

        if (i % 2 == 0)
        {
            div_2 = dp[i / 2];
        }

        sub_1 = dp[i - 1];

        int steps = 1 + min(sub_1, min(div_3, div_2));

        dp[i] = steps;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int steps = min_steps_to_one(n);
    cout << steps << endl;

    int memo[n + 1] = {0};
    cout << min_steps_to_one_top_down(n, memo) << endl;

    cout << min_steps_to_one_bottom_up(n);
}