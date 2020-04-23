#include <bits/stdc++.h>
using namespace std;

void min_cost_ropes(vector<int> ropes, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    int total_cost = 0;
    while (pq.size() > 1)
    {
        int first_rope = pq.top();
        pq.pop();
        int second_rope = pq.top();
        pq.pop();
        int curr_cost = first_rope + second_rope;
        total_cost += curr_cost;

        pq.push(curr_cost);
        cout << first_rope << "," << second_rope << "," << curr_cost;
        cout << endl;
    }

    cout << total_cost;
}

int main()
{
    vector<int> ropes;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ropes.push_back(x);
    }

    min_cost_ropes(ropes, n);
}