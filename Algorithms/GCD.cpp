#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    int n1;
    cin >> n1;

    int n2;
    cin >> n2;

    int result = gcd(n1, n2);
    cout << result;
}
