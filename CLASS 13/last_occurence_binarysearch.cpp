// In an array of integer ,find the last occurence of a number(key) if it is present in the array

#include <iostream>
using namespace std;

int last_occurence(int *arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int arr[13] = {1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7};

    int key = 6;

    int result = last_occurence(arr, 13, 6);

    cout << result;
}