#include <iostream>
using namespace std;

bool func(int *arr, int st, int ed, int element)
{

    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if (arr[mid] == element)
        {
            return true;
        }

        else if (element < arr[mid])
        {
            ed = mid - 1;
        }

        else
        {
            st = mid + 1;
        }
    }

    return false;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    bool result = func(arr, 0, 5, 11);

    if (result)
        cout << "present";
    else
        cout << " not present";

    return 0;
}