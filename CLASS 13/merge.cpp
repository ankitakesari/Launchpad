// merge two sorted arrays into one sorted array

#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{

    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end + 1];
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    arr = temp;
    for (int x = 0; x <= end; x++)
    {
        cout << arr[x] << " ";
    }
}

int main()
{
    int arr[11] = {1, 3, 5, 7, 8, 2, 5, 9, 11, 12, 13};

    int start = 0;
    int end = 10;
    int mid = 4;

    merge(arr, start, mid, end);

    return 0;
}