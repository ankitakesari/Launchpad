//find two numbers whose sum is equal to target

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool target_sum_pair(int *arr, int n, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int to_get = target - arr[i];

        if (mp.count(to_get))
        {
            cout << arr[i] << "  " << to_get << endl;
            return true;
        }

        else
        {
            mp[arr[i]] = i;
        }
    }

    return false;
}

int main()
{
    int n = 9;

    int arr[n] = {5, -2, 3, 8, 5, 0, 12, 54, 2};
    int target = 7;

    if (target_sum_pair(arr, n, target))
    {
        cout << "pair with target sum exists";
    }

    else
    {
        cout << "pair with target sum doesn't exist";
    }
}