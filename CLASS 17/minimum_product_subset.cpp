// find minimum possible product from the subsets of an array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimum_product(int *arr, int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int no_of_zero = 0;
    int no_of_neg = 0;
    int product = 1;
    int max_neg = INT_MIN;
    int min_pos = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            no_of_zero++;
        }

        else if (arr[i] < 0)
        {
            product *= arr[i];
            no_of_neg++;
            if (arr[i] > max_neg)
            {
                max_neg = arr[i];
            }
        }

        else
        {
            product *= arr[i];
            if (arr[i] < min_pos)
            {
                min_pos = arr[i];
            }
        }
    }

    //cout << "max neg : " << max_neg << endl;

    if (no_of_neg == 0)
    {
        if (no_of_zero > 0)
        {

            return 0;
        }

        else
        {

            return min_pos;
        }
    }

    else
    {
        if (no_of_neg & 1)
        {

            return product;
        }

        else
        {

            return (product / max_neg);
        }
    }
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

    int product = minimum_product(arr, n);

    cout << "minimum in all possible subset: " << product;

    return 0;
}