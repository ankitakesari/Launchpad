// check whether a number is present in a Rotated Sorted Array

#include <iostream>
using namespace std;

int searchInRotated(int *arr, int start, int end, int key)
{

    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    //check whether right part of array is sorted
    if (arr[mid] <= arr[end])
    {
        // right part of array is sorted but does the number exist between them
        if (arr[mid] <= key && key <= arr[end])
        {
            searchInRotated(arr, mid + 1, end, key); //right search
        }

        else
        {
            searchInRotated(arr, start, mid - 1, key); //left search
        }
    }

    else
    {
        //left part of array is sorted

        if (arr[start] <= key && key <= arr[mid])
        {
            searchInRotated(arr, start, mid - 1, key); //left search
        }

        else
        {
            searchInRotated(arr, mid + 1, end, key); //right search
        }
    }
}

int main()
{
    int arr[8] = {5, 6, 7, 8, 1, 2, 3, 4};

    int key = 3;

    int index = searchInRotated(arr, 0, 7, key);

    if (index < 0)
    {
        cout << "key not present";
    }

    else
    {
        cout << "key: " << key << " is present at index " << index;
    }

    return 0;
}