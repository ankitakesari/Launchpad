//quick sort

#include <iostream>
using namespace std;

int placePivot(int *arr, int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int idx = placePivot(arr, start, end);

    quickSort(arr, start, idx - 1);
    quickSort(arr, idx + 1, end);
}

int main()
{
    int arr[6] = {16, 8, 9, 10, 2, 3};

    quickSort(arr, 0, 5);

    for (int x = 0; x < 6; x++)
    {
        cout << arr[x] << "  ";
    }
    return 0;
}