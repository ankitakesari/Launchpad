//Given an array S of size N , check if it is possible to split sequence into two sequences
//s1 to si and si+1 to sN such that first sequence is strictly decreasing and second is strictly increasing.
#include <iostream>
using namespace std;

bool func(int *arr, int n)
{

    int i = 0;
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            i++;
        }

        else
        {
            break;
        }
    }

    //cout << "i: " << i << endl;

    if (i == n - 1 || i == n - 2)
    {
        return true;
    }

    int j = i + 1;
    while (j < n - 1)
    {
        if (arr[j] < arr[j + 1])
        {
            j++;
        }

        else
        {
            break;
        }
    }

    //cout << "j: " << j << endl;

    if (j == n - 1)
    {

        return true;
    }

    else
    {

        return false;
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

    bool result = func(arr, n);

    if (result)
    {
        cout << "true";
    }

    else
    {
        cout << "false";
    }
}