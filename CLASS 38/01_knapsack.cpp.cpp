#include <iostream>
using namespace std;

int knapsack_bottom_up(int *weight, int *price, int n, int total_weight)
{

    int dp[n + 1][total_weight + 1];

    for (int item = 0; item <= n; item++)
    {
        for (int weights = 0; weights <= total_weight; weights++)
        {
            if (item == 0 || weights == 0)
            {
                dp[item][weights] = 0;
            }

            else
            {
                int inc = 0, exc = 0;

                exc = dp[item - 1][weights];

                int curr_weight = weight[item - 1];

                if (weights - curr_weight >= 0)
                {
                    inc = price[item - 1] + dp[item - 1][weights - curr_weight];
                }

                dp[item][weights] = max(inc, exc);
            }
        }
    }

    return dp[n][total_weight];
}

int main()
{
    int n;
    int total_weight;

    cin >> n;
    cin >> total_weight;

    int weight[n];
    int price[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << knapsack_bottom_up(weight, price, n, total_weight);
}