//there n wine bottles
//you can only sell one wine bottle in a year
//price of wine bottle varies as new price= original price * year in which it is sold
//only bottle at the first or last position can be sold
//maximise the profit
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int years = n;

    int dp[n][n] = {0};

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i] * years;
    }

    years--;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int start = j;
            int end = i + j;

            dp[j][i + j] = max((arr[start] * years + dp[start + 1][end]), (arr[end] * years + dp[start][end - 1]));
        }
        years--;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    cout << "max profit: " << dp[0][n - 1];
}