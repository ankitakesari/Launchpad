#include <iostream>
using namespace std;

int kadane_algo(int *arr, int n)
{
    int max_till_now = INT_MIN;

    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr > max_till_now)
        {
            max_till_now = curr;
        }

        if (curr < 0)
        {
            curr = 0;
        }
        // cout << "curr" << curr << "  "
        //      << "max:" << max_till_now;
        //cout << endl;
    }

    return max_till_now;
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

    int without_wrapping = kadane_algo(arr, n);

    //substracting maximum negative contribution
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        arr[i] = -arr[i];
    }

    int neg_cont = kadane_algo(arr, n);
    int with_wrapping = total_sum + neg_cont;

    cout << max(with_wrapping, without_wrapping);
}