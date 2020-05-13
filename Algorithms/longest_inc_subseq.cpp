#include <iostream>
using namespace std;

int longest_inc_subseq(int n, int *arr)
{
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }

    int max_length = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return max_length;
}

int main()
{
    int n = 6;
    int arr[6] = {50, 3, 10, 7, 40, 50};

    cout << longest_inc_subseq(n, arr);

    return 0;
}