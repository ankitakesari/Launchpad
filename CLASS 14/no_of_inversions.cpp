// find the number of inversions in a given array
// i<j and arr[i]>arr[j]

#include <iostream>
using namespace std;

int merge(int *arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    int count = 0;

    int temp[100] = {0};

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
            count += mid - i + 1;
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

    i = 0;

    for (int x = start; x <= end; x++)
    {
        arr[x] = temp[i];
        i++;
    }

    return count;
}

int mergeSort(int *arr, int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    int count = 0;

    int mid = start + (end - start) / 2;

    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);

    count += merge(arr, start, mid, end);

    return count;
}

int main()
{
    int arr[7] = {15, 8, 9, 10, 2, 3, 1};

    int inversions = mergeSort(arr, 0, 6);

    cout << "No of Inversions: " << inversions;

    return 0;
}