// merge two sorted arrays into one sorted array

#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{

    //cout << "merge" << endl;
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[100] = {0};
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

    i = 0;
    //copying back to the original array
    for (int x = start; x <= end; x++)
    {
        arr[x] = temp[i];
        i++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = start + ((end - start) / 2);

    //cout << "check 1" << endl;
    //if had used upper mid then stuck in infinite loop (printing check 1)
    mergeSort(arr, start, mid);

    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int arr[100] = {1, 6, 5, 4, 10, 2, 18, 7};
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}