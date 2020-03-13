//Actually, the two sticks in a pair of chopsticks need not be of the same length.
//A pair of sticks can be used to eat as long as the difference in their length is at most D.
// The Chef has N sticks in which the ith stick is L[i] units long.
// A stick can't be part of more than one pair of chopsticks.
//Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.

//https://www.codechef.com/problems/TACHSTCK

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    int d;
    cin >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int count = 0;
    int i = 0;
    while (i < n - 1)
    {
        if ((arr[i + 1] - arr[i]) <= d)
        {
            count++;
            i = i + 2;
        }

        else
        {
            i++;
        }
    }

    cout << count;
}