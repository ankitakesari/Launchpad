#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr1[n];
    int arr2[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    vector<int> v;

    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
            j++;
        }

        else if (arr1[i] > arr2[j])
        {
            j++;
        }

        else
        {
            i++;
        }
    }

    if (!v.empty())
    {
        cout << "[";

        for (int a = 0; a < v.size() - 1; a++)
        {
            cout << v[a] << ", ";
        }
        cout << v[v.size() - 1];

        cout << "]";
    }
}