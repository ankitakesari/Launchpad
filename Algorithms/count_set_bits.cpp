//count the no of set-bits in for all numbers between a and b (both inclusive)

#include <iostream>
using namespace std;
int memo[1000] = {0};
vector<int> v;

int count_set_bits(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (memo[n] != 0)
    {
        return memo[n];
    }

    int count = 0;

    if (n % 2 == 0)
    {
        count = count_set_bits(n / 2);
    }

    else
    {
        count = 1 + count_set_bits(n / 2);
    }

    memo[n] = count;
    return count;
}

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase > 0)
    {
        int a;
        int b;
        cin >> a;
        cin >> b;

        int total_bits = 0;

        for (int i = a; i <= b; i++)
        {
            total_bits += count_set_bits(i);
        }

        v.push_back(total_bits);

        testcase--;
    }

    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
}