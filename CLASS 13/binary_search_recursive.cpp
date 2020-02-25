#include <iostream>
using namespace std;

bool func(int *arr, int st, int ed, int element)
{
    if (st > ed)
    {
        return false;
    }

    bool result = false;
    int mid = (st + ed) / 2;
    if (arr[mid] == element)
    {
        result = true;
    }

    else if (element < arr[mid])
    {
        //ed = mid - 1;
        result = func(arr, st, mid - 1, element);
    }

    else
    {
        //st = mid + 1;
        result = func(arr, mid + 1, ed, element);
    }

    return result;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    bool result = func(arr, 0, 5, 5);

    if (result)
        cout << "present";
    else
        cout << " not present";

    return 0;
}