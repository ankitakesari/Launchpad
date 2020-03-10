#include <iostream>
#include <vector>
using namespace std;

string ref = "0ACB";

vector<int> V[4];

void func(int disc, int source, int helper, int dest)
{
    if (disc == 0)
    {
        return;
    }
    func(disc - 1, source, dest, helper);
    int x = V[source].back();
    V[source].pop_back();
    V[dest].push_back(x);
    cout << "Moving ring " << x << " from " << ref[source] << " to " << ref[dest] << endl;
    func(disc - 1, helper, source, dest);
}

int main()
{
    int n;
    cin >> n;

    //vector<int> V[4];

    for (int i = n; i > 0; i--)
    {
        V[1].push_back(i);
    }

    for (int a = 0; a < 4; a++)
    {
        cout << V[1][a] << endl;
    }
    func(n, 1, 2, 3);

    return 0;
}