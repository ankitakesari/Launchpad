//If the sum of any of the subset is zero, then print “Yes” (without quotes) else print “No”(without quotes).

//The first line contains an integer T, which is the total number of test cases.
//T test cases follow.
//Each test case consists of two lines.
//The first line consists of a single integer N, which is the number of elements present in the set A.
//The second line contains N space separated integers denoting the elements of the set A.
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;

vector<int> v;

void func(int n, int *arr, int sum)
{
    if (n == 0)
    {
        v.push_back(sum);
        return;
    }

    func(n - 1, arr + 1, sum + arr[0]);
    func(n - 1, arr + 1, sum);
}

int main()
{

    int testcase;
    cin >> testcase;
    while (testcase > 0)
    {
        int n;
        cin >> n;
        int arr1[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        int maxocc = pow(2, n);

        int sum = 0;
        func(n, arr1, sum);

        int count = 0;
        for (int x = 0; x < v.size(); x++)
        {
            if (v[x] == 0)
                count++;
        }

        if (count > 1)
        {
            cout << "Yes" << endl;
        }

        else
        {
            cout << "No" << endl;
        }
        v.clear();
        testcase--;
    }
}