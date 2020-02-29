// find the kth smallest element in an unsorted array ,without sorting the whole array

#include <iostream>
using namespace std;

int placepivot(int *arr, int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

int k_smallest(int *arr, int start, int end, int k)
{
    if (start >= end)
    {
        return -1;
    }

    if (k > 0 && k <= end - start + 1)
    {
        int idx = placepivot(arr, start, end);
        //cout << "idx:" << idx << endl;
        //cout << "k: " << k << endl;
        cout << endl;

        if (idx - start == k - 1)
        {
            return arr[idx];
        }

        else if (idx > k - 1)
        {
            //lies on left side
            return k_smallest(arr, start, idx - 1, k);
        }

        else
        {
            return k_smallest(arr, idx + 1, end, k - 1 - idx);
        }
    }

    return -1;
}

int main()
{
    int arr[6] = {3, 2, 1, 4, 9, 5};

    int k = 3;

    int result = k_smallest(arr, 0, 5, k);

    cout << result;

    return 0;
}
