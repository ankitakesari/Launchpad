#include <bits/stdc++.h>
using namespace std;

int longest_inc_subseq(int n, int *arr)
{
    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int curr_ele = arr[i];

        auto id = lower_bound(v.begin(), v.end(), curr_ele);

        if (id == v.end())
        {
            v.push_back(arr[i]);
        }

        else
        {
            *id = curr_ele;
        }
    }

    return v.size();
}

int main()
{
    int n = 6;
    int arr[6] = {50, 3, 10, 7, 40, 50};

    cout << longest_inc_subseq(n, arr);

    return 0;
}