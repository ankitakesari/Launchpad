//find two numbers whose sum is equal to target

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool subarray_with_sum_zero(int *arr, int n)
{
    unordered_map<int, int> mp;

    int prefix_sum = 0;

    for (int i = 0; i < n; i++)
    {
        prefix_sum = 0;

        if (prefix_sum == 0 || (mp.count(prefix_sum) && mp[prefix_sum] != i))
        {

            return true;
        }

        mp[prefix_sum] = i;
    }

    return false;
}

int main()
{
    int n = 6;

    int arr[6] = {3, 2, 4, -2, -2, -5};

    if (subarray_with_sum_zero(arr, n))
    {
        cout << "subarray with sum 0 exists";
    }

    else
    {
        cout << "subarray with sum 0 doesn't exists";
    }
}