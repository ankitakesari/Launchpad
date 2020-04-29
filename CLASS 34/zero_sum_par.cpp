//find two numbers whose sum is equal to 0

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool zero_sum_pair(int *arr, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int to_get = -1 * arr[i];

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
    int n = 10;
    //all numbers are unique
    int arr[n] = {5, 2, 9, 7, 4, 0, 12, 54, -2, 3};

    if (zero_sum_pair(arr, n))
    {
        cout << "pair with sum zero exists";
    }

    else
    {
        cout << "pair with sum zero doesn't exist";
    }
}