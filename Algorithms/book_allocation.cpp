#include <iostream>
using namespace std;

bool possible_allo(int *arr, int n, int m, int target)
{
    int pages = 0;
    int students = 1;

    for (int i = 0; i < n; i++)
    {

        if (pages + arr[i] > target)
        {
            students++;
            pages = arr[i];
            if (students > m)
            {
                return false;
            }
        }
        else
        {
            pages += arr[i];
        }
    }
    return true;
}

int book_allo(int *arr, int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int start = arr[n - 1];

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    int end = total;
    int mid = 0;
    int ans = INT_MAX;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (possible_allo(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    //n is the number of books
    //m is the number of students

    int n;
    int m;
    cin >> n;
    cin >> m;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min_pages = book_allo(arr, n, m);
    cout << min_pages;
}