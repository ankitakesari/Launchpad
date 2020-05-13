#include <iostream>
using namespace std;

int max_profit_rod_cut(int n, int *arr)
{

    if (n == 0)
    {
        return 0;
    }
    int max_profit = 0;

    for (int i = 1; i <= n; i++)
    {
        int curr_profit = arr[i] + max_profit_rod_cut(n - i, arr);
        max_profit = max(max_profit, curr_profit);
    }
    return max_profit;
}

int max_profit_rod_cut_top_down(int n, int *arr, int *store)
{

    if (n == 0)
    {
        return 0;
    }
    int max_profit = 0;

    if (store[n] != -1)
    {
        return store[n];
    }

    for (int i = 1; i <= n; i++)
    {
        int curr_profit = arr[i] + max_profit_rod_cut(n - i, arr);
        max_profit = max(max_profit, curr_profit);
    }

    store[n] = max_profit;
    return max_profit;
}

int max_profit_rod_cut_bottom_up(int n, int *arr)
{
    int dp[n] = {0};

    for (int i = 1; i <= n; i++)
    {
        int curr_profit = 0;

        for (int j = 1; j <= i; j++)
        {
            curr_profit = max(curr_profit, arr[j] + arr[i - j]);
        }

        dp[i] = curr_profit;
    }

    return dp[n];
}

int main()
{
    int n = 8;
    int arr[10] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int store[n + 1];

    for (int i = 0; i <= n; i++)
    {
        store[i] = -1;
    }

    cout << max_profit_rod_cut(8, arr) << endl;
    cout << max_profit_rod_cut_top_down(8, arr, store) << endl;
    cout << max_profit_rod_cut_bottom_up(8, arr);
}