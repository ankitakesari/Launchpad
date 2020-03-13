#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int cost[4] = {3, 5, 2, 5};

    int next[4] = {2, 1, 2, 5};

    int min = cost[0];

    int total = min * next[0];

    for (int i = 1; i < n; i++)
    {
        if (cost[i] < min)
        {
            min = cost[i];
        }

        total += min * next[i];
    }

    cout << total;
}