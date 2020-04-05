#include <iostream>
using namespace std;

void bubblesort(int arr[10], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        bool sorted = true;
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        if (sorted == true)
            break;

        for (int i = 0; i < 6; i++)
            cout << arr[i] << " , ";

        cout << endl;
    }
}

int main()
{
    int arr[6] = {5, 9, 1, 3, 2, 6};

    bubblesort(arr, 6);

    return 0;
}