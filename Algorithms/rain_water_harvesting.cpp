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

    int left_max[n] = {0};
    int right_max[n] = {0};
    left_max[0] = arr[0];
    right_max[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }
    int result = 0;

    for (int i = 1; i < n - 1; i++)
    {
        result += min(left_max[i], right_max[i]) - arr[i];
    }

    cout << result;
}