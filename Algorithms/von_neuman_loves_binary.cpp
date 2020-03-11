//Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;

    while (testcase > 0)
    {
        int n;
        cin >> n;

        int count = 0;
        int result = 0;

        while (n != 0)
        {
            int x = n % 10;
            int y = x * pow(2, count);
            count++;
            result += y;
            n = n / 10;
            // cout << result << endl;
            // cout << "n:" << n << endl;
        }
        cout << result << endl;
        testcase--;
    }
}