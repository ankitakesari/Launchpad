// Pivot is the position from where array is rotated.

#include <iostream>
using namespace std;

int pivotInRotatedArray(int *arr, int start, int end)
{
    if (start >= end)
    {
        return start;
    }

    int mid = start + (end - start) / 2;

    if (start < mid && arr[mid - 1] > arr[mid])
    {
        return mid;
    }

    if (end > mid && arr[mid + 1] < arr[mid])
    {
        return mid + 1;
    }

    if (arr[mid] > arr[end])
    { //right unsorted
        pivotInRotatedArray(arr, mid + 1, end);
    }

    else
    {
        //left unsorted
        pivotInRotatedArray(arr, start, mid - 1);
    }
}

int main()
{
    int arr[8] = {6, 7, 8, 9, 1, 2, 3, 4};

    int index = pivotInRotatedArray(arr, 0, 7);

    cout << "Array is pivoted at index: " << index;

    return 0;
}