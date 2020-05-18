//Given an array arr of n length.
//You will be given Q queries for the array.
//Each query contains a number N.You have to determine whether a number exist in the array or not

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase > 0)
    {
        unordered_map<int, int> mp;

        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = i;
            }
        }

        vector<string> v;
        int Q;
        cin >> Q;

        for (int i = 0; i < Q; i++)
        {
            int x;
            cin >> x;

            if (mp.find(x) == mp.end())
            {
                v.push_back("No");
            }

            else
            {
                v.push_back("Yes");
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
        testcase--;
    }
}