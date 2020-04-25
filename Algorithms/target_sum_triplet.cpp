//n is the number of elements in the array
//find a triplet that is equal to the target
#include <bits/stdc++.h>
using namespace std;

void find_triplet(int *arr, int size, int target)
{

    for (int i = 0; i < size - 2; i++)
    {
        int first = arr[i];

        int lower = i + 1;
        int upper = size - 1;

        while (lower < upper)
        {
            if (first + arr[lower] + arr[upper] == target)
            {
                cout << first << ", " << arr[lower] << " and " << arr[upper];
                cout << endl;
                lower++;
                upper--;
            }

            else if (first + arr[lower] + arr[upper] > target)
            {
                upper--;
            }

            else
            {
                lower++;
            }
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

    int target;
    cin >> target;

    sort(arr, arr + n);

    find_triplet(arr, n, target);
}