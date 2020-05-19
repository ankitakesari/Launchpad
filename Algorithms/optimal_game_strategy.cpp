//Piyush and Nimit are playing a coin game.
//They are given n coins with values x1, x2 …. xn where 'n' is always even.
//They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row.
//The value of coin is received by that player.
// Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

#include <iostream>
using namespace std;

int memo[30][30] = {0};
int func(int *arr, int n, int start, int end)
{
    if (end - start == 1)
    {
        return max(arr[start], arr[end]);
    }

    int a = 0, b = 0, c = 0;
    //finding a
    if (memo[start + 2][end] != 0)
    {
        a = memo[start + 2][end];
    }
    else
    {
        a = func(arr, n, start + 2, end);
    }

    //finding b
    if (memo[start + 1][end - 1] != 0)
    {
        b = memo[start + 1][end - 1];
    }
    else
    {
        b = func(arr, n, start + 1, end - 1);
    }

    //finding
    if (memo[start][end - 2] != 0)
    {
        c = memo[start][end - 2];
    }
    else
    {
        c = func(arr, n, start, end - 2);
    }

    int way1 = arr[start] + min(a, b);

    int way2 = arr[end] + min(b, c);

    memo[start][end] = max(way1, way2);

    return memo[start][end];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << func(arr, n, 0, n - 1);
}